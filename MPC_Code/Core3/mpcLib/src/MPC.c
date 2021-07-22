/* DESCRIPTION:
 * This file contains all implementations of functions for the MPC library. 
*/

#include "INFO.h"
#include "stdio.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_mutex.h"
#include "altera_avalon_mutex_regs.h"
#include "altera_avalon_fifo_util.h"
#include "sys/alt_alarm.h"
#include "nios2.h"
#include "altera_avalon_fifo_regs.h"
#include "io.h"
#include <sys/alt_alarm.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"
#include "sys/alt_timestamp.h"

alt_u8 totalCPUs = 3; // Make more general by determining fifoBaseAddresses-size

// A list of the timer's base addresses, used in the MPC functions relating to timers.
alt_u32 TIMER_BASES [][8] = {
	{
		TIMER_0_0_BASE,
		TIMER_1_0_BASE,
		TIMER_2_0_BASE,
		0,
		0,
		0,
		0,
		0
	},

	{
		TIMER_0_1_BASE,
		TIMER_1_1_BASE,
		TIMER_2_1_BASE,
		0,
		0,
		0,
		0,
		0
	}
};

// A list of all the FIFO variables, used in the MPC functions relating to the 
alt_u32 fifoInCsrBaseAddresses [][8] = {
	{ 	
		0, 
		FIFO_0_TO_1_IN_CSR_BASE, 
		FIFO_0_TO_2_IN_CSR_BASE, 
		0,
		0,
		0,
		0,
		0    
	},

	{ 	
		FIFO_1_TO_0_IN_CSR_BASE, 
		0, 
		FIFO_1_TO_2_IN_CSR_BASE, 
		0,
		0,
		0,
		0,
		0      
	},

	{ 	
		FIFO_2_TO_0_IN_CSR_BASE, 
		FIFO_2_TO_1_IN_CSR_BASE, 
		0, 
		0,
		0,
		0,
		0,
		0       
	}
};

alt_u32 fifoOutCsrBaseAddresses [][8] = {
	{ 
		0, 
		FIFO_0_TO_1_OUT_CSR_BASE, 
		FIFO_0_TO_2_OUT_CSR_BASE, 
		0,
		0,
		0,
		0,
		0      
	},

	{ 
		FIFO_1_TO_0_OUT_CSR_BASE, 
		0, 
		FIFO_1_TO_2_OUT_CSR_BASE, 
		0,
		0,
		0,
 		0,
		0     
	},

	{ 
		FIFO_2_TO_0_OUT_CSR_BASE, 
		FIFO_2_TO_1_OUT_CSR_BASE, 
		0, 
		0,
		0,
		0,
		0,
		0     
	}
};

alt_u32 fifoInBaseAddresses [][8] = {
	{ 
		0, 
		FIFO_0_TO_1_IN_BASE, 
		FIFO_0_TO_2_IN_BASE, 
		0,
		0,
		0,
		0,
		0     
	},

	{ 
		FIFO_1_TO_0_IN_BASE, 
		0, 
		FIFO_1_TO_2_IN_BASE, 
		0,
		0,
		0,
		0,
		0      
	},

	{ 
		FIFO_2_TO_0_IN_BASE, 
		FIFO_2_TO_1_IN_BASE, 
		0, 
		0,
		0,
		0,
		0,
		0     
	}
};

alt_u32 fifoOutBaseAddresses [][8] = {
	{ 
		0, 
		FIFO_0_TO_1_OUT_BASE, 
		FIFO_0_TO_2_OUT_BASE, 
		0,
		0,
		0,
		0,
		0     
	},

	{ 
		FIFO_1_TO_0_OUT_BASE, 
		0, 
		FIFO_1_TO_2_OUT_BASE, 
		0,
		0,
		0,
		0,
		0     
	},

	{ 
		FIFO_2_TO_0_OUT_BASE, 
		FIFO_2_TO_1_OUT_BASE, 
		0, 
		0,
		0,
		0,
		0,
		0     
	}
};

