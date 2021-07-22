// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/rel/13.0sp1/ip/merlin/altera_merlin_router/altera_merlin_router.sv.terp#1 $
// $Revision: #1 $
// $Date: 2013/03/07 $
// $Author: swbranch $

// -------------------------------------------------------
// Merlin Router
//
// Asserts the appropriate one-hot encoded channel based on 
// either (a) the address or (b) the dest id. The DECODER_TYPE
// parameter controls this behaviour. 0 means address decoder,
// 1 means dest id decoder.
//
// In the case of (a), it also sets the destination id.
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module Core8_addr_router_006_default_decode
  #(
     parameter DEFAULT_CHANNEL = 0,
               DEFAULT_WR_CHANNEL = -1,
               DEFAULT_RD_CHANNEL = -1,
               DEFAULT_DESTID = 255 
   )
  (output [92 - 84 : 0] default_destination_id,
   output [284-1 : 0] default_wr_channel,
   output [284-1 : 0] default_rd_channel,
   output [284-1 : 0] default_src_channel
  );

  assign default_destination_id = 
    DEFAULT_DESTID[92 - 84 : 0];

  generate begin : default_decode
    if (DEFAULT_CHANNEL == -1) begin
      assign default_src_channel = '0;
    end
    else begin
      assign default_src_channel = 284'b1 << DEFAULT_CHANNEL;
    end
  end
  endgenerate

  generate begin : default_decode_rw
    if (DEFAULT_RD_CHANNEL == -1) begin
      assign default_wr_channel = '0;
      assign default_rd_channel = '0;
    end
    else begin
      assign default_wr_channel = 284'b1 << DEFAULT_WR_CHANNEL;
      assign default_rd_channel = 284'b1 << DEFAULT_RD_CHANNEL;
    end
  end
  endgenerate

endmodule


