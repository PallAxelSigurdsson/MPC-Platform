/* DESCRIPTION:
 * This code measures and reports the latencies of all functions 
 * relating to the shared timer peripherals.
 */
#include "system.h"
#include "MPC.h"			// The library holding all MPC OS commands.
#include "INFO.h"			// Information about the whole multicore system (central system.h)
#include <sys/alt_irq.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_performance_counter.h"

alt_u32 READ_DATA		= 0;

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
	printf("CORE %u\n",CPU_3);

	alt_irq_context CONTEXT;

	MPC_initialize_fifos(CPU_3, 12, 1);
	MPC_receive_from_CPU(CPU_2, CPU_3);

	printf("\n\n-------- SHARED TIMESTAMP 0 RESET --------\n\n");

	printf("\nShared Timestamp 0 Reset\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_shared_timestamp_0_reset();

		PERF_END(PERFORMANCE_COUNTER_3_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_3_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_3_BASE, 1)-PERF_OVERHEAD;

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

	printf("TIMESTAMP 0 RESET MIN: %u\n",TIMER_MIN);
	printf("TIMESTAMP 0 RESET MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	


	printf("\n\n-------- SHARED TIMESTAMP 0 --------\n\n");

	printf("\nShared Timestamp 0 - alt_u32 Storage\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		READ_DATA = MPC_shared_timestamp_0();

		PERF_END(PERFORMANCE_COUNTER_3_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_3_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_3_BASE, 1)-PERF_OVERHEAD;

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

	printf("TIMESTAMP 0 MIN: %u\n",TIMER_MIN);
	printf("TIMESTAMP 0 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;




	printf("\n\n-------- SHARED TIMESTAMP 1 RESET --------\n\n");

	printf("\nShared Timestamp 1 Reset\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_shared_timestamp_1_reset();

		PERF_END(PERFORMANCE_COUNTER_3_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_3_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_3_BASE, 1)-PERF_OVERHEAD;

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

	printf("TIMESTAMP 1 RESET MIN: %u\n",TIMER_MIN);
	printf("TIMESTAMP 1 RESET MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	


	printf("\n\n-------- SHARED TIMESTAMP 1 --------\n\n");

	printf("\nShared Timestamp 1 - alt_u32 Storage\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		READ_DATA = MPC_shared_timestamp_1();

		PERF_END(PERFORMANCE_COUNTER_3_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_3_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_3_BASE, 1)-PERF_OVERHEAD;

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

	printf("TIMESTAMP 1 MIN: %u\n",TIMER_MIN);
	printf("TIMESTAMP 1 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;	


	MPC_send_to_CPU(CPU_3, CPU_4 , 10);

	return 0;
}