alt_u32 fifoInDepths [][7] = {
	{ 
		0, 
		FIFO_0_TO_1_IN_FIFO_DEPTH, 
		FIFO_0_TO_2_IN_FIFO_DEPTH, 
		0,
		0,
		0,
		0,
		0     
	},

	{ 
		FIFO_1_TO_0_IN_FIFO_DEPTH, 
		0, 
		FIFO_1_TO_2_IN_FIFO_DEPTH, 
		0,
		0,
		0,
		0,
		0    
	},

	{ 
		FIFO_2_TO_0_IN_FIFO_DEPTH, 
		FIFO_2_TO_1_IN_FIFO_DEPTH, 
		0, 
		0,
		0,
		0,
		0,
		0    
	}
};

alt_u32 fifoOutDepths [][8] = {
	{ 
		0, 
		FIFO_0_TO_1_OUT_FIFO_DEPTH, 
		FIFO_0_TO_2_OUT_FIFO_DEPTH, 
		0,
		0,
		0,
		0,
		0      
	},

	{ 
		FIFO_1_TO_0_OUT_FIFO_DEPTH, 
		0, 
		FIFO_1_TO_2_OUT_FIFO_DEPTH, 
		0,
		0,
		0,
		0,
		0      
	},

	{ 
		FIFO_2_TO_0_OUT_FIFO_DEPTH, 
		FIFO_2_TO_1_OUT_FIFO_DEPTH, 
		0, 
		0,
		0,
		0,
		0,
		0      
	}
};

/* Initializes all connected fifos for the processor that calls it */
void MPC_initialize_fifos(alt_u8 CPU, alt_u8 ALMOST_FULL, alt_u8 ALMOST_EMPTY)
{
	int OUT;
	int IN;
	int i;
	for(i=0;i<totalCPUs;i++){
		if(i != CPU){
			IN = altera_avalon_fifo_init(fifoInCsrBaseAddresses[CPU][i],
				0, // disable interrupts,
				ALMOST_EMPTY, // almost empty level
				ALMOST_FULL); // almost full level

			if(IN != 0){
				printf("INIT ERROR: From CPU %u to CPU %u. ERROR: %i\n",CPU,i,IN);
			}

			OUT = altera_avalon_fifo_init(fifoOutCsrBaseAddresses[i][CPU],
				  0, // disable interrupts,
				  ALMOST_EMPTY, // almost empty level
				  ALMOST_FULL); // almost full level

			if(OUT != 0){
				printf("INIT ERROR: From CPU %u to CPU %u. ERROR: %i\n",i,CPU,OUT);
			}
	
		}
	}
}

/* Blocking function that sends data from one CPU to another through the designated FIFO */
void MPC_send_to_CPU(alt_u8 CPU_SENDER, alt_u8 CPU_RECEIVER , int DATA)
{
	while(altera_avalon_fifo_read_status(fifoInCsrBaseAddresses[CPU_SENDER][CPU_RECEIVER],0x1) != 0);

		altera_avalon_fifo_write_fifo(fifoInBaseAddresses[CPU_SENDER][CPU_RECEIVER], fifoInCsrBaseAddresses[CPU_SENDER][CPU_RECEIVER], DATA);
}

/* Blocking function that receives data from a CPU through the designated FIFO */
int MPC_receive_from_CPU(alt_u8 CPU_SENDER, alt_u8 CPU_RECEIVER)
{
	while(altera_avalon_fifo_read_status(fifoOutCsrBaseAddresses[CPU_SENDER][CPU_RECEIVER],0x2) != 0);
		
return altera_avalon_fifo_read_fifo(fifoOutBaseAddresses[CPU_SENDER][CPU_RECEIVER],fifoOutCsrBaseAddresses[CPU_SENDER][CPU_RECEIVER]);
}

/* Returns an integer that gives the fill value of the FIFO in question */
int MPC_FIFO_level(alt_u8 CPU_SENDER, alt_u8 CPU_RECEIVER)
{
	if( CPU_RECEIVER < totalCPUs ) //Do not have to check if CPU_RECEIVER is negative since alt_u8 [0,255]
		return altera_avalon_fifo_read_level(fifoInCsrBaseAddresses[CPU_SENDER][CPU_RECEIVER]);
	else
		printf("ERROR: ILLEGAL RECEIVER CPU %i\n", CPU_RECEIVER);
	return -1;
}

