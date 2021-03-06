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

alt_u8 CPU;
alt_u8 ALMOST_FULL		= 12;
alt_u8 ALMOST_EMPTY		= 1;

int DATA;
alt_u8 SENDER;
alt_u8 RECEIVER;
alt_u8 MASK				= 0x3F;

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

	printf("\033c");
	printf("CORE %u\n",CPU);

	MPC_initialize_fifos(CPU_5, 12, 1);
	MPC_receive_from_CPU(CPU_4, CPU_5);

/****************/
/***FIFO LEVEL***/
/****************/

	printf("\n\n-------- FIFO LEVEL --------\n\n");
	printf("\nRead FIFO Level - Immediate SENDER - Immediate RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(5,0);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(5,1);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(5,2);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(5,3);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(5,4);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(0,5);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(1,5);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(2,5);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(3,5);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(4,5);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	alt_irq_enable_all(CONTEXT);

	printf("READ FIFO LEVEL MIN: %u\n",TIMER_MIN);
	printf("READ FIFO LEVEL MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nRead FIFO Level - alt_u8 SENDER - Immediate RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(CPU,0);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(CPU,1);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(CPU,2);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(CPU,3);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(CPU,4);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

				DATA = MPC_FIFO_level(SENDER,5);

				PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

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

	printf("READ FIFO LEVEL MIN: %u\n",TIMER_MIN);
	printf("READ FIFO LEVEL MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


	printf("\nRead FIFO Level - Immediate SENDER - alt_u8 RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(0,CPU);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(1,CPU);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(2,CPU);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(3,CPU);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA = MPC_FIFO_level(4,CPU);

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

				DATA = MPC_FIFO_level(5,RECEIVER);

				PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

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

	printf("READ FIFO LEVEL MIN: %u\n",TIMER_MIN);
	printf("READ FIFO LEVEL MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nRead FIFO Level - alt_u8 SENDER - alt_u8 RECEIVER - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

				DATA = MPC_FIFO_level(RECEIVER,CPU);

				PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

				if(TIMER < TIMER_MIN){
					TIMER_MIN = TIMER;
				}
				if(TIMER > TIMER_MAX){
					TIMER_MAX = TIMER;
				}
			}
		}
	}

	for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

				DATA = MPC_FIFO_level(CPU,RECEIVER);

				PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
				PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

				TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

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

	printf("READ FIFO LEVEL MIN: %u\n",TIMER_MIN);
	printf("READ FIFO LEVEL MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


	return 0;
}
