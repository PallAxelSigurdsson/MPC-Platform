/* DESCRIPTION:
 * This code measures and reports the overhead of the performance counter peripheral.
 */

#include "system.h"
#include <stdio.h>
#include "MPC.h"			// The library holding all MPC OS commands.
#include "INFO.h"			// Information about the whole multicore system (central system.h)
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_performance_counter.h"

alt_u32 ITERATION 		= 0;
alt_u32 TIMER			= 0;
alt_u8 COUNTER8			= 0;
alt_u16 COUNTER16		= 0;
alt_u32 COUNTER32		= 0;
int COUNTER_INT			= 0;

alt_u32 TIMER_MIN		= 1000000;
alt_u32 TIMER_MAX		= 0;
alt_u32 TIMER_MIN_1		= 1000000;
alt_u32 TIMER_MAX_1		= 0;
alt_u32 TIMER_MIN_2		= 1000000;
alt_u32 TIMER_MAX_2		= 0;
alt_u32 TIMER_MIN_3		= 1000000;
alt_u32 TIMER_MAX_3		= 0;
alt_u32 TIMER_MIN_4		= 1000000;
alt_u32 TIMER_MAX_4		= 0;
alt_u32 TIMER_MIN_5		= 1000000;
alt_u32 TIMER_MAX_5		= 0;
alt_u32 TIMER_MIN_6		= 1000000;
alt_u32 TIMER_MAX_6		= 0;
alt_u32 TIMER_MIN_7		= 1000000;
alt_u32 TIMER_MAX_7		= 0;