/* Returns the contents of the status register of the FIFO in question. See Altera documentation for interpretation of values. */ 
int MPC_FIFO_status(alt_u8 CPU_SENDER, alt_u8 CPU_RECEIVER, alt_u8 mask)
{
	if( CPU_RECEIVER < totalCPUs ) //Do not have to check if CPU_RECEIVER is negative since alt_u8 [0,255]
		return altera_avalon_fifo_read_status(fifoInCsrBaseAddresses[CPU_SENDER][CPU_RECEIVER], mask);
	else
		printf("ERROR: ILLEGAL RECEIVER CPU %i\n", CPU_RECEIVER);
	return -1;
}

//Commands for writing to red leds

/* Writes a single red LED high, all other red LEDs will be set to low*/
void MPC_write_single_red_LED(alt_u8 LEDNUMBER){

	alt_u32 MASK = 1;
	IOWR_ALTERA_AVALON_PIO_DATA(RED_LEDS_BASE,MASK<<LEDNUMBER);

}

/* Writes a complete mask to the red LEDs, ligting the LEDs up in the binary pattern provided */
void MPC_write_mask_red_LED(alt_u32 MASK){

	IOWR_ALTERA_AVALON_PIO_DATA(RED_LEDS_BASE,MASK);

}

/* Shuts all red LEDs off */
void MPC_reset_red_leds(){
	
	IOWR_ALTERA_AVALON_PIO_DATA(RED_LEDS_BASE,0);

}

//Commands for writing to green leds

/* Writes a single green LED high, all other green LEDs will be set to low*/
void MPC_write_single_green_LED(alt_u8 LEDNUMBER){

	alt_u32 MASK = 1;
	IOWR_ALTERA_AVALON_PIO_DATA(GREEN_LEDS_BASE,MASK<<LEDNUMBER);

}

/* Writes a complete mask to the green LEDs, ligting the LEDs up in the binary pattern provided */
void MPC_write_mask_green_LED(alt_u8 MASK){

	IOWR_ALTERA_AVALON_PIO_DATA(GREEN_LEDS_BASE,MASK);

}

/* Shuts all green LEDs off */
void MPC_reset_green_leds(){
	
	IOWR_ALTERA_AVALON_PIO_DATA(GREEN_LEDS_BASE,0);

}


//Commands for reading switches

/* Reads the binary value of a single chosen switch */
int MPC_read_single_switch(alt_u8 SWITCHNUMBER){

	alt_u32 MASK = 1;
	alt_u32 DATA;
	alt_u32 OUT;
	DATA = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
	
	OUT = (MASK<<SWITCHNUMBER) & DATA;
	
	(OUT == 0) ? (OUT = 0) : (OUT = 1);

	return OUT;
}

/* Reads a complete mask from the switches, reading only the switches having masked binary value of 1 */
int MPC_read_mask_switches(){

	return IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);

}

/********************************************************************************************************************************
*						MUTEX FUNCTIONS
*********************************************************************************************************************************/


/* Gives a Yes/No (1/0) answer depending on if the MUTEX is owned by the current core */
int MPC_mutex_is_mine(alt_mutex_dev* MUTEX){

	return altera_avalon_mutex_is_mine(MUTEX);

}

/* Gives back the ID of the core that currently owns the MUTEX */
int MPC_mutex_owner(alt_mutex_dev* MUTEX){

	char *ptr;
	ptr = MUTEX -> mutex_base;

	return (*(ptr+2)-1);

}

/* Returns if the MUTEX has been acquired since reset */
int MPC_mutex_first_lock(alt_mutex_dev* MUTEX){

	return altera_avalon_mutex_first_lock(MUTEX);

}

/* Helper function. Tries locking the MUTEX chosen */
int alt_trylock( alt_mutex_dev* dev, alt_u32 value )
{
  alt_u32 id, data, check;
  int ret_code;

  NIOS2_READ_CPUID(id);

  /* the data we want the mutex to hold */
  data = (id << ALTERA_AVALON_MUTEX_MUTEX_OWNER_OFST) | value;

  /* attempt to write to the mutex */
  IOWR_ALTERA_AVALON_MUTEX_MUTEX(dev->mutex_base, data);
  
  check = IORD_ALTERA_AVALON_MUTEX_MUTEX(dev->mutex_base);

  if ( check == data)
  {
    ret_code = 0;
  }else{
	ret_code = -1;
  }

  return ret_code;
}

