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
/***INITIALIZE***/
/****************/

	printf("\n\n-------- INITIALIZE FIFOS --------\n\n");
	printf("\nInitialize FIFOs - Immediate CPU - Immediate ALMOST_FULL - Immediate ALMOST_EMPTY\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		MPC_initialize_fifos(5,12,1);

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

	printf("INITIALIZE FIFOS MIN: %u\n",TIMER_MIN);
	printf("INITIALIZE FIFOS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nInitialize FIFOs - alt_u8 CPU - Immediate ALMOST_FULL - Immediate ALMOST_EMPTY\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		MPC_initialize_fifos(CPU,12,1);

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

	printf("INITIALIZE FIFOS MIN: %u\n",TIMER_MIN);
	printf("INITIALIZE FIFOS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nInitialize FIFOs - Immediate CPU - alt_u8 ALMOST_FULL - Immediate ALMOST_EMPTY\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		MPC_initialize_fifos(5,ALMOST_FULL,1);

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

	printf("INITIALIZE FIFOS MIN: %u\n",TIMER_MIN);
	printf("INITIALIZE FIFOS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nInitialize FIFOs - Immediate CPU - Immediate ALMOST_FULL - alt_u8 ALMOST_EMPTY\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		MPC_initialize_fifos(5,12,ALMOST_EMPTY);

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

	printf("INITIALIZE FIFOS MIN: %u\n",TIMER_MIN);
	printf("INITIALIZE FIFOS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nInitialize FIFOs - alt_u8 CPU - alt_u8 ALMOST_FULL - Immediate ALMOST_EMPTY\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		MPC_initialize_fifos(CPU,ALMOST_FULL,1);

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

	printf("INITIALIZE FIFOS MIN: %u\n",TIMER_MIN);
	printf("INITIALIZE FIFOS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nInitialize FIFOs - alt_u8 CPU - Immediate ALMOST_FULL - alt_u8 ALMOST_EMPTY\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		MPC_initialize_fifos(CPU,12,ALMOST_EMPTY);

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

	printf("INITIALIZE FIFOS MIN: %u\n",TIMER_MIN);
	printf("INITIALIZE FIFOS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nInitialize FIFOs - Immediate CPU - alt_u8 ALMOST_FULL - alt_u8 ALMOST_EMPTY\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		MPC_initialize_fifos(5,ALMOST_FULL,ALMOST_EMPTY);

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

	printf("INITIALIZE FIFOS MIN: %u\n",TIMER_MIN);
	printf("INITIALIZE FIFOS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nInitialize FIFOs - alt_u8 CPU - alt_u8 ALMOST_FULL - alt_u8 ALMOST_EMPTY\n\n");	
	
	CONTEXT = alt_irq_disable_all();


	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		MPC_initialize_fifos(CPU,ALMOST_FULL,ALMOST_EMPTY);

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

	printf("INITIALIZE FIFOS MIN: %u\n",TIMER_MIN);
	printf("INITIALIZE FIFOS MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	return 0;
}
