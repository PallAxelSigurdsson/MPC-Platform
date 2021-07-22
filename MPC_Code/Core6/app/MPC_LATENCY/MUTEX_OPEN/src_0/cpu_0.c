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

	MPC_initialize_fifos(CPU_0, 12, 1);

/***********************/
/***OPEN SINGLE MUTEX***/
/***********************/

	printf("\n\n-------- OPEN SINGLE MUTEX --------\n\n");
	printf("\nOpen single MUTEX 0 - const char* MUTEX - alt_mutex_dev* Storage\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_0_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_0_BASE,1);

		MUTEX_SINGLE = MPC_mutex_open(MUTEX_0_NAME);

		PERF_END(PERFORMANCE_COUNTER_0_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_0_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_0_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("OPEN SINGLE MUTEX MIN: %u\n",TIMER_MIN);
	printf("OPEN SINGLE MUTEX MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nOpen single MUTEX 1 - const char* MUTEX - alt_mutex_dev* Storage\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_0_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_0_BASE,1);

		MUTEX_SINGLE = MPC_mutex_open(MUTEX_1_NAME);

		PERF_END(PERFORMANCE_COUNTER_0_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_0_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_0_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("OPEN SINGLE MUTEX MIN: %u\n",TIMER_MIN);
	printf("OPEN SINGLE MUTEX MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nOpen single MUTEX 2 - const char* MUTEX - alt_mutex_dev* Storage\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_0_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_0_BASE,1);

		MUTEX_SINGLE = MPC_mutex_open(MUTEX_2_NAME);

		PERF_END(PERFORMANCE_COUNTER_0_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_0_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_0_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("OPEN SINGLE MUTEX MIN: %u\n",TIMER_MIN);
	printf("OPEN SINGLE MUTEX MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nOpen single MUTEX 3 - const char* MUTEX - alt_mutex_dev* Storage\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_0_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_0_BASE,1);

		MUTEX_SINGLE = MPC_mutex_open(MUTEX_3_NAME);

		PERF_END(PERFORMANCE_COUNTER_0_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_0_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_0_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("OPEN SINGLE MUTEX MIN: %u\n",TIMER_MIN);
	printf("OPEN SINGLE MUTEX MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nOpen single MUTEX 4 - const char* MUTEX - alt_mutex_dev* Storage\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_0_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_0_BASE,1);

		MUTEX_SINGLE = MPC_mutex_open(MUTEX_4_NAME);

		PERF_END(PERFORMANCE_COUNTER_0_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_0_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_0_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("OPEN SINGLE MUTEX MIN: %u\n",TIMER_MIN);
	printf("OPEN SINGLE MUTEX MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nOpen single MUTEX 5 - const char* MUTEX - alt_mutex_dev* Storage\n\n");	
	
	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_0_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_0_BASE,1);

		MUTEX_SINGLE = MPC_mutex_open(MUTEX_5_NAME);

		PERF_END(PERFORMANCE_COUNTER_0_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_0_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_0_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	
	alt_irq_enable_all(CONTEXT);

	printf("OPEN SINGLE MUTEX MIN: %u\n",TIMER_MIN);
	printf("OPEN SINGLE MUTEX MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

/**********************/
/***OPEN ALL MUTEXES***/
/**********************/

	printf("\n\n-------- OPEN ALL MUTEXES --------\n\n");
	printf("\nOpen All MUTEXES - MPC_MUTEXLIST Storage\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_0_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_0_BASE,1);

		MUTEXES = MPC_mutex_open_all();

		PERF_END(PERFORMANCE_COUNTER_0_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_0_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_0_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}
	}
	alt_irq_enable_all(CONTEXT);

	printf("OPEN ALL MUTEXES MIN: %u\n",TIMER_MIN);
	printf("OPEN ALL MUTEXES MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


	MPC_send_to_CPU(CPU_0, CPU_1 , 10);

	return 0;
}
