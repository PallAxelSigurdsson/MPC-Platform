/* DESCRIPTION:
 * This code measures and reports the critical arbitration latency 
 * for the DATA = IORD_ALTERA_AVALON_MUTEX_MUTEX(MUTEXES.MUTEX_0->mutex_base) function.
 */

#include "system.h"
#include <stdio.h>
#include "MPC.h"			// The library holding all MPC OS commands.
#include "INFO.h"			// Information about the whole multicore system (central system.h)
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_performance_counter.h"
#include "altera_avalon_mutex_regs.h"

alt_u32 DATA;
alt_u32 TIMER;
alt_u32 MEM_INDEX;

alt_u32 ITERATION 		= 0;

MPC_MUTEXLIST MUTEXES;

alt_u32 TIME_MAX 		= 1;
alt_u32 TIME_MIN 		= 1000000;
alt_u32 CORE_MAX 		= 1;
alt_u32 CORE_MIN 		= 1000000;
alt_u32 SHARED_MAX 		= 1;
alt_u32 SHARED_MIN 		= 1000000;

/* The performance counter measurement overhead (in clock cycles). */
alt_u32 PERF_OVERHEAD 	= 16;

/* The below pointers are used for accessing the registers in the System clock timer core. */
int *STATUS 			= (int)(TIMER_3_0_BASE);
int *CONTROL 			= (int)(TIMER_3_0_BASE+4);
int *PERIOD_LOW 		= (int)(TIMER_3_0_BASE+8);
int *PERIOD_HIGH 		= (int)(TIMER_3_0_BASE+12);
int *SNAP_LOW 			= (int)(TIMER_3_0_BASE+16);
int *SNAP_HIGH 			= (int)(TIMER_3_0_BASE+20);

void measure(void* context){

	*STATUS = 0x2;

	PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
	PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

	DATA = IORD_ALTERA_AVALON_MUTEX_MUTEX(MUTEXES.MUTEX_0->mutex_base);

	PERF_END(PERFORMANCE_COUNTER_3_BASE,1);	
	PERF_STOP_MEASURING(PERFORMANCE_COUNTER_3_BASE);

	TIMER = perf_get_section_time(PERFORMANCE_COUNTER_3_BASE, 1);

	PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

	ITERATION++;
	
	if(TIMER < TIME_MIN){
		TIME_MIN = TIMER;
	}
	if(TIMER > TIME_MAX){
		TIME_MAX = TIMER;
	}

	if(ITERATION == 10000){
	
		TIME_MIN = TIME_MIN - PERF_OVERHEAD;
		TIME_MAX = TIME_MAX - PERF_OVERHEAD;

		MPC_shared_memory_write(TIME_MIN, 10+CPU_3);
		MPC_shared_memory_write(TIME_MAX, 20+CPU_3);

		printf("\033c");

		printf("\n\nCongestion test - IORD_ALTERA_AVALON_MUTEX_MUTEX(MUTEXES.MUTEX_0->mutex_base) \n\n");
		printf("UNITS: Clock cycles\n\n");

		printf("LOCAL CORE REPORT - Core %u   \n",CPU_3);
		printf("MIN LATENCY                 : %u   \n",TIME_MIN);
		printf("MAX LATENCY                 : %u   \n",TIME_MAX);
		printf("MAX ARBITRATION LATENCY     : %u   \n",TIME_MAX-TIME_MIN);
	}

	if(ITERATION == 10001){
		for(MEM_INDEX = 0; MEM_INDEX < CORE_COUNT; MEM_INDEX++){
			SHARED_MIN = MPC_shared_memory_read(10+MEM_INDEX);
			SHARED_MAX = MPC_shared_memory_read(20+MEM_INDEX);

			if(SHARED_MIN < CORE_MIN){
				CORE_MIN = SHARED_MIN;
			}
			if(SHARED_MAX > CORE_MAX){
				CORE_MAX = SHARED_MAX;
			}

		}

		printf("\nOVERALL SYSTEM REPORT\n");
		printf("MIN LATENCY                 : %u   \n",CORE_MIN);
		printf("MAX LATENCY                 : %u   \n",CORE_MAX);
		printf("MAX ARBITRATION LATENCY     : %u   \n",CORE_MAX-CORE_MIN);

		*STATUS = 0x3;
	}

}


int main()
{
	// Initialize timer
	*PERIOD_LOW = 0xc34f;
	*PERIOD_HIGH = 0x0000;
	*CONTROL = 0x7;

	MUTEXES = MPC_mutex_open_all();

	PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

	alt_ic_isr_register(TIMER_3_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_3_0_IRQ, measure, NULL, NULL);

	while(1){}

	return 0;
}