/* Blocking MUTEX acquisition function */
void MPC_mutex_lock(alt_mutex_dev* MUTEX){

  	ALT_SEM_PEND (MUTEX->lock, 0);

	while (alt_trylock( MUTEX, 1 ) != 0);

}

/* Releases the MUTEX */
void MPC_mutex_unlock(alt_mutex_dev* MUTEX){

	altera_avalon_mutex_unlock(MUTEX);

}

/* Returns the handle for the MUTEX requested */
alt_mutex_dev* MPC_mutex_open(const char* MUTEX){

	return altera_avalon_mutex_open(MUTEX);

}

/* Returns the handle for all MUTEXs in the MPC system */
MPC_MUTEXLIST MPC_mutex_open_all(){

	MPC_MUTEXLIST MUTEXES;
	
	MUTEXES.MUTEX_0 = altera_avalon_mutex_open(MUTEX_0_NAME);
	MUTEXES.MUTEX_1 = altera_avalon_mutex_open(MUTEX_1_NAME);
	MUTEXES.MUTEX_2 = altera_avalon_mutex_open(MUTEX_2_NAME);
	MUTEXES.MUTEX_3 = altera_avalon_mutex_open(MUTEX_3_NAME);
	MUTEXES.MUTEX_4 = altera_avalon_mutex_open(MUTEX_4_NAME);
	MUTEXES.MUTEX_5 = altera_avalon_mutex_open(MUTEX_5_NAME);

	return MUTEXES;

}

/********************************************************************************************************************************
*						SHARED MEMORY FUNCTIONS
*********************************************************************************************************************************/

/* Write a single 32 bit unsigned integer value to the shared memory location (starting at address 0) */
void MPC_shared_memory_write(alt_u32 DATA, alt_u32 ADDRESS){
	int *ptr = (int)(ONCHIP_SHARED_BASE + ADDRESS*4);
	*ptr = DATA;
}

/* Read a single 32 bit unsigned integer value from the shared memory location (starting at address 0) */
alt_u32 MPC_shared_memory_read(alt_u32 ADDRESS){
	int *ptr = (int)(ONCHIP_SHARED_BASE + ADDRESS*4);
	return *ptr;
}
/********************************************************************************************************************************
*						TIME STAMP FUNCTIONS
*********************************************************************************************************************************/


/* Initializes the local timestamp timer for use, starting the count */
void MPC_sys_timer_reset(alt_u32 CPU_ID){

	int *CONTROL 			= (int)(TIMER_BASES[0][CPU_ID]+4);
	int *PERIOD_LOW 		= (int)(TIMER_BASES[0][CPU_ID]+8);
	int *PERIOD_HIGH 		= (int)(TIMER_BASES[0][CPU_ID]+12);

	*CONTROL = 0x8;
	*PERIOD_LOW = 0xFFFF;
	*PERIOD_HIGH = 0xFFFF;
	*CONTROL = 0x4;

}

/* Get a local timestamp value, number of clock cycles since the timer started */
alt_u32 MPC_sys_timestamp(alt_u32 CPU_ID){

	alt_u32 SNAP_L;
	alt_u32 SNAP_H;
	alt_u32 TIME_CYCLES;

	int *SNAP_LOW 			= (int)(TIMER_BASES[0][CPU_ID]+16);
	int *SNAP_HIGH 			= (int)(TIMER_BASES[0][CPU_ID]+20);

	*SNAP_LOW = 0;
	SNAP_L = *SNAP_LOW;
	SNAP_H = *SNAP_HIGH;

	TIME_CYCLES = (0xFFFFFFFF - ((SNAP_H << 16) | SNAP_L));

	return TIME_CYCLES;
}

/* Set the period of the timer module. Useful for timer interrupts */
void MPC_sys_timer_period(alt_u32 CPU_ID, alt_u32 NEW_PERIOD){

	int *CONTROL 			= (int)(TIMER_BASES[0][CPU_ID]+4);
	int *PERIOD_LOW 		= (int)(TIMER_BASES[0][CPU_ID]+8);
	int *PERIOD_HIGH 		= (int)(TIMER_BASES[0][CPU_ID]+12);

	*PERIOD_LOW = 0xFFFF | NEW_PERIOD;
	*PERIOD_HIGH = 0xFFFF | (NEW_PERIOD >> 16);
	*CONTROL = 0x7;
	
} 



