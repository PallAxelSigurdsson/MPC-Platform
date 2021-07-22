/* DESCRIPTION:
 * This code measures and reports the latencies of all functions 
 * relating to the green LED peripheral.
 */

#include "system.h"
#include "MPC.h"			// The library holding all MPC OS commands.
#include "INFO.h"			// Information about the whole multicore system (central system.h)
#include <sys/alt_irq.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_performance_counter.h"

alt_u8 COUNTER8			= 0;

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

	MPC_initialize_fifos(CPU_3, 12, 1);
	MPC_receive_from_CPU(CPU_2, CPU_3);

	printf("\n\n-------- WRITE SINGLE GREEN LED --------\n\n");

	printf("\nWrite Single Green LED - Immediate\n\n");

	alt_irq_context CONTEXT;
	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(0);

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

	printf("WRITE GREEN LED 0 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 0 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(1);

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

	printf("WRITE GREEN LED 1 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 1 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(2);

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

	printf("WRITE GREEN LED 2 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 2 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(3);

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

	printf("WRITE GREEN LED 3 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 3 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(4);

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

	printf("WRITE GREEN LED 4 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 4 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(5);

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

	printf("WRITE GREEN LED 5 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 5 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(6);

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

	printf("WRITE GREEN LED 6 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 6 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(7);

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

	printf("WRITE GREEN LED 7 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 7 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;



	printf("\nWRITE GREEN LED MIN: %u\n",MEASURED_MIN);
	printf("WRITE GREEN LED MAX: %u\n",MEASURED_MAX);

	MEASURED_MIN = 1000000;
	MEASURED_MAX = 0;



	printf("\nWrite Single Green LED - alt_u8\n\n");



for(COUNTER8 = 0; COUNTER8 < 8; COUNTER8++){
	CONTEXT = alt_irq_disable_all();
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_single_green_LED(COUNTER8);

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

	printf("WRITE GREEN LED %u MIN: %u\n",COUNTER8,TIMER_MIN);
	printf("WRITE GREEN LED %u MAX: %u\n",COUNTER8,TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;
}

	printf("\nWRITE GREEN LED MIN: %u\n",MEASURED_MIN);
	printf("WRITE GREEN LED MAX: %u\n",MEASURED_MAX);

	MEASURED_MIN = 1000000;
	MEASURED_MAX = 0;


//NEXT TEST



printf("\n\n-------- WRITE MASK GREEN LED --------\n\n");

	printf("\nWrite Mask Green LED - Immediate\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_mask_green_LED(0xFF);

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

	printf("WRITE GREEN LED 0 MIN: %u\n",TIMER_MIN);
	printf("WRITE GREEN LED 0 MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;

	printf("\nWrite Mask Green LED - alt_u8\n\n");


	CONTEXT = alt_irq_disable_all();
	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_write_mask_green_LED(COUNTER8);

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
		

	alt_irq_enable_all(CONTEXT);

	printf("WRITE MASK GREEN LED MIN: %u\n",TIMER_MIN);
	printf("WRITE MASK GREEN LED MAX: %u\n",TIMER_MAX);

	TIMER_MIN = 1000000;
	TIMER_MAX = 0;


//NEXT TEST



printf("\n\n-------- RESET GREEN LED --------\n\n");

	printf("\nReset Green LED - No Argument\n\n");

	CONTEXT = alt_irq_disable_all();

	for(INDEX = 0; INDEX < ITERATIONS; INDEX++){

		PERF_RESET(PERFORMANCE_COUNTER_3_BASE);

		PERF_START_MEASURING(PERFORMANCE_COUNTER_3_BASE);	
		PERF_BEGIN(PERFORMANCE_COUNTER_3_BASE,1);

		MPC_reset_green_leds();

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

	printf("RESET GREEN LED 0 MIN: %u\n",TIMER_MIN);
	printf("RESET GREEN LED 0 MAX: %u\n",TIMER_MAX);

	return 0;
}
