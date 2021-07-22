/* DESCRIPTION:
 * This code measures and reports the latencies of all functions 
 * relating to the shared memory peripheral.
 */
#include "system.h"
#include "MPC.h"			// The library holding all MPC OS commands.
#include "INFO.h"			// Information about the whole multicore system (central system.h)
#include <sys/alt_irq.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_performance_counter.h"

alt_u32 WRITE_DATA32	= 100;
alt_u32 ADDRESS32		= 100;
alt_u32 READ_DATA32		= 0;

alt_u32 INDEX 			= 0;
alt_u32 TIMER			= 0;
alt_u32 ITERATIONS		= 10000;

alt_u32 TIMER_MIN		= 1000000;
alt_u32 TIMER_MAX		= 0;

alt_u32 MEASURED_MIN	= 1000000;
alt_u32 MEASURED_MAX	= 0;

alt_u32 PERF_OVERHEAD	= 16;

int main()
{
	printf("\033c");
	printf("CORE %u\n",CPU_4);

	MPC_initialize_fifos(CPU_4, 12, 1);
	MPC_receive_from_CPU(CPU_3, CPU_4);
	printf("\n\n-------- SHARED MEMORY WRITE --------\n\n");

	alt_irq_context CONTEXT;

	printf("\nShared Memory Write - Immediate DATA - Immediate ADDRESS\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		MPC_shared_memory_write(100,100);

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
	
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("SHARED MEM WRITE MIN: %u\n",TIMER_MIN);
	printf("SHARED MEM WRITE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nShared Memory Write - alt_u32 DATA - Immediate ADDRESS\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		MPC_shared_memory_write(WRITE_DATA32,100);

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
	
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("SHARED MEM WRITE MIN: %u\n",TIMER_MIN);
	printf("SHARED MEM WRITE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nShared Memory Write - Immediate DATA - alt_u32 ADDRESS\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		MPC_shared_memory_write(100,ADDRESS32);

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
	
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("SHARED MEM WRITE MIN: %u\n",TIMER_MIN);
	printf("SHARED MEM WRITE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nShared Memory Write - alt_u32 DATA - alt_u32 ADDRESS\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		MPC_shared_memory_write(WRITE_DATA32,ADDRESS32);

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
	
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("SHARED MEM WRITE MIN: %u\n",TIMER_MIN);
	printf("SHARED MEM WRITE MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;





printf("\n\n-------- SHARED MEMORY READ --------\n\n");


	printf("\nShared Memory Read - alt_u32 Storage - Immediate ADDRESS\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		READ_DATA32 = MPC_shared_memory_read(100);

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
	
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("SHARED MEM READ MIN: %u\n",TIMER_MIN);
	printf("SHARED MEM READ MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nShared Memory Read - alt_u32 Storage - alt_u32 ADDRESS\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_4_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_4_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_4_BASE,1);

		READ_DATA32 = MPC_shared_memory_read(ADDRESS32);

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
	
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("SHARED MEM READ MIN: %u\n",TIMER_MIN);
	printf("SHARED MEM READ MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	return 0;
}