/* Initializes the local timestamp timer for use, starting the count */
void MPC_local_timestamp_reset(alt_u32 CPU_ID){
	
	int *CONTROL 			= (int)(TIMER_BASES[1][CPU_ID]+4);
	int *PERIOD_LOW 		= (int)(TIMER_BASES[1][CPU_ID]+8);
	int *PERIOD_HIGH 		= (int)(TIMER_BASES[1][CPU_ID]+12);

	*CONTROL = 0x8;
	*PERIOD_LOW = 0xFFFF;
	*PERIOD_HIGH = 0xFFFF;
	*CONTROL = 0x4;

}

/* Get a local timestamp value, number of clock cycles since the timer started */
alt_u32 MPC_local_timestamp(alt_u32 CPU_ID){
	
	alt_u32 SNAP_L;
	alt_u32 SNAP_H;
	alt_u32 TIME_CYCLES;

	int *SNAP_LOW 			= (int)(TIMER_BASES[1][CPU_ID]+16);
	int *SNAP_HIGH 			= (int)(TIMER_BASES[1][CPU_ID]+20);

	*SNAP_LOW = 0;
	SNAP_L = *SNAP_LOW;
	SNAP_H = *SNAP_HIGH;

	TIME_CYCLES = (0xFFFFFFFF - ((SNAP_H << 16) | SNAP_L));

	return TIME_CYCLES;
}


/* Initializes the local timestamp timer for use, starting the count */
void MPC_shared_timestamp_0_reset(){
	
	int *CONTROL 			= (int)(TIMER_SHARED_0_BASE+4);
	int *PERIOD_LOW 		= (int)(TIMER_SHARED_0_BASE+8);
	int *PERIOD_HIGH 		= (int)(TIMER_SHARED_0_BASE+12);

	*CONTROL = 0x8;
	*PERIOD_LOW = 0xFFFF;
	*PERIOD_HIGH = 0xFFFF;
	*CONTROL = 0x4;

}

/* Get a local timestamp value, number of clock cycles since the timer started */
alt_u32 MPC_shared_timestamp_0(){
	
	alt_u32 SNAP_L;
	alt_u32 SNAP_H;
	alt_u32 TIME_CYCLES;

	int *SNAP_LOW 			= (int)(TIMER_SHARED_0_BASE+16);
	int *SNAP_HIGH 			= (int)(TIMER_SHARED_0_BASE+20);

	*SNAP_LOW = 0;
	SNAP_L = *SNAP_LOW;
	SNAP_H = *SNAP_HIGH;

	TIME_CYCLES = (0xFFFFFFFF - ((SNAP_H << 16) | SNAP_L));

	return TIME_CYCLES;
}


/* Initializes the local timestamp timer for use, starting the count */
void MPC_shared_timestamp_1_reset(){
	
	int *CONTROL 			= (int)(TIMER_SHARED_1_BASE+4);
	int *PERIOD_LOW 		= (int)(TIMER_SHARED_1_BASE+8);
	int *PERIOD_HIGH 		= (int)(TIMER_SHARED_1_BASE+12);

	*CONTROL = 0x8;
	*PERIOD_LOW = 0xFFFF;
	*PERIOD_HIGH = 0xFFFF;
	*CONTROL = 0x4;

}

/* Get a local timestamp value, number of clock cycles since the timer started */
alt_u32 MPC_shared_timestamp_1(){
	
	alt_u32 SNAP_L;
	alt_u32 SNAP_H;
	alt_u32 TIME_CYCLES;

	int *SNAP_LOW 			= (int)(TIMER_SHARED_1_BASE+16);
	int *SNAP_HIGH 			= (int)(TIMER_SHARED_1_BASE+20);

	*SNAP_LOW = 0;
	SNAP_L = *SNAP_LOW;
	SNAP_H = *SNAP_HIGH;

	TIME_CYCLES = (0xFFFFFFFF - ((SNAP_H << 16) | SNAP_L));

	return TIME_CYCLES;
}