module Core8_addr_router_006
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // Command Sink (Input)
    // -------------------
    input                       sink_valid,
    input  [103-1 : 0]    sink_data,
    input                       sink_startofpacket,
    input                       sink_endofpacket,
    output                      sink_ready,

    // -------------------
    // Command Source (Output)
    // -------------------
    output                          src_valid,
    output reg [103-1    : 0] src_data,
    output reg [284-1 : 0] src_channel,
    output                          src_startofpacket,
    output                          src_endofpacket,
    input                           src_ready
);

    // -------------------------------------------------------
    // Local parameters and variables
    // -------------------------------------------------------
    localparam PKT_ADDR_H = 53;
    localparam PKT_ADDR_L = 36;
    localparam PKT_DEST_ID_H = 92;
    localparam PKT_DEST_ID_L = 84;
    localparam PKT_PROTECTION_H = 96;
    localparam PKT_PROTECTION_L = 94;
    localparam ST_DATA_W = 103;
    localparam ST_CHANNEL_W = 284;
    localparam DECODER_TYPE = 0;

    localparam PKT_TRANS_WRITE = 56;
    localparam PKT_TRANS_READ  = 57;

    localparam PKT_ADDR_W = PKT_ADDR_H-PKT_ADDR_L + 1;
    localparam PKT_DEST_ID_W = PKT_DEST_ID_H-PKT_DEST_ID_L + 1;



    // -------------------------------------------------------
    // Figure out the number of bits to mask off for each slave span
    // during address decoding
    // -------------------------------------------------------
    localparam PAD0 = log2ceil(64'h1000 - 64'h800); 
    localparam PAD1 = log2ceil(64'h1080 - 64'h1000); 
    localparam PAD2 = log2ceil(64'h10a0 - 64'h1080); 
    localparam PAD3 = log2ceil(64'h10c0 - 64'h10a0); 
    localparam PAD4 = log2ceil(64'h10e0 - 64'h10c0); 
    localparam PAD5 = log2ceil(64'h1100 - 64'h10e0); 
    localparam PAD6 = log2ceil(64'h1120 - 64'h1100); 
    localparam PAD7 = log2ceil(64'h1140 - 64'h1120); 
    localparam PAD8 = log2ceil(64'h1160 - 64'h1140); 
    localparam PAD9 = log2ceil(64'h1180 - 64'h1160); 
    localparam PAD10 = log2ceil(64'h11a0 - 64'h1180); 
    localparam PAD11 = log2ceil(64'h11c0 - 64'h11a0); 
    localparam PAD12 = log2ceil(64'h11e0 - 64'h11c0); 
    localparam PAD13 = log2ceil(64'h1200 - 64'h11e0); 
    localparam PAD14 = log2ceil(64'h1220 - 64'h1200); 
    localparam PAD15 = log2ceil(64'h1240 - 64'h1220); 
    localparam PAD16 = log2ceil(64'h1260 - 64'h1240); 
    localparam PAD17 = log2ceil(64'h1280 - 64'h1260); 
    localparam PAD18 = log2ceil(64'h12a0 - 64'h1280); 
    localparam PAD19 = log2ceil(64'h12c0 - 64'h12a0); 
    localparam PAD20 = log2ceil(64'h12d0 - 64'h12c0); 
    localparam PAD21 = log2ceil(64'h12e0 - 64'h12d0); 
    localparam PAD22 = log2ceil(64'h12f0 - 64'h12e0); 
    localparam PAD23 = log2ceil(64'h12f8 - 64'h12f0); 
    localparam PAD24 = log2ceil(64'h1300 - 64'h12f8); 
    localparam PAD25 = log2ceil(64'h1308 - 64'h1300); 
    localparam PAD26 = log2ceil(64'h1310 - 64'h1308); 
    localparam PAD27 = log2ceil(64'h1318 - 64'h1310); 
    localparam PAD28 = log2ceil(64'h1320 - 64'h1318); 
    localparam PAD29 = log2ceil(64'h1328 - 64'h1320); 
    localparam PAD30 = log2ceil(64'h132c - 64'h1328); 
    localparam PAD31 = log2ceil(64'h1330 - 64'h132c); 
    localparam PAD32 = log2ceil(64'h1334 - 64'h1330); 
    localparam PAD33 = log2ceil(64'h1338 - 64'h1334); 
    localparam PAD34 = log2ceil(64'h133c - 64'h1338); 
    localparam PAD35 = log2ceil(64'h1340 - 64'h133c); 
    localparam PAD36 = log2ceil(64'h1344 - 64'h1340); 
    localparam PAD37 = log2ceil(64'h1348 - 64'h1344); 
    localparam PAD38 = log2ceil(64'h134c - 64'h1348); 
    localparam PAD39 = log2ceil(64'h1350 - 64'h134c); 
    localparam PAD40 = log2ceil(64'h1354 - 64'h1350); 
    localparam PAD41 = log2ceil(64'h1358 - 64'h1354); 
    localparam PAD42 = log2ceil(64'h135c - 64'h1358); 
    localparam PAD43 = log2ceil(64'h1360 - 64'h135c); 
    localparam PAD44 = log2ceil(64'h18000 - 64'h10000); 
    localparam PAD45 = log2ceil(64'h30000 - 64'h20000); 
    // -------------------------------------------------------
    // Work out which address bits are significant based on the
    // address range of the slaves. If the required width is too
    // large or too small, we use the address field width instead.
    // -------------------------------------------------------
    localparam ADDR_RANGE = 64'h30000;
    localparam RANGE_ADDR_WIDTH = log2ceil(ADDR_RANGE);
    localparam OPTIMIZED_ADDR_H = (RANGE_ADDR_WIDTH > PKT_ADDR_W) ||
                                  (RANGE_ADDR_WIDTH == 0) ?
                                        PKT_ADDR_H :
                                        PKT_ADDR_L + RANGE_ADDR_WIDTH - 1;

    localparam RG = RANGE_ADDR_WIDTH-1;

      wire [PKT_ADDR_W-1 : 0] address = sink_data[OPTIMIZED_ADDR_H : PKT_ADDR_L];

    // -------------------------------------------------------
    // Pass almost everything through, untouched
    // -------------------------------------------------------
    assign sink_ready        = src_ready;
    assign src_valid         = sink_valid;
    assign src_startofpacket = sink_startofpacket;
    assign src_endofpacket   = sink_endofpacket;

    wire [PKT_DEST_ID_W-1:0] default_destid;
    wire [284-1 : 0] default_src_channel;





    Core8_addr_router_006_default_decode the_default_decode(
      .default_destination_id (default_destid),
      .default_wr_channel   (),
      .default_rd_channel   (),
      .default_src_channel  (default_src_channel)
    );

    always @* begin
        src_data    = sink_data;
        src_channel = default_src_channel;
        src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = default_destid;

        // --------------------------------------------------
        // Address Decoder
        // Sets the channel and destination ID based on the address
        // --------------------------------------------------

    // ( 0x800 .. 0x1000 )
    if ( {address[RG:PAD0],{PAD0{1'b0}}} == 18'h800   ) begin
            src_channel = 284'b0000000000000000000000000000000001000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 3;
    end

    // ( 0x1000 .. 0x1080 )
    if ( {address[RG:PAD1],{PAD1{1'b0}}} == 18'h1000   ) begin
            src_channel = 284'b0100000000000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 259;
    end

    // ( 0x1080 .. 0x10a0 )
    if ( {address[RG:PAD2],{PAD2{1'b0}}} == 18'h1080   ) begin
            src_channel = 284'b0000000000000000000000000000000000100000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 283;
    end

    // ( 0x10a0 .. 0x10c0 )
    if ( {address[RG:PAD3],{PAD3{1'b0}}} == 18'h10a0   ) begin
            src_channel = 284'b1000000000000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 273;
    end

    // ( 0x10c0 .. 0x10e0 )
    if ( {address[RG:PAD4],{PAD4{1'b0}}} == 18'h10c0   ) begin
            src_channel = 284'b0010000000000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 218;
    end

    // ( 0x10e0 .. 0x1100 )
    if ( {address[RG:PAD5],{PAD5{1'b0}}} == 18'h10e0   ) begin
            src_channel = 284'b0000100000000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 190;
    end

    // ( 0x1100 .. 0x1120 )
    if ( {address[RG:PAD6],{PAD6{1'b0}}} == 18'h1100   ) begin
            src_channel = 284'b0000001000000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 162;
    end

    // ( 0x1120 .. 0x1140 )
    if ( {address[RG:PAD7],{PAD7{1'b0}}} == 18'h1120   ) begin
            src_channel = 284'b0000000010000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 134;
    end

    // ( 0x1140 .. 0x1160 )
    if ( {address[RG:PAD8],{PAD8{1'b0}}} == 18'h1140   ) begin
            src_channel = 284'b0000000000100000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 116;
    end

    // ( 0x1160 .. 0x1180 )
    if ( {address[RG:PAD9],{PAD9{1'b0}}} == 18'h1160   ) begin
            src_channel = 284'b0000000000001000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 112;
    end

    // ( 0x1180 .. 0x11a0 )
    if ( {address[RG:PAD10],{PAD10{1'b0}}} == 18'h1180   ) begin
            src_channel = 284'b0000000000000010000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 108;
    end

    // ( 0x11a0 .. 0x11c0 )
    if ( {address[RG:PAD11],{PAD11{1'b0}}} == 18'h11a0   ) begin
            src_channel = 284'b0000000000000000100000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 104;
    end

    // ( 0x11c0 .. 0x11e0 )
    if ( {address[RG:PAD12],{PAD12{1'b0}}} == 18'h11c0   ) begin
            src_channel = 284'b0000000000000000000000000000000000010000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 282;
    end

    // ( 0x11e0 .. 0x1200 )
    if ( {address[RG:PAD13],{PAD13{1'b0}}} == 18'h11e0   ) begin
            src_channel = 284'b0000000000000000001000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 100;
    end

    // ( 0x1200 .. 0x1220 )
    if ( {address[RG:PAD14],{PAD14{1'b0}}} == 18'h1200   ) begin
            src_channel = 284'b0000000000000000000010000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 96;
    end

    // ( 0x1220 .. 0x1240 )
    if ( {address[RG:PAD15],{PAD15{1'b0}}} == 18'h1220   ) begin
            src_channel = 284'b0000000000000000000000100000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 92;
    end

    // ( 0x1240 .. 0x1260 )
    if ( {address[RG:PAD16],{PAD16{1'b0}}} == 18'h1240   ) begin
            src_channel = 284'b0000000000000000000000001000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 74;
    end

    // ( 0x1260 .. 0x1280 )
    if ( {address[RG:PAD17],{PAD17{1'b0}}} == 18'h1260   ) begin
            src_channel = 284'b0000000000000000000000000010000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 46;
    end

    // ( 0x1280 .. 0x12a0 )
    if ( {address[RG:PAD18],{PAD18{1'b0}}} == 18'h1280   ) begin
            src_channel = 284'b0000000000000000000000000000100000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 18;
    end

    // ( 0x12a0 .. 0x12c0 )
    if ( {address[RG:PAD19],{PAD19{1'b0}}} == 18'h12a0   ) begin
            src_channel = 284'b0000000000000000000000000000000100000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 272;
    end

    // ( 0x12c0 .. 0x12d0 )
    if ( {address[RG:PAD20],{PAD20{1'b0}}} == 18'h12c0   ) begin
            src_channel = 284'b0000000000000000000000000000000000001000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 265;
    end

    // ( 0x12d0 .. 0x12e0 )
    if ( {address[RG:PAD21],{PAD21{1'b0}}} == 18'h12d0   ) begin
            src_channel = 284'b0000000000000000000000000000000000000100000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 232;
    end

    // ( 0x12e0 .. 0x12f0 )
    if ( {address[RG:PAD22],{PAD22{1'b0}}} == 18'h12e0   ) begin
            src_channel = 284'b0000000000000000000000000000000000000010000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 264;
    end

    // ( 0x12f0 .. 0x12f8 )
    if ( {address[RG:PAD23],{PAD23{1'b0}}} == 18'h12f0   ) begin
            src_channel = 284'b0000000000000000000000000000000000000001000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 246;
    end

    // ( 0x12f8 .. 0x1300 )
    if ( {address[RG:PAD24],{PAD24{1'b0}}} == 18'h12f8   ) begin
            src_channel = 284'b0000000000000000000000000000000000000000100000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 245;
    end

    // ( 0x1300 .. 0x1308 )
    if ( {address[RG:PAD25],{PAD25{1'b0}}} == 18'h1300   ) begin
            src_channel = 284'b0000000000000000000000000000000000000000010000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 244;
    end

    // ( 0x1308 .. 0x1310 )
    if ( {address[RG:PAD26],{PAD26{1'b0}}} == 18'h1308   ) begin
            src_channel = 284'b0000000000000000000000000000000000000000001000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 243;
    end

    // ( 0x1310 .. 0x1318 )
    if ( {address[RG:PAD27],{PAD27{1'b0}}} == 18'h1310   ) begin
            src_channel = 284'b0000000000000000000000000000000000000000000100;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 242;
    end

    // ( 0x1318 .. 0x1320 )
    if ( {address[RG:PAD28],{PAD28{1'b0}}} == 18'h1318   ) begin
            src_channel = 284'b0000000000000000000000000000000000000000000010;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 241;
    end

    // ( 0x1320 .. 0x1328 )
    if ( {address[RG:PAD29],{PAD29{1'b0}}} == 18'h1320   ) begin
            src_channel = 284'b0000000000000000000000000000001000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 236;
    end

    // ( 0x1328 .. 0x132c )
    if ( {address[RG:PAD30],{PAD30{1'b0}}} == 18'h1328   ) begin
            src_channel = 284'b0001000000000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 219;
    end

    // ( 0x132c .. 0x1330 )
    if ( {address[RG:PAD31],{PAD31{1'b0}}} == 18'h132c   ) begin
            src_channel = 284'b0000010000000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 191;
    end

    // ( 0x1330 .. 0x1334 )
    if ( {address[RG:PAD32],{PAD32{1'b0}}} == 18'h1330   ) begin
            src_channel = 284'b0000000100000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 163;
    end

    // ( 0x1334 .. 0x1338 )
    if ( {address[RG:PAD33],{PAD33{1'b0}}} == 18'h1334   ) begin
            src_channel = 284'b0000000001000000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 135;
    end

    // ( 0x1338 .. 0x133c )
    if ( {address[RG:PAD34],{PAD34{1'b0}}} == 18'h1338   ) begin
            src_channel = 284'b0000000000010000000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 117;
    end

    // ( 0x133c .. 0x1340 )
    if ( {address[RG:PAD35],{PAD35{1'b0}}} == 18'h133c   ) begin
            src_channel = 284'b0000000000000100000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 113;
    end

    // ( 0x1340 .. 0x1344 )
    if ( {address[RG:PAD36],{PAD36{1'b0}}} == 18'h1340   ) begin
            src_channel = 284'b0000000000000001000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 109;
    end

    // ( 0x1344 .. 0x1348 )
    if ( {address[RG:PAD37],{PAD37{1'b0}}} == 18'h1344   ) begin
            src_channel = 284'b0000000000000000010000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 105;
    end

    // ( 0x1348 .. 0x134c )
    if ( {address[RG:PAD38],{PAD38{1'b0}}} == 18'h1348   ) begin
            src_channel = 284'b0000000000000000000100000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 101;
    end

    // ( 0x134c .. 0x1350 )
    if ( {address[RG:PAD39],{PAD39{1'b0}}} == 18'h134c   ) begin
            src_channel = 284'b0000000000000000000001000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 97;
    end

    // ( 0x1350 .. 0x1354 )
    if ( {address[RG:PAD40],{PAD40{1'b0}}} == 18'h1350   ) begin
            src_channel = 284'b0000000000000000000000010000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 93;
    end

    // ( 0x1354 .. 0x1358 )
    if ( {address[RG:PAD41],{PAD41{1'b0}}} == 18'h1354   ) begin
            src_channel = 284'b0000000000000000000000000100000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 75;
    end

    // ( 0x1358 .. 0x135c )
    if ( {address[RG:PAD42],{PAD42{1'b0}}} == 18'h1358   ) begin
            src_channel = 284'b0000000000000000000000000001000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 47;
    end

    // ( 0x135c .. 0x1360 )
    if ( {address[RG:PAD43],{PAD43{1'b0}}} == 18'h135c   ) begin
            src_channel = 284'b0000000000000000000000000000010000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 19;
    end

    // ( 0x10000 .. 0x18000 )
    if ( {address[RG:PAD44],{PAD44{1'b0}}} == 18'h10000   ) begin
            src_channel = 284'b0000000000000000000000000000000010000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 250;
    end

    // ( 0x20000 .. 0x30000 )
    if ( {address[RG:PAD45],{PAD45{1'b0}}} == 18'h20000   ) begin
            src_channel = 284'b0000000000000000000000000000000000000000000001;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 255;
    end

end


    // --------------------------------------------------
    // Ceil(log2()) function
    // --------------------------------------------------
    function integer log2ceil;
        input reg[65:0] val;
        reg [65:0] i;

        begin
            i = 1;
            log2ceil = 0;

            while (i < val) begin
                log2ceil = log2ceil + 1;
                i = i << 1;
            end
        end
    endfunction

endmodule


