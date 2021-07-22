/* DESCRIPTION:
 * This code measures and reports the latencies of all functions 
 * relating to the switches peripheral.
 */

#include "system.h"
#include "MPC.h"			// The library holding all MPC OS commands.
#include "INFO.h"			// Information about the whole multicore system (central system.h)
#include <sys/alt_irq.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_performance_counter.h"

alt_u8 COUNTER8			= 0;

int DATA_INT			= 0;

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
	printf("CORE %u\n",CPU_5);

	MPC_initialize_fifos(CPU_5, 12, 1);
	MPC_receive_from_CPU(CPU_4, CPU_5);

	printf("\n\n-------- READ SINGLE SWITCH --------\n\n");

	alt_irq_context CONTEXT;
	CONTEXT = alt_irq_disable_all();

	printf("\nRead Single Switch - Immediate Argument - Integer Storage\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(0);

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
	
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 0 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 0 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(1);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 1 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 1 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(2);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 2 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 2 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(3);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 3 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 3 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(4);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 4 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 4 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(5);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 5 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 5 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(6);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 6 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 6 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(7);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 7 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 7 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(8);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 8 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 8 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(9);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 9 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 9 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(10);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 10 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 10 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(11);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 11 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 11 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(12);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 12 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 12 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(13);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 13 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 13 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(14);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 14 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 14 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(15);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 15 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 15 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(16);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 16 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 16 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(17);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH 17 MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH 17 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


	printf("\nREAD SWITCH MIN: %u\n",MEASURED_MIN);
	printf("READ SWITCH MAX: %u\n",MEASURED_MAX);

	MEASURED_MIN = 1000000;
	MEASURED_MAX = 0;




	printf("\nRead Single Switch - alt_u8 Argument - Integer Storage\n\n");

for(COUNTER8 = 0; COUNTER8 < 18; COUNTER8++){
	CONTEXT = alt_irq_disable_all();
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_single_switch(COUNTER8);

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
		
	if(TIMER_MIN < MEASURED_MIN){
		MEASURED_MIN = TIMER_MIN;
		}
	if(TIMER_MAX > MEASURED_MAX){
		MEASURED_MAX = TIMER_MAX;
		}

	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH %u MIN	: %u\n",COUNTER8,TIMER_MIN);
	printf("READ SWITCH %u MAX	: %u\n",COUNTER8,TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;
}

	printf("\nREAD SWITCH MIN  : %u\n",MEASURED_MIN);
	printf("READ SWITCH MAX  : %u\n",MEASURED_MAX);

	MEASURED_MIN = 1000000;
	MEASURED_MAX = 0;


	printf("\n\n-------- READ SWITCH MASK --------\n\n");

printf("\nRead Switches Mask - No Argument - Integer Storage\n\n");

	CONTEXT = alt_irq_disable_all();

		PERF_RESET(PERFORMANCE_COUNTER_5_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_5_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_5_BASE,1);

		DATA_INT = MPC_read_mask_switches();

		PERF_END(PERFORMANCE_COUNTER_5_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_5_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_5_BASE, 1)-PERF_OVERHEAD;

		if(TIMER < TIMER_MIN){
			TIMER_MIN = TIMER;
		}
		if(TIMER > TIMER_MAX){
			TIMER_MAX = TIMER;
		}

	
	alt_irq_enable_all(CONTEXT);

	printf("READ SWITCH MIN: %u\n",TIMER_MIN);
	printf("READ SWITCH MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	return 0;
}
