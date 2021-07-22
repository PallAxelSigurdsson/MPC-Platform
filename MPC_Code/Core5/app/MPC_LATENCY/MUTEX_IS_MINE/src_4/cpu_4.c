/* DESCRIPTION:
 * This code measures and reports the latencies of all functions 
 * relating to the MUTEX peripherals.
 */
#include "system.h"
#include "MPC.h"			// The library holding all MPC OS commands.
#include "INFO.h"			// Information about the whole multicore system (central system.h)
#include <sys/alt_irq.h>
#include "altera_avalon_performance_counter.h"

alt_u8 CPU;
alt_u8 ALMOST_FULL		= 12;
alt_u8 ALMOST_EMPTY		= 1;

int STORAGE;

MPC_MUTEXLIST MUTEXES;
alt_mutex_dev* MUTEX_SINGLE; 

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

	MPC_initialize_fifos(CPU_4, 12, 1);
	MPC_receive_from_CPU(CPU_3, CPU_4);
	MUTEXES = MPC_mutex_open_all();

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_0_NAME);
	MUTEX_SINGLE = MPC_mutex_open(MUTEX_1_NAME);
	MUTEX_SINGLE = MPC_mutex_open(MUTEX_2_NAME);
	MUTEX_SINGLE = MPC_mutex_open(MUTEX_3_NAME);
	MUTEX_SINGLE = MPC_mutex_open(MUTEX_4_NAME);
	MUTEX_SINGLE = MPC_mutex_open(MUTEX_5_NAME);

/*************************/
/***IS MUTEX MINE? NONE***/
/*************************/

	printf("\n\n-------- IS MUTEX MINE? NONE --------\n\n");
	printf("\nIs MUTEX Mine? - MPC_MUTEXLIST MUTEX - Integer Storage - Result = NONE\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_0);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_1);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_2);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_3);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_4);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_5);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("IS MUTEX MINE MIN: %u\n",TIMER_MIN);
	printf("IS MUTEX MINE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


	printf("\nIs MUTEX Mine? - alt_mutex_dev* MUTEX - Integer Storage - Result = NONE\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_0_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	MUTEX_SINGLE = MPC_mutex_open(MUTEX_1_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_2_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_3_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_4_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_5_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("IS MUTEX MINE MIN: %u\n",TIMER_MIN);
	printf("IS MUTEX MINE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

/************************/
/***IS MUTEX MINE? YES***/
/************************/

	printf("\n\n-------- IS MUTEX MINE? YES --------\n\n");
	printf("\nIs MUTEX Mine? - MPC_MUTEXLIST MUTEX - Integer Storage - Result = YES\n\n");	
	
	MPC_mutex_lock(MUTEXES.MUTEX_0);
	MPC_mutex_lock(MUTEXES.MUTEX_1);
	MPC_mutex_lock(MUTEXES.MUTEX_2);
	MPC_mutex_lock(MUTEXES.MUTEX_3);
	MPC_mutex_lock(MUTEXES.MUTEX_4);
	MPC_mutex_lock(MUTEXES.MUTEX_5);

	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_0);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_1);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_2);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_3);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_4);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_5);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("IS MUTEX MINE MIN: %u\n",TIMER_MIN);
	printf("IS MUTEX MINE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


	printf("\nIs MUTEX Mine? - alt_mutex_dev* MUTEX - Integer Storage - Result = YES\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_0_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_1_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	MUTEX_SINGLE = MPC_mutex_open(MUTEX_2_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_3_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_4_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_5_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("IS MUTEX MINE MIN: %u\n",TIMER_MIN);
	printf("IS MUTEX MINE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	MPC_mutex_unlock(MUTEXES.MUTEX_0);
	MPC_mutex_unlock(MUTEXES.MUTEX_1);
	MPC_mutex_unlock(MUTEXES.MUTEX_2);
	MPC_mutex_unlock(MUTEXES.MUTEX_3);
	MPC_mutex_unlock(MUTEXES.MUTEX_4);
	MPC_mutex_unlock(MUTEXES.MUTEX_5);
	

/***********************/
/***IS MUTEX MINE? NO***/
/***********************/

	printf("\n\n-------- IS MUTEX MINE? NO --------\n\n");
	printf("\nIs MUTEX Mine? - MPC_MUTEXLIST MUTEX - Integer Storage - Result = NO\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_0);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_1);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_2);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_3);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_4);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEXES.MUTEX_5);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("IS MUTEX MINE MIN: %u\n",TIMER_MIN);
	printf("IS MUTEX MINE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


	printf("\nIs MUTEX Mine? - alt_mutex_dev* MUTEX - Integer Storage - Result = NO\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_0_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}


	MUTEX_SINGLE = MPC_mutex_open(MUTEX_1_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_2_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_3_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_4_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}

	MUTEX_SINGLE = MPC_mutex_open(MUTEX_5_NAME);

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		STORAGE = MPC_mutex_is_mine(MUTEX_SINGLE);

		PERF_END(PERFORMANCE_COUNTER_4_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_4_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_4_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("IS MUTEX MINE MIN: %u\n",TIMER_MIN);
	printf("IS MUTEX MINE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


	return 0;
}