int main()
{

	printf("\033c");
	printf("CORE %u\n\n",CPU_7);
	printf("\nPerformance Counter Overhead - All 7 sections (constant)\n\n");

	alt_irq_context CONTEXT;
	CONTEXT = alt_irq_disable_all();

	for(ITERATION = 0; ITERATION < 10000; ITERATION++){

		PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,1);

		//Nothing - Measuring overhead of Performance Counter

		PERF_END(PERFORMANCE_COUNTER_7_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, 1);

		if(TIMER < TIMER_MIN_1){
			TIMER_MIN_1 = TIMER;
		}
		if(TIMER > TIMER_MAX_1){
			TIMER_MAX_1 = TIMER;
		}

	}
	
	alt_irq_enable_all(CONTEXT);

	printf("PERF SECTION 1 OVERHEAD MIN: %u\n",TIMER_MIN_1);
	printf("PERF SECTION 1 OVERHEAD MAX: %u\n",TIMER_MAX_1);

	CONTEXT = alt_irq_disable_all();

	for(ITERATION = 0; ITERATION < 10000; ITERATION++){

		PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,1);

		//Nothing - Measuring overhead of Performance Counter

		PERF_END(PERFORMANCE_COUNTER_7_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, 1);

		if(TIMER < TIMER_MIN_2){
			TIMER_MIN_2 = TIMER;
		}
		if(TIMER > TIMER_MAX_2){
			TIMER_MAX_2 = TIMER;
		}

	}

	alt_irq_enable_all(CONTEXT);

	printf("PERF SECTION 2 OVERHEAD MIN: %u\n",TIMER_MIN_2);
	printf("PERF SECTION 2 OVERHEAD MAX: %u\n",TIMER_MAX_2);

	CONTEXT = alt_irq_disable_all();

	for(ITERATION = 0; ITERATION < 10000; ITERATION++){

		PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,1);

		//Nothing - Measuring overhead of Performance Counter

		PERF_END(PERFORMANCE_COUNTER_7_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, 1);

		if(TIMER < TIMER_MIN_3){
			TIMER_MIN_3 = TIMER;
		}
		if(TIMER > TIMER_MAX_3){
			TIMER_MAX_3 = TIMER;
		}

	}

	alt_irq_enable_all(CONTEXT);

	printf("PERF SECTION 3 OVERHEAD MIN: %u\n",TIMER_MIN_3);
	printf("PERF SECTION 3 OVERHEAD MAX: %u\n",TIMER_MAX_3);

	CONTEXT = alt_irq_disable_all();

	for(ITERATION = 0; ITERATION < 10000; ITERATION++){

		PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,1);

		//Nothing - Measuring overhead of Performance Counter

		PERF_END(PERFORMANCE_COUNTER_7_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, 1);

		if(TIMER < TIMER_MIN_4){
			TIMER_MIN_4 = TIMER;
		}
		if(TIMER > TIMER_MAX_4){
			TIMER_MAX_4 = TIMER;
		}

	}

	alt_irq_enable_all(CONTEXT);

	printf("PERF SECTION 4 OVERHEAD MIN: %u\n",TIMER_MIN_4);
	printf("PERF SECTION 4 OVERHEAD MAX: %u\n",TIMER_MAX_4);

	CONTEXT = alt_irq_disable_all();

	for(ITERATION = 0; ITERATION < 10000; ITERATION++){

		PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,1);

		//Nothing - Measuring overhead of Performance Counter

		PERF_END(PERFORMANCE_COUNTER_7_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, 1);

		if(TIMER < TIMER_MIN_5){
			TIMER_MIN_5 = TIMER;
		}
		if(TIMER > TIMER_MAX_5){
			TIMER_MAX_5 = TIMER;
		}

	}

	alt_irq_enable_all(CONTEXT);

	printf("PERF SECTION 5 OVERHEAD MIN: %u\n",TIMER_MIN_5);
	printf("PERF SECTION 5 OVERHEAD MAX: %u\n",TIMER_MAX_5);

	CONTEXT = alt_irq_disable_all();

	for(ITERATION = 0; ITERATION < 10000; ITERATION++){

		PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,1);

		//Nothing - Measuring overhead of Performance Counter

		PERF_END(PERFORMANCE_COUNTER_7_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, 1);

		if(TIMER < TIMER_MIN_6){
			TIMER_MIN_6 = TIMER;
		}
		if(TIMER > TIMER_MAX_6){
			TIMER_MAX_6 = TIMER;
		}

	}

	alt_irq_enable_all(CONTEXT);

	printf("PERF SECTION 6 OVERHEAD MIN: %u\n",TIMER_MIN_6);
	printf("PERF SECTION 6 OVERHEAD MAX: %u\n",TIMER_MAX_6);

	CONTEXT = alt_irq_disable_all();

	for(ITERATION = 0; ITERATION < 10000; ITERATION++){

		PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,1);

		//Nothing - Measuring overhead of Performance Counter

		PERF_END(PERFORMANCE_COUNTER_7_BASE,1);	
		PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

		TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, 1);

		if(TIMER < TIMER_MIN_7){
			TIMER_MIN_7 = TIMER;
		}
		if(TIMER > TIMER_MAX_7){
			TIMER_MAX_7 = TIMER;
		}

	}

	alt_irq_enable_all(CONTEXT);

	printf("PERF SECTION 7 OVERHEAD MIN: %u\n",TIMER_MIN_7);
	printf("PERF SECTION 7 OVERHEAD MAX: %u\n",TIMER_MAX_7);

	printf("\nPerformance Counter Overhead - All 7 sections (alt_u8)\n\n");


	for(COUNTER8 = 1; COUNTER8 < 8; COUNTER8++){
		CONTEXT = alt_irq_disable_all();

		for(ITERATION = 0; ITERATION < 10000; ITERATION++){

			PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,COUNTER8);

			//Nothing - Measuring overhead of Performance Counter

			PERF_END(PERFORMANCE_COUNTER_7_BASE,COUNTER8);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, COUNTER8);

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}

		}

		alt_irq_enable_all(CONTEXT);

		printf("PERF SECTION %u OVERHEAD MIN: %u\n",COUNTER8,TIMER_MIN);
		printf("PERF SECTION %u OVERHEAD MAX: %u\n",COUNTER8,TIMER_MAX);

		TIMER_MIN = 1000000;
		TIMER_MAX = 0;
	}

	printf("\nPerformance Counter Overhead - All 7 sections (alt_u16)\n\n");


	for(COUNTER16 = 1; COUNTER16 < 8; COUNTER16++){
		CONTEXT = alt_irq_disable_all();

		for(ITERATION = 0; ITERATION < 10000; ITERATION++){

			PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,COUNTER16);

			//Nothing - Measuring overhead of Performance Counter

			PERF_END(PERFORMANCE_COUNTER_7_BASE,COUNTER16);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, COUNTER16);

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}

		}

		alt_irq_enable_all(CONTEXT);

		printf("PERF SECTION %u OVERHEAD MIN: %u\n",COUNTER16,TIMER_MIN);
		printf("PERF SECTION %u OVERHEAD MAX: %u\n",COUNTER16,TIMER_MAX);

		TIMER_MIN = 1000000;
		TIMER_MAX = 0;
	}

	printf("\nPerformance Counter Overhead - All 7 sections (alt_u32)\n\n");


	for(COUNTER32 = 1; COUNTER32 < 8; COUNTER32++){
		CONTEXT = alt_irq_disable_all();

		for(ITERATION = 0; ITERATION < 10000; ITERATION++){

			PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,COUNTER32);

			//Nothing - Measuring overhead of Performance Counter

			PERF_END(PERFORMANCE_COUNTER_7_BASE,COUNTER32);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, COUNTER32);

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}

		}

		alt_irq_enable_all(CONTEXT);

		printf("PERF SECTION %u OVERHEAD MIN: %u\n",COUNTER32,TIMER_MIN);
		printf("PERF SECTION %u OVERHEAD MAX: %u\n",COUNTER32,TIMER_MAX);

		TIMER_MIN = 1000000;
		TIMER_MAX = 0;
	}

	printf("\nPerformance Counter Overhead - All 7 sections (integer)\n\n");


	for(COUNTER_INT = 1; COUNTER_INT < 8; COUNTER_INT++){
		CONTEXT = alt_irq_disable_all();

		for(ITERATION = 0; ITERATION < 10000; ITERATION++){

			PERF_RESET(PERFORMANCE_COUNTER_7_BASE);

			PERF_START_MEASURING(PERFORMANCE_COUNTER_7_BASE);	
			PERF_BEGIN(PERFORMANCE_COUNTER_7_BASE,COUNTER_INT);

			//Nothing - Measuring overhead of Performance Counter

			PERF_END(PERFORMANCE_COUNTER_7_BASE,COUNTER_INT);	
			PERF_STOP_MEASURING(PERFORMANCE_COUNTER_7_BASE);

			TIMER = perf_get_section_time(PERFORMANCE_COUNTER_7_BASE, COUNTER_INT);

			if(TIMER < TIMER_MIN){
				TIMER_MIN = TIMER;
			}
			if(TIMER > TIMER_MAX){
				TIMER_MAX = TIMER;
			}

		}

		alt_irq_enable_all(CONTEXT);

		printf("PERF SECTION %u OVERHEAD MIN: %u\n",COUNTER_INT,TIMER_MIN);
		printf("PERF SECTION %u OVERHEAD MAX: %u\n",COUNTER_INT,TIMER_MAX);

		TIMER_MIN = 1000000;
		TIMER_MAX = 0;
	}


	return 0;
}
