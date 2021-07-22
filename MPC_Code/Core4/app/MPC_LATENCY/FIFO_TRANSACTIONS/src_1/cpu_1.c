/* DESCRIPTION:
 * This code measures and reports the latencies of all functions 
 * relating to the FIFO peripherals.
 */
#include "system.h"
#include "MPC.h"			// The library holding all MPC OS commands.
#include "INFO.h"			// Information about the whole multicore system (central system.h)
#include <sys/alt_irq.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_performance_counter.h"

alt_u32 CPU;
alt_u32 ALMOST_FULL		= 12;
alt_u32 ALMOST_EMPTY	= 1;
alt_u32 TEST			= 0;
alt_u32 ACCUMULATOR		= 0;

alt_u8 SENDER;
alt_u8 RECEIVER;
int DATA				= 100;

alt_u32 INDEX 			= 0;
alt_u32 TIMER			= 0;
alt_u32 ITERATIONS		= 10000;

alt_u32 TIMER_MIN		= 1000000;
alt_u32 TIMER_MAX		= 0;

alt_u32 PERF_OVERHEAD	= 16;

int main()
{

	alt_irq_context CONTEXT;

	NIOS2_READ_CPUID(CPU);
	CPU--;

	MPC_local_timestamp_reset(CPU);

	printf("\033c");
	printf("CORE %u\n",CPU);
	MPC_initialize_fifos(1,12,1);
	

/*********************** TEST 1 ***********************/

/******/
/*SEND*/
/******/


	printf("\n\n-------- TRANSACTIONS --------\n\n");

	printf("\nSend To CPU - Immediate SENDER - Immediate RECEIVER - Immediate DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(1,0,100);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(1,2,100);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(1,3,100);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

	alt_irq_enable_all(CONTEXT);

	printf("SEND THROUGH FIFO MIN: %u\n",TIMER_MIN);
	printf("SEND THROUGH FIFO MAX: %u\n",TIMER_MAX);

	
	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********/
/*RECEIVE*/
/*********/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nReceive From CPU - Immediate SENDER - Immediate RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			DATA = MPC_receive_from_CPU(0,1);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			DATA = MPC_receive_from_CPU(2,1);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			DATA = MPC_receive_from_CPU(3,1);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

	alt_irq_enable_all(CONTEXT);

	printf("RECEIVE FROM FIFO MIN: %u\n",TIMER_MIN);
	printf("RECEIVE FROM FIFO MAX: %u\n",TIMER_MAX);



	TIMER_MIN = 1000000;
	TIMER_MAX = 0;



/*********************** TEST 2 ***********************/

/******/
/*SEND*/
/******/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);


	printf("\nSend To CPU - alt_u8 SENDER - Immediate RECEIVER - Immediate DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(CPU,0,100);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(CPU,2,100);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(CPU,3,100);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

	alt_irq_enable_all(CONTEXT);

	printf("SEND THROUGH FIFO MIN: %u\n",TIMER_MIN);
	printf("SEND THROUGH FIFO MAX: %u\n",TIMER_MAX);

	
	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********/
/*RECEIVE*/
/*********/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nReceive From CPU - Immediate SENDER - alt_u8 RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			DATA = MPC_receive_from_CPU(0,CPU);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			DATA = MPC_receive_from_CPU(2,CPU);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			DATA = MPC_receive_from_CPU(3,CPU);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

	alt_irq_enable_all(CONTEXT);

	printf("RECEIVE FROM FIFO MIN: %u\n",TIMER_MIN);
	printf("RECEIVE FROM FIFO MAX: %u\n",TIMER_MAX);



	TIMER_MIN = 1000000;
	TIMER_MAX = 0;



/*********************** TEST 3 ***********************/

/******/
/*SEND*/
/******/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nSend To CPU - Immediate SENDER - Immediate RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(1,0,DATA);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(1,2,DATA);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(1,3,DATA);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

	alt_irq_enable_all(CONTEXT);

	printf("SEND THROUGH FIFO MIN: %u\n",TIMER_MIN);
	printf("SEND THROUGH FIFO MAX: %u\n",TIMER_MAX);

	
	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********/
/*RECEIVE*/
/*********/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nReceive From CPU - alt_u8 SENDER - Immediate RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_receive_from_CPU(SENDER,1);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("RECEIVE FROM FIFO MIN: %u\n",TIMER_MIN);
	printf("RECEIVE FROM FIFO MAX: %u\n",TIMER_MAX);



	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

;

/*********************** TEST 4 ***********************/

/******/
/*SEND*/
/******/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nSend To CPU - alt_u8 SENDER - Immediate RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(CPU,0,DATA);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(CPU,2,DATA);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

		for(INDEX = 0; INDEX < 13; INDEX++){
			PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

			MPC_send_to_CPU(CPU,3,DATA);

			PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}
		}

	alt_irq_enable_all(CONTEXT);

	printf("SEND THROUGH FIFO MIN: %u\n",TIMER_MIN);
	printf("SEND THROUGH FIFO MAX: %u\n",TIMER_MAX);

	
	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********/
/*RECEIVE*/
/*********/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nReceive From CPU - alt_u8 SENDER - alt_u8 RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_receive_from_CPU(SENDER,CPU);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("RECEIVE FROM FIFO MIN: %u\n",TIMER_MIN);
	printf("RECEIVE FROM FIFO MAX: %u\n",TIMER_MAX);



	TIMER_MIN = 1000000;
	TIMER_MAX = 0;



/*********************** TEST 5 ***********************/

/******/
/*SEND*/
/******/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);


	printf("\nSend To CPU - Immediate SENDER - alt_u8 RECEIVER - Immediate DATA\n\n");
	
	CONTEXT = alt_irq_disable_all();

	for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				MPC_send_to_CPU(1,RECEIVER,100);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("SEND THROUGH FIFO MIN: %u\n",TIMER_MIN);
	printf("SEND THROUGH FIFO MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********/
/*RECEIVE*/
/*********/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nReceive From CPU - alt_u8 SENDER - alt_u8 RECEIVER - Integer DATA ---REDUNDANT---\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_receive_from_CPU(SENDER,CPU);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("RECEIVE FROM FIFO MIN: %u\n",TIMER_MIN);
	printf("RECEIVE FROM FIFO MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;



/*********************** TEST 6 ***********************/

/******/
/*SEND*/
/******/


	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nSend To CPU - alt_u8 SENDER - alt_u8 RECEIVER - Immediate DATA\n\n");
	
	CONTEXT = alt_irq_disable_all();

	for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				MPC_send_to_CPU(CPU,RECEIVER,100);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("SEND THROUGH FIFO MIN: %u\n",TIMER_MIN);
	printf("SEND THROUGH FIFO MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********/
/*RECEIVE*/
/*********/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nReceive From CPU - alt_u8 SENDER - alt_u8 RECEIVER - Integer DATA ---REDUNDANT---\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_receive_from_CPU(SENDER,CPU);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("RECEIVE FROM FIFO MIN: %u\n",TIMER_MIN);
	printf("RECEIVE FROM FIFO MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;




/*********************** TEST 7 ***********************/

/******/
/*SEND*/
/******/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);


	printf("\nSend To CPU - Immediate SENDER - alt_u8 RECEIVER - Integer DATA\n\n");
	
	CONTEXT = alt_irq_disable_all();

	for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				MPC_send_to_CPU(1,RECEIVER,DATA);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("SEND THROUGH FIFO MIN: %u\n",TIMER_MIN);
	printf("SEND THROUGH FIFO MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********/
/*RECEIVE*/
/*********/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nReceive From CPU - alt_u8 SENDER - alt_u8 RECEIVER - Integer DATA ---REDUNDANT---\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_receive_from_CPU(SENDER,CPU);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("RECEIVE FROM FIFO MIN: %u\n",TIMER_MIN);
	printf("RECEIVE FROM FIFO MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********************** TEST 8 ***********************/

/******/
/*SEND*/
/******/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);


	printf("\nSend To CPU - alt_u8 SENDER - alt_u8 RECEIVER - Integer DATA\n\n");
	
	CONTEXT = alt_irq_disable_all();

	for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				MPC_send_to_CPU(CPU,RECEIVER,DATA);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("SEND THROUGH FIFO MIN: %u\n",TIMER_MIN);
	printf("SEND THROUGH FIFO MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


/*********/
/*RECEIVE*/
/*********/

	while(MPC_local_timestamp(CPU)/50000000 < 2){}

	MPC_local_timestamp_reset(CPU);

	printf("\nReceive From CPU - alt_u8 SENDER - alt_u8 RECEIVER - Integer DATA ---REDUNDANT---\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_receive_from_CPU(SENDER,CPU);

				PERF_END(PERFORMANCE_COUNTER_1_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_1_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_1_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}
		

	alt_irq_enable_all(CONTEXT);

	printf("RECEIVE FROM FIFO MIN: %u\n",TIMER_MIN);
	printf("RECEIVE FROM FIFO MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;




	return 0;
}
