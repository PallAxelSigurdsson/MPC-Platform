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

	MPC_initialize_fifos(CPU_1, 12, 1);
	MPC_receive_from_CPU(CPU_0, CPU_1);


/*****************/
/***FIFO STATUS***/
/*****************/

	printf("\n\n-------- READ FIFO STATUS --------\n\n");
	printf("\nRead FIFO Status - Immediate SENDER - Immediate RECEIVER - Immediate MASK - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 0, 0x3F);

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
	
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 2, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 3, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 4, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 5, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(0, 1, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(2, 1, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(3, 1, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(4, 1, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(5, 1, 0x3F);

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

	printf("READ FIFO STATUS MIN: %u\n",TIMER_MIN);
	printf("READ FIFO STATUS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;






printf("\nRead FIFO Status - Immediate SENDER - Immediate RECEIVER - alt_u8 MASK - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 0, MASK);

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
	
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 2, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 3, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 4, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(1, 5, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(0, 1, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(2, 1, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(3, 1, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(4, 1, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(5, 1, MASK);

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

	printf("READ FIFO STATUS MIN: %u\n",TIMER_MIN);
	printf("READ FIFO STATUS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;



	printf("\nRead FIFO Status - alt_u8 SENDER - Immediate RECEIVER - Immediate MASK - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 0, 0x3F);

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
	
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 2, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 3, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 4, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 5, 0x3F);

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

		for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_FIFO_status(SENDER, 1, 0x3F);

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

	printf("READ FIFO STATUS MIN: %u\n",TIMER_MIN);
	printf("READ FIFO STATUS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;



	printf("\nRead FIFO Status - alt_u8 SENDER - Immediate RECEIVER - alt_u8 MASK - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 0, MASK);

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
	
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 2, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 3, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 4, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(CPU, 5, MASK);

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

		for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_FIFO_status(SENDER, 1, MASK);

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

	printf("READ FIFO STATUS MIN: %u\n",TIMER_MIN);
	printf("READ FIFO STATUS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


printf("\nRead FIFO Status - Immediate SENDER - alt_u8 RECEIVER - Immediate MASK - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(0,CPU, 0x3F);

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
	
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(2,CPU, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(3,CPU, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(4,CPU, 0x3F);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(5,CPU, 0x3F);

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

		for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_FIFO_status(1, RECEIVER, 0x3F);

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

	printf("READ FIFO STATUS MIN: %u\n",TIMER_MIN);
	printf("READ FIFO STATUS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;




printf("\nRead FIFO Status - Immediate SENDER - alt_u8 RECEIVER - alt_u8 MASK - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(0,CPU, MASK);

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
	
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(2,CPU, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(3,CPU, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(4,CPU, MASK);

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

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

		DATA = MPC_FIFO_status(5,CPU, MASK);

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

		for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_FIFO_status(1, RECEIVER, MASK);

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

	printf("READ FIFO STATUS MIN: %u\n",TIMER_MIN);
	printf("READ FIFO STATUS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;




printf("\nRead FIFO Status - alt_u8 SENDER - alt_u8 RECEIVER - Immediate MASK - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

		for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_FIFO_status(SENDER, CPU, 0x3F);

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

		for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_FIFO_status(CPU, RECEIVER, 0x3F);

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

	printf("READ FIFO STATUS MIN: %u\n",TIMER_MIN);
	printf("READ FIFO STATUS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

printf("\nRead FIFO Status - alt_u8 SENDER - alt_u8 RECEIVER - alt_u8 MASK - Integer DATA\n\n");	
	
	CONTEXT = alt_irq_disable_all();

		for(SENDER = 0; SENDER < CORE_COUNT; SENDER++){
	
			if(CPU != SENDER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_FIFO_status(SENDER, CPU, MASK);

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

		for(RECEIVER = 0; RECEIVER < CORE_COUNT; RECEIVER++){
	
			if(CPU != RECEIVER){

			for(INDEX = 0; INDEX < 13; INDEX++){
				PERF_RESET(PERFORMANCE_COUNTER_1_BASE);

				PERF_START_MEASURING(PERFORMANCE_COUNTER_1_BASE);	
				PERF_BEGIN(PERFORMANCE_COUNTER_1_BASE,1);

				DATA = MPC_FIFO_status(CPU, RECEIVER, MASK);

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

	printf("READ FIFO STATUS MIN: %u\n",TIMER_MIN);
	printf("READ FIFO STATUS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;




	MPC_send_to_CPU(CPU_1, CPU_2 , 10);

	return 0;
}
