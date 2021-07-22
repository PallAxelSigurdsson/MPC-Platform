/* DESCRIPTION:
 * This file holds global information for the whole MPC system. This is required because
 * some functions (mainly FIFO functions) must be initialized with all FIFO information
 * present (which is not present to all cpu's in their 'system.h' files). This file also
 * declares useful datatypes and definitions, used MPC function declarations.
 * This is the central 'system.h' file.
*/

#ifndef INFO_H
#define INFO_H

#include "altera_avalon_mutex.h"

#define CPU_0 0
#define CPU_1 1
#define CPU_2 2
#define CPU_3 3
#define CPU_4 4
#define CPU_5 5
#define CPU_6 6
#define CPU_7 7

#define CORE_COUNT 8

#define STATE_WAITING		1		/* Definition of the WAIT state for tasks */
#define STATE_READY			0		/* Definition of the READY state for tasks */

/* Structure for holding all mutexes in the MPC system */
typedef struct { 
    alt_mutex_dev* MUTEX_0; 
	alt_mutex_dev* MUTEX_1; 
	alt_mutex_dev* MUTEX_2; 
	alt_mutex_dev* MUTEX_3; 
	alt_mutex_dev* MUTEX_4; 
	alt_mutex_dev* MUTEX_5; 
} MPC_MUTEXLIST; 

// The Task Control Block (TCB) holding all information on each process.
typedef struct {
	alt_u8	PID;                   	/* ID of the proces, a simple integer */
	alt_u8	PRIO;                  	/* process priority, lower number --> higher priority */
	void	(*FTPR)();      		/* pointer to the process function, simply the name of the process */
	alt_u8	STATE;					/* The state of the process, can be WAIT or READY */
	int		PERIOD;					/* The period of the process in ms, sets deadline for the process*/
	int		LAUNCH;					/* Time of the last launch of the process, initialize to 0 (all processes are released at time 0) */

	int		(*WAKEUP)();			/* The pointer to the triggering function of a non-periodic task. Set to 0 if task is periodic */
	alt_u8	ONESHOT;				/* Tells the scheduler if the non-periodic task should run once (rising edge) or continuously at trigger level */
	alt_u8	SHOTHISTORY;			/* Variabble needed for history tracking if ONESHOT is active (set to 1). This variable should be initialized to 0 */
} TCB;


/********************/
/* system.h - CPU 0 */
/********************/

/*
 * timer_0_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0_0 altera_avalon_timer
#define TIMER_0_0_ALWAYS_RUN 0
#define TIMER_0_0_BASE 0x12a0
#define TIMER_0_0_COUNTER_SIZE 32
#define TIMER_0_0_FIXED_PERIOD 0
#define TIMER_0_0_FREQ 50000000
#define TIMER_0_0_IRQ 0
#define TIMER_0_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_0_LOAD_VALUE 49999
#define TIMER_0_0_MULT 0.0010
#define TIMER_0_0_NAME "/dev/timer_0_0"
#define TIMER_0_0_PERIOD 1
#define TIMER_0_0_PERIOD_UNITS "ms"
#define TIMER_0_0_RESET_OUTPUT 0
#define TIMER_0_0_SNAPSHOT 1
#define TIMER_0_0_SPAN 32
#define TIMER_0_0_TICKS_PER_SEC 1000.0
#define TIMER_0_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_0_TYPE "altera_avalon_timer"


/*
 * timer_0_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0_1 altera_avalon_timer
#define TIMER_0_1_ALWAYS_RUN 0
#define TIMER_0_1_BASE 0x10a0
#define TIMER_0_1_COUNTER_SIZE 32
#define TIMER_0_1_FIXED_PERIOD 0
#define TIMER_0_1_FREQ 50000000
#define TIMER_0_1_IRQ 1
#define TIMER_0_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_1_LOAD_VALUE 49999
#define TIMER_0_1_MULT 0.0010
#define TIMER_0_1_NAME "/dev/timer_0_1"
#define TIMER_0_1_PERIOD 1
#define TIMER_0_1_PERIOD_UNITS "ms"
#define TIMER_0_1_RESET_OUTPUT 0
#define TIMER_0_1_SNAPSHOT 1
#define TIMER_0_1_SPAN 32
#define TIMER_0_1_TICKS_PER_SEC 1000.0
#define TIMER_0_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_1_TYPE "altera_avalon_timer"

/********************/
/* system.h - CPU 1 */
/********************/

/*
 * timer_1_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_1_0 altera_avalon_timer
#define TIMER_1_0_ALWAYS_RUN 0
#define TIMER_1_0_BASE 0x12a0
#define TIMER_1_0_COUNTER_SIZE 32
#define TIMER_1_0_FIXED_PERIOD 0
#define TIMER_1_0_FREQ 50000000
#define TIMER_1_0_IRQ 0
#define TIMER_1_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_1_0_LOAD_VALUE 49999
#define TIMER_1_0_MULT 0.0010
#define TIMER_1_0_NAME "/dev/timer_1_0"
#define TIMER_1_0_PERIOD 1
#define TIMER_1_0_PERIOD_UNITS "ms"
#define TIMER_1_0_RESET_OUTPUT 0
#define TIMER_1_0_SNAPSHOT 1
#define TIMER_1_0_SPAN 32
#define TIMER_1_0_TICKS_PER_SEC 1000.0
#define TIMER_1_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_1_0_TYPE "altera_avalon_timer"


/*
 * timer_1_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_1_1 altera_avalon_timer
#define TIMER_1_1_ALWAYS_RUN 0
#define TIMER_1_1_BASE 0x10a0
#define TIMER_1_1_COUNTER_SIZE 32
#define TIMER_1_1_FIXED_PERIOD 0
#define TIMER_1_1_FREQ 50000000
#define TIMER_1_1_IRQ 1
#define TIMER_1_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_1_1_LOAD_VALUE 49999
#define TIMER_1_1_MULT 0.0010
#define TIMER_1_1_NAME "/dev/timer_1_1"
#define TIMER_1_1_PERIOD 1
#define TIMER_1_1_PERIOD_UNITS "ms"
#define TIMER_1_1_RESET_OUTPUT 0
#define TIMER_1_1_SNAPSHOT 1
#define TIMER_1_1_SPAN 32
#define TIMER_1_1_TICKS_PER_SEC 1000.0
#define TIMER_1_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_1_1_TYPE "altera_avalon_timer"



/********************/
/* system.h - CPU 2 */
/********************/


/*
 * timer_2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_2_0 altera_avalon_timer
#define TIMER_2_0_ALWAYS_RUN 0
#define TIMER_2_0_BASE 0x12a0
#define TIMER_2_0_COUNTER_SIZE 32
#define TIMER_2_0_FIXED_PERIOD 0
#define TIMER_2_0_FREQ 50000000
#define TIMER_2_0_IRQ 0
#define TIMER_2_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_2_0_LOAD_VALUE 49999
#define TIMER_2_0_MULT 0.0010
#define TIMER_2_0_NAME "/dev/timer_2_0"
#define TIMER_2_0_PERIOD 1
#define TIMER_2_0_PERIOD_UNITS "ms"
#define TIMER_2_0_RESET_OUTPUT 0
#define TIMER_2_0_SNAPSHOT 1
#define TIMER_2_0_SPAN 32
#define TIMER_2_0_TICKS_PER_SEC 1000.0
#define TIMER_2_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_2_0_TYPE "altera_avalon_timer"


/*
 * timer_2_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_2_1 altera_avalon_timer
#define TIMER_2_1_ALWAYS_RUN 0
#define TIMER_2_1_BASE 0x10a0
#define TIMER_2_1_COUNTER_SIZE 32
#define TIMER_2_1_FIXED_PERIOD 0
#define TIMER_2_1_FREQ 50000000
#define TIMER_2_1_IRQ 1
#define TIMER_2_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_2_1_LOAD_VALUE 49999
#define TIMER_2_1_MULT 0.0010
#define TIMER_2_1_NAME "/dev/timer_2_1"
#define TIMER_2_1_PERIOD 1
#define TIMER_2_1_PERIOD_UNITS "ms"
#define TIMER_2_1_RESET_OUTPUT 0
#define TIMER_2_1_SNAPSHOT 1
#define TIMER_2_1_SPAN 32
#define TIMER_2_1_TICKS_PER_SEC 1000.0
#define TIMER_2_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_2_1_TYPE "altera_avalon_timer"


/********************/
/* system.h - CPU 3 */
/********************/

/*
 * timer_3_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_3_0 altera_avalon_timer
#define TIMER_3_0_ALWAYS_RUN 0
#define TIMER_3_0_BASE 0x12a0
#define TIMER_3_0_COUNTER_SIZE 32
#define TIMER_3_0_FIXED_PERIOD 0
#define TIMER_3_0_FREQ 50000000
#define TIMER_3_0_IRQ 0
#define TIMER_3_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_3_0_LOAD_VALUE 49999
#define TIMER_3_0_MULT 0.0010
#define TIMER_3_0_NAME "/dev/timer_3_0"
#define TIMER_3_0_PERIOD 1
#define TIMER_3_0_PERIOD_UNITS "ms"
#define TIMER_3_0_RESET_OUTPUT 0
#define TIMER_3_0_SNAPSHOT 1
#define TIMER_3_0_SPAN 32
#define TIMER_3_0_TICKS_PER_SEC 1000.0
#define TIMER_3_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_3_0_TYPE "altera_avalon_timer"


/*
 * timer_3_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_3_1 altera_avalon_timer
#define TIMER_3_1_ALWAYS_RUN 0
#define TIMER_3_1_BASE 0x10a0
#define TIMER_3_1_COUNTER_SIZE 32
#define TIMER_3_1_FIXED_PERIOD 0
#define TIMER_3_1_FREQ 50000000
#define TIMER_3_1_IRQ 1
#define TIMER_3_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_3_1_LOAD_VALUE 49999
#define TIMER_3_1_MULT 0.0010
#define TIMER_3_1_NAME "/dev/timer_3_1"
#define TIMER_3_1_PERIOD 1
#define TIMER_3_1_PERIOD_UNITS "ms"
#define TIMER_3_1_RESET_OUTPUT 0
#define TIMER_3_1_SNAPSHOT 1
#define TIMER_3_1_SPAN 32
#define TIMER_3_1_TICKS_PER_SEC 1000.0
#define TIMER_3_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_3_1_TYPE "altera_avalon_timer"

/********************/
/* system.h - CPU 4 */
/********************/

/*
 * timer_4_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_4_0 altera_avalon_timer
#define TIMER_4_0_ALWAYS_RUN 0
#define TIMER_4_0_BASE 0x12a0
#define TIMER_4_0_COUNTER_SIZE 32
#define TIMER_4_0_FIXED_PERIOD 0
#define TIMER_4_0_FREQ 50000000
#define TIMER_4_0_IRQ 0
#define TIMER_4_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_4_0_LOAD_VALUE 49999
#define TIMER_4_0_MULT 0.0010
#define TIMER_4_0_NAME "/dev/timer_4_0"
#define TIMER_4_0_PERIOD 1
#define TIMER_4_0_PERIOD_UNITS "ms"
#define TIMER_4_0_RESET_OUTPUT 0
#define TIMER_4_0_SNAPSHOT 1
#define TIMER_4_0_SPAN 32
#define TIMER_4_0_TICKS_PER_SEC 1000.0
#define TIMER_4_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_4_0_TYPE "altera_avalon_timer"


/*
 * timer_4_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_4_1 altera_avalon_timer
#define TIMER_4_1_ALWAYS_RUN 0
#define TIMER_4_1_BASE 0x10a0
#define TIMER_4_1_COUNTER_SIZE 32
#define TIMER_4_1_FIXED_PERIOD 0
#define TIMER_4_1_FREQ 50000000
#define TIMER_4_1_IRQ 1
#define TIMER_4_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_4_1_LOAD_VALUE 49999
#define TIMER_4_1_MULT 0.0010
#define TIMER_4_1_NAME "/dev/timer_4_1"
#define TIMER_4_1_PERIOD 1
#define TIMER_4_1_PERIOD_UNITS "ms"
#define TIMER_4_1_RESET_OUTPUT 0
#define TIMER_4_1_SNAPSHOT 1
#define TIMER_4_1_SPAN 32
#define TIMER_4_1_TICKS_PER_SEC 1000.0
#define TIMER_4_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_4_1_TYPE "altera_avalon_timer"


/********************/
/* system.h - CPU 5 */
/********************/

/*
 * timer_5_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_5_0 altera_avalon_timer
#define TIMER_5_0_ALWAYS_RUN 0
#define TIMER_5_0_BASE 0x12a0
#define TIMER_5_0_COUNTER_SIZE 32
#define TIMER_5_0_FIXED_PERIOD 0
#define TIMER_5_0_FREQ 50000000
#define TIMER_5_0_IRQ 0
#define TIMER_5_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_5_0_LOAD_VALUE 49999
#define TIMER_5_0_MULT 0.0010
#define TIMER_5_0_NAME "/dev/timer_5_0"
#define TIMER_5_0_PERIOD 1
#define TIMER_5_0_PERIOD_UNITS "ms"
#define TIMER_5_0_RESET_OUTPUT 0
#define TIMER_5_0_SNAPSHOT 1
#define TIMER_5_0_SPAN 32
#define TIMER_5_0_TICKS_PER_SEC 1000.0
#define TIMER_5_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_5_0_TYPE "altera_avalon_timer"


/*
 * timer_5_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_5_1 altera_avalon_timer
#define TIMER_5_1_ALWAYS_RUN 0
#define TIMER_5_1_BASE 0x10a0
#define TIMER_5_1_COUNTER_SIZE 32
#define TIMER_5_1_FIXED_PERIOD 0
#define TIMER_5_1_FREQ 50000000
#define TIMER_5_1_IRQ 1
#define TIMER_5_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_5_1_LOAD_VALUE 49999
#define TIMER_5_1_MULT 0.0010
#define TIMER_5_1_NAME "/dev/timer_5_1"
#define TIMER_5_1_PERIOD 1
#define TIMER_5_1_PERIOD_UNITS "ms"
#define TIMER_5_1_RESET_OUTPUT 0
#define TIMER_5_1_SNAPSHOT 1
#define TIMER_5_1_SPAN 32
#define TIMER_5_1_TICKS_PER_SEC 1000.0
#define TIMER_5_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_5_1_TYPE "altera_avalon_timer"



/********************/
/* system.h - CPU 6 */
/********************/

/*
 * timer_6_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_6_0 altera_avalon_timer
#define TIMER_6_0_ALWAYS_RUN 0
#define TIMER_6_0_BASE 0x12a0
#define TIMER_6_0_COUNTER_SIZE 32
#define TIMER_6_0_FIXED_PERIOD 0
#define TIMER_6_0_FREQ 50000000
#define TIMER_6_0_IRQ 0
#define TIMER_6_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_6_0_LOAD_VALUE 49999
#define TIMER_6_0_MULT 0.0010
#define TIMER_6_0_NAME "/dev/timer_6_0"
#define TIMER_6_0_PERIOD 1
#define TIMER_6_0_PERIOD_UNITS "ms"
#define TIMER_6_0_RESET_OUTPUT 0
#define TIMER_6_0_SNAPSHOT 1
#define TIMER_6_0_SPAN 32
#define TIMER_6_0_TICKS_PER_SEC 1000.0
#define TIMER_6_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_6_0_TYPE "altera_avalon_timer"


/*
 * timer_6_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_6_1 altera_avalon_timer
#define TIMER_6_1_ALWAYS_RUN 0
#define TIMER_6_1_BASE 0x10a0
#define TIMER_6_1_COUNTER_SIZE 32
#define TIMER_6_1_FIXED_PERIOD 0
#define TIMER_6_1_FREQ 50000000
#define TIMER_6_1_IRQ 1
#define TIMER_6_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_6_1_LOAD_VALUE 49999
#define TIMER_6_1_MULT 0.0010
#define TIMER_6_1_NAME "/dev/timer_6_1"
#define TIMER_6_1_PERIOD 1
#define TIMER_6_1_PERIOD_UNITS "ms"
#define TIMER_6_1_RESET_OUTPUT 0
#define TIMER_6_1_SNAPSHOT 1
#define TIMER_6_1_SPAN 32
#define TIMER_6_1_TICKS_PER_SEC 1000.0
#define TIMER_6_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_6_1_TYPE "altera_avalon_timer"


/********************/
/* system.h - CPU 7 */
/********************/

/*
 * timer_7_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_7_0 altera_avalon_timer
#define TIMER_7_0_ALWAYS_RUN 0
#define TIMER_7_0_BASE 0x12a0
#define TIMER_7_0_COUNTER_SIZE 32
#define TIMER_7_0_FIXED_PERIOD 0
#define TIMER_7_0_FREQ 50000000
#define TIMER_7_0_IRQ 0
#define TIMER_7_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_7_0_LOAD_VALUE 49999
#define TIMER_7_0_MULT 0.0010
#define TIMER_7_0_NAME "/dev/timer_7_0"
#define TIMER_7_0_PERIOD 1
#define TIMER_7_0_PERIOD_UNITS "ms"
#define TIMER_7_0_RESET_OUTPUT 0
#define TIMER_7_0_SNAPSHOT 1
#define TIMER_7_0_SPAN 32
#define TIMER_7_0_TICKS_PER_SEC 1000.0
#define TIMER_7_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_7_0_TYPE "altera_avalon_timer"


/*
 * timer_7_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_7_1 altera_avalon_timer
#define TIMER_7_1_ALWAYS_RUN 0
#define TIMER_7_1_BASE 0x10a0
#define TIMER_7_1_COUNTER_SIZE 32
#define TIMER_7_1_FIXED_PERIOD 0
#define TIMER_7_1_FREQ 50000000
#define TIMER_7_1_IRQ 1
#define TIMER_7_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_7_1_LOAD_VALUE 49999
#define TIMER_7_1_MULT 0.0010
#define TIMER_7_1_NAME "/dev/timer_7_1"
#define TIMER_7_1_PERIOD 1
#define TIMER_7_1_PERIOD_UNITS "ms"
#define TIMER_7_1_RESET_OUTPUT 0
#define TIMER_7_1_SNAPSHOT 1
#define TIMER_7_1_SPAN 32
#define TIMER_7_1_TICKS_PER_SEC 1000.0
#define TIMER_7_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_7_1_TYPE "altera_avalon_timer"





/********************/
/* FIFO INFORMATION */
/********************/


/********************/
/* system.h - CPU 0 */
/********************/

/*
 * fifo_0_to_1_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_1_in altera_avalon_fifo
#define FIFO_0_TO_1_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_1_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_1_IN_BASE 0x135c
#define FIFO_0_TO_1_IN_BITS_PER_SYMBOL 16
#define FIFO_0_TO_1_IN_CHANNEL_WIDTH 8
#define FIFO_0_TO_1_IN_ERROR_WIDTH 8
#define FIFO_0_TO_1_IN_FIFO_DEPTH 16
#define FIFO_0_TO_1_IN_IRQ -1
#define FIFO_0_TO_1_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_1_IN_NAME "/dev/fifo_0_to_1_in"
#define FIFO_0_TO_1_IN_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_1_IN_SPAN 4
#define FIFO_0_TO_1_IN_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_1_IN_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_1_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_1_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_1_IN_USE_AVALONST_SINK 0
#define FIFO_0_TO_1_IN_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_1_IN_USE_BACKPRESSURE 1
#define FIFO_0_TO_1_IN_USE_IRQ 0
#define FIFO_0_TO_1_IN_USE_PACKET 1
#define FIFO_0_TO_1_IN_USE_READ_CONTROL 1
#define FIFO_0_TO_1_IN_USE_REGISTER 0
#define FIFO_0_TO_1_IN_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_1_in_csr altera_avalon_fifo
#define FIFO_0_TO_1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_1_IN_CSR_BASE 0x1280
#define FIFO_0_TO_1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_1_IN_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_1_IN_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_1_IN_CSR_IRQ -1
#define FIFO_0_TO_1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_1_IN_CSR_NAME "/dev/fifo_0_to_1_in_csr"
#define FIFO_0_TO_1_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_1_IN_CSR_SPAN 32
#define FIFO_0_TO_1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_1_IN_CSR_USE_IRQ 0
#define FIFO_0_TO_1_IN_CSR_USE_PACKET 1
#define FIFO_0_TO_1_IN_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_1_IN_CSR_USE_REGISTER 0
#define FIFO_0_TO_1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_2_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_2_in altera_avalon_fifo
#define FIFO_0_TO_2_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_2_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_2_IN_BASE 0x1358
#define FIFO_0_TO_2_IN_BITS_PER_SYMBOL 16
#define FIFO_0_TO_2_IN_CHANNEL_WIDTH 8
#define FIFO_0_TO_2_IN_ERROR_WIDTH 8
#define FIFO_0_TO_2_IN_FIFO_DEPTH 16
#define FIFO_0_TO_2_IN_IRQ -1
#define FIFO_0_TO_2_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_2_IN_NAME "/dev/fifo_0_to_2_in"
#define FIFO_0_TO_2_IN_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_2_IN_SPAN 4
#define FIFO_0_TO_2_IN_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_2_IN_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_2_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_2_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_2_IN_USE_AVALONST_SINK 0
#define FIFO_0_TO_2_IN_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_2_IN_USE_BACKPRESSURE 1
#define FIFO_0_TO_2_IN_USE_IRQ 0
#define FIFO_0_TO_2_IN_USE_PACKET 1
#define FIFO_0_TO_2_IN_USE_READ_CONTROL 1
#define FIFO_0_TO_2_IN_USE_REGISTER 0
#define FIFO_0_TO_2_IN_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_2_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_2_in_csr altera_avalon_fifo
#define FIFO_0_TO_2_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_2_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_2_IN_CSR_BASE 0x1260
#define FIFO_0_TO_2_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_2_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_2_IN_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_2_IN_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_2_IN_CSR_IRQ -1
#define FIFO_0_TO_2_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_2_IN_CSR_NAME "/dev/fifo_0_to_2_in_csr"
#define FIFO_0_TO_2_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_2_IN_CSR_SPAN 32
#define FIFO_0_TO_2_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_2_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_2_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_2_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_2_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_2_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_2_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_2_IN_CSR_USE_IRQ 0
#define FIFO_0_TO_2_IN_CSR_USE_PACKET 1
#define FIFO_0_TO_2_IN_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_2_IN_CSR_USE_REGISTER 0
#define FIFO_0_TO_2_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_3_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_3_in altera_avalon_fifo
#define FIFO_0_TO_3_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_3_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_3_IN_BASE 0x1354
#define FIFO_0_TO_3_IN_BITS_PER_SYMBOL 16
#define FIFO_0_TO_3_IN_CHANNEL_WIDTH 8
#define FIFO_0_TO_3_IN_ERROR_WIDTH 8
#define FIFO_0_TO_3_IN_FIFO_DEPTH 16
#define FIFO_0_TO_3_IN_IRQ -1
#define FIFO_0_TO_3_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_3_IN_NAME "/dev/fifo_0_to_3_in"
#define FIFO_0_TO_3_IN_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_3_IN_SPAN 4
#define FIFO_0_TO_3_IN_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_3_IN_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_3_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_3_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_3_IN_USE_AVALONST_SINK 0
#define FIFO_0_TO_3_IN_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_3_IN_USE_BACKPRESSURE 1
#define FIFO_0_TO_3_IN_USE_IRQ 0
#define FIFO_0_TO_3_IN_USE_PACKET 1
#define FIFO_0_TO_3_IN_USE_READ_CONTROL 1
#define FIFO_0_TO_3_IN_USE_REGISTER 0
#define FIFO_0_TO_3_IN_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_3_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_3_in_csr altera_avalon_fifo
#define FIFO_0_TO_3_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_3_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_3_IN_CSR_BASE 0x1240
#define FIFO_0_TO_3_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_3_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_3_IN_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_3_IN_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_3_IN_CSR_IRQ -1
#define FIFO_0_TO_3_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_3_IN_CSR_NAME "/dev/fifo_0_to_3_in_csr"
#define FIFO_0_TO_3_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_3_IN_CSR_SPAN 32
#define FIFO_0_TO_3_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_3_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_3_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_3_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_3_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_3_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_3_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_3_IN_CSR_USE_IRQ 0
#define FIFO_0_TO_3_IN_CSR_USE_PACKET 1
#define FIFO_0_TO_3_IN_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_3_IN_CSR_USE_REGISTER 0
#define FIFO_0_TO_3_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_4_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_4_in altera_avalon_fifo
#define FIFO_0_TO_4_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_4_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_4_IN_BASE 0x1344
#define FIFO_0_TO_4_IN_BITS_PER_SYMBOL 16
#define FIFO_0_TO_4_IN_CHANNEL_WIDTH 8
#define FIFO_0_TO_4_IN_ERROR_WIDTH 8
#define FIFO_0_TO_4_IN_FIFO_DEPTH 16
#define FIFO_0_TO_4_IN_IRQ -1
#define FIFO_0_TO_4_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_4_IN_NAME "/dev/fifo_0_to_4_in"
#define FIFO_0_TO_4_IN_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_4_IN_SPAN 4
#define FIFO_0_TO_4_IN_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_4_IN_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_4_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_4_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_4_IN_USE_AVALONST_SINK 0
#define FIFO_0_TO_4_IN_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_4_IN_USE_BACKPRESSURE 1
#define FIFO_0_TO_4_IN_USE_IRQ 0
#define FIFO_0_TO_4_IN_USE_PACKET 1
#define FIFO_0_TO_4_IN_USE_READ_CONTROL 1
#define FIFO_0_TO_4_IN_USE_REGISTER 0
#define FIFO_0_TO_4_IN_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_4_in_csr altera_avalon_fifo
#define FIFO_0_TO_4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_4_IN_CSR_BASE 0x11a0
#define FIFO_0_TO_4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_4_IN_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_4_IN_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_4_IN_CSR_IRQ -1
#define FIFO_0_TO_4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_4_IN_CSR_NAME "/dev/fifo_0_to_4_in_csr"
#define FIFO_0_TO_4_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_4_IN_CSR_SPAN 32
#define FIFO_0_TO_4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_4_IN_CSR_USE_IRQ 0
#define FIFO_0_TO_4_IN_CSR_USE_PACKET 1
#define FIFO_0_TO_4_IN_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_4_IN_CSR_USE_REGISTER 0
#define FIFO_0_TO_4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_5_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_5_in altera_avalon_fifo
#define FIFO_0_TO_5_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_5_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_5_IN_BASE 0x1340
#define FIFO_0_TO_5_IN_BITS_PER_SYMBOL 16
#define FIFO_0_TO_5_IN_CHANNEL_WIDTH 8
#define FIFO_0_TO_5_IN_ERROR_WIDTH 8
#define FIFO_0_TO_5_IN_FIFO_DEPTH 16
#define FIFO_0_TO_5_IN_IRQ -1
#define FIFO_0_TO_5_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_5_IN_NAME "/dev/fifo_0_to_5_in"
#define FIFO_0_TO_5_IN_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_5_IN_SPAN 4
#define FIFO_0_TO_5_IN_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_5_IN_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_5_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_5_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_5_IN_USE_AVALONST_SINK 0
#define FIFO_0_TO_5_IN_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_5_IN_USE_BACKPRESSURE 1
#define FIFO_0_TO_5_IN_USE_IRQ 0
#define FIFO_0_TO_5_IN_USE_PACKET 1
#define FIFO_0_TO_5_IN_USE_READ_CONTROL 1
#define FIFO_0_TO_5_IN_USE_REGISTER 0
#define FIFO_0_TO_5_IN_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_5_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_5_in_csr altera_avalon_fifo
#define FIFO_0_TO_5_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_5_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_5_IN_CSR_BASE 0x1180
#define FIFO_0_TO_5_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_5_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_5_IN_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_5_IN_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_5_IN_CSR_IRQ -1
#define FIFO_0_TO_5_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_5_IN_CSR_NAME "/dev/fifo_0_to_5_in_csr"
#define FIFO_0_TO_5_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_5_IN_CSR_SPAN 32
#define FIFO_0_TO_5_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_5_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_5_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_5_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_5_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_5_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_5_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_5_IN_CSR_USE_IRQ 0
#define FIFO_0_TO_5_IN_CSR_USE_PACKET 1
#define FIFO_0_TO_5_IN_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_5_IN_CSR_USE_REGISTER 0
#define FIFO_0_TO_5_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_6_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_6_in altera_avalon_fifo
#define FIFO_0_TO_6_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_6_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_6_IN_BASE 0x133c
#define FIFO_0_TO_6_IN_BITS_PER_SYMBOL 16
#define FIFO_0_TO_6_IN_CHANNEL_WIDTH 8
#define FIFO_0_TO_6_IN_ERROR_WIDTH 8
#define FIFO_0_TO_6_IN_FIFO_DEPTH 16
#define FIFO_0_TO_6_IN_IRQ -1
#define FIFO_0_TO_6_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_6_IN_NAME "/dev/fifo_0_to_6_in"
#define FIFO_0_TO_6_IN_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_6_IN_SPAN 4
#define FIFO_0_TO_6_IN_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_6_IN_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_6_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_6_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_6_IN_USE_AVALONST_SINK 0
#define FIFO_0_TO_6_IN_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_6_IN_USE_BACKPRESSURE 1
#define FIFO_0_TO_6_IN_USE_IRQ 0
#define FIFO_0_TO_6_IN_USE_PACKET 1
#define FIFO_0_TO_6_IN_USE_READ_CONTROL 1
#define FIFO_0_TO_6_IN_USE_REGISTER 0
#define FIFO_0_TO_6_IN_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_6_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_6_in_csr altera_avalon_fifo
#define FIFO_0_TO_6_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_6_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_6_IN_CSR_BASE 0x1160
#define FIFO_0_TO_6_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_6_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_6_IN_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_6_IN_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_6_IN_CSR_IRQ -1
#define FIFO_0_TO_6_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_6_IN_CSR_NAME "/dev/fifo_0_to_6_in_csr"
#define FIFO_0_TO_6_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_6_IN_CSR_SPAN 32
#define FIFO_0_TO_6_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_6_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_6_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_6_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_6_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_6_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_6_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_6_IN_CSR_USE_IRQ 0
#define FIFO_0_TO_6_IN_CSR_USE_PACKET 1
#define FIFO_0_TO_6_IN_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_6_IN_CSR_USE_REGISTER 0
#define FIFO_0_TO_6_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_7_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_7_in altera_avalon_fifo
#define FIFO_0_TO_7_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_7_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_7_IN_BASE 0x1338
#define FIFO_0_TO_7_IN_BITS_PER_SYMBOL 16
#define FIFO_0_TO_7_IN_CHANNEL_WIDTH 8
#define FIFO_0_TO_7_IN_ERROR_WIDTH 8
#define FIFO_0_TO_7_IN_FIFO_DEPTH 16
#define FIFO_0_TO_7_IN_IRQ -1
#define FIFO_0_TO_7_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_7_IN_NAME "/dev/fifo_0_to_7_in"
#define FIFO_0_TO_7_IN_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_7_IN_SPAN 4
#define FIFO_0_TO_7_IN_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_7_IN_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_7_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_7_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_7_IN_USE_AVALONST_SINK 0
#define FIFO_0_TO_7_IN_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_7_IN_USE_BACKPRESSURE 1
#define FIFO_0_TO_7_IN_USE_IRQ 0
#define FIFO_0_TO_7_IN_USE_PACKET 1
#define FIFO_0_TO_7_IN_USE_READ_CONTROL 1
#define FIFO_0_TO_7_IN_USE_REGISTER 0
#define FIFO_0_TO_7_IN_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_7_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_7_in_csr altera_avalon_fifo
#define FIFO_0_TO_7_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_7_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_7_IN_CSR_BASE 0x1140
#define FIFO_0_TO_7_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_7_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_7_IN_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_7_IN_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_7_IN_CSR_IRQ -1
#define FIFO_0_TO_7_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_7_IN_CSR_NAME "/dev/fifo_0_to_7_in_csr"
#define FIFO_0_TO_7_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_7_IN_CSR_SPAN 32
#define FIFO_0_TO_7_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_7_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_7_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_7_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_7_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_7_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_7_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_7_IN_CSR_USE_IRQ 0
#define FIFO_0_TO_7_IN_CSR_USE_PACKET 1
#define FIFO_0_TO_7_IN_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_7_IN_CSR_USE_REGISTER 0
#define FIFO_0_TO_7_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_0_out altera_avalon_fifo
#define FIFO_1_TO_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_0_OUT_BASE 0x1350
#define FIFO_1_TO_0_OUT_BITS_PER_SYMBOL 16
#define FIFO_1_TO_0_OUT_CHANNEL_WIDTH 8
#define FIFO_1_TO_0_OUT_ERROR_WIDTH 8
#define FIFO_1_TO_0_OUT_FIFO_DEPTH 16
#define FIFO_1_TO_0_OUT_IRQ -1
#define FIFO_1_TO_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_0_OUT_NAME "/dev/fifo_1_to_0_out"
#define FIFO_1_TO_0_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_0_OUT_SPAN 4
#define FIFO_1_TO_0_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_0_OUT_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_0_OUT_USE_AVALONST_SINK 0
#define FIFO_1_TO_0_OUT_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_0_OUT_USE_BACKPRESSURE 1
#define FIFO_1_TO_0_OUT_USE_IRQ 0
#define FIFO_1_TO_0_OUT_USE_PACKET 1
#define FIFO_1_TO_0_OUT_USE_READ_CONTROL 1
#define FIFO_1_TO_0_OUT_USE_REGISTER 0
#define FIFO_1_TO_0_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_0_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_0_out_csr altera_avalon_fifo
#define FIFO_1_TO_0_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_0_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_0_OUT_CSR_BASE 0x1220
#define FIFO_1_TO_0_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_0_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_0_OUT_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_0_OUT_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_0_OUT_CSR_IRQ -1
#define FIFO_1_TO_0_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_0_OUT_CSR_NAME "/dev/fifo_1_to_0_out_csr"
#define FIFO_1_TO_0_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_0_OUT_CSR_SPAN 32
#define FIFO_1_TO_0_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_0_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_0_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_0_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_0_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_0_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_0_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_0_OUT_CSR_USE_IRQ 0
#define FIFO_1_TO_0_OUT_CSR_USE_PACKET 1
#define FIFO_1_TO_0_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_0_OUT_CSR_USE_REGISTER 0
#define FIFO_1_TO_0_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_0_out altera_avalon_fifo
#define FIFO_2_TO_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_0_OUT_BASE 0x134c
#define FIFO_2_TO_0_OUT_BITS_PER_SYMBOL 16
#define FIFO_2_TO_0_OUT_CHANNEL_WIDTH 8
#define FIFO_2_TO_0_OUT_ERROR_WIDTH 8
#define FIFO_2_TO_0_OUT_FIFO_DEPTH 16
#define FIFO_2_TO_0_OUT_IRQ -1
#define FIFO_2_TO_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_0_OUT_NAME "/dev/fifo_2_to_0_out"
#define FIFO_2_TO_0_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_0_OUT_SPAN 4
#define FIFO_2_TO_0_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_0_OUT_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_0_OUT_USE_AVALONST_SINK 0
#define FIFO_2_TO_0_OUT_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_0_OUT_USE_BACKPRESSURE 1
#define FIFO_2_TO_0_OUT_USE_IRQ 0
#define FIFO_2_TO_0_OUT_USE_PACKET 1
#define FIFO_2_TO_0_OUT_USE_READ_CONTROL 1
#define FIFO_2_TO_0_OUT_USE_REGISTER 0
#define FIFO_2_TO_0_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_0_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_0_out_csr altera_avalon_fifo
#define FIFO_2_TO_0_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_0_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_0_OUT_CSR_BASE 0x1200
#define FIFO_2_TO_0_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_0_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_0_OUT_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_0_OUT_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_0_OUT_CSR_IRQ -1
#define FIFO_2_TO_0_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_0_OUT_CSR_NAME "/dev/fifo_2_to_0_out_csr"
#define FIFO_2_TO_0_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_0_OUT_CSR_SPAN 32
#define FIFO_2_TO_0_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_0_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_0_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_0_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_0_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_0_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_0_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_0_OUT_CSR_USE_IRQ 0
#define FIFO_2_TO_0_OUT_CSR_USE_PACKET 1
#define FIFO_2_TO_0_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_0_OUT_CSR_USE_REGISTER 0
#define FIFO_2_TO_0_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_0_out altera_avalon_fifo
#define FIFO_3_TO_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_0_OUT_BASE 0x1348
#define FIFO_3_TO_0_OUT_BITS_PER_SYMBOL 16
#define FIFO_3_TO_0_OUT_CHANNEL_WIDTH 8
#define FIFO_3_TO_0_OUT_ERROR_WIDTH 8
#define FIFO_3_TO_0_OUT_FIFO_DEPTH 16
#define FIFO_3_TO_0_OUT_IRQ -1
#define FIFO_3_TO_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_0_OUT_NAME "/dev/fifo_3_to_0_out"
#define FIFO_3_TO_0_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_0_OUT_SPAN 4
#define FIFO_3_TO_0_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_0_OUT_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_0_OUT_USE_AVALONST_SINK 0
#define FIFO_3_TO_0_OUT_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_0_OUT_USE_BACKPRESSURE 1
#define FIFO_3_TO_0_OUT_USE_IRQ 0
#define FIFO_3_TO_0_OUT_USE_PACKET 1
#define FIFO_3_TO_0_OUT_USE_READ_CONTROL 1
#define FIFO_3_TO_0_OUT_USE_REGISTER 0
#define FIFO_3_TO_0_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_0_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_0_out_csr altera_avalon_fifo
#define FIFO_3_TO_0_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_0_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_0_OUT_CSR_BASE 0x11e0
#define FIFO_3_TO_0_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_0_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_0_OUT_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_0_OUT_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_0_OUT_CSR_IRQ -1
#define FIFO_3_TO_0_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_0_OUT_CSR_NAME "/dev/fifo_3_to_0_out_csr"
#define FIFO_3_TO_0_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_0_OUT_CSR_SPAN 32
#define FIFO_3_TO_0_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_0_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_0_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_0_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_0_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_0_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_0_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_0_OUT_CSR_USE_IRQ 0
#define FIFO_3_TO_0_OUT_CSR_USE_PACKET 1
#define FIFO_3_TO_0_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_0_OUT_CSR_USE_REGISTER 0
#define FIFO_3_TO_0_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_0_out altera_avalon_fifo
#define FIFO_4_TO_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_0_OUT_BASE 0x1334
#define FIFO_4_TO_0_OUT_BITS_PER_SYMBOL 16
#define FIFO_4_TO_0_OUT_CHANNEL_WIDTH 8
#define FIFO_4_TO_0_OUT_ERROR_WIDTH 8
#define FIFO_4_TO_0_OUT_FIFO_DEPTH 16
#define FIFO_4_TO_0_OUT_IRQ -1
#define FIFO_4_TO_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_0_OUT_NAME "/dev/fifo_4_to_0_out"
#define FIFO_4_TO_0_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_0_OUT_SPAN 4
#define FIFO_4_TO_0_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_0_OUT_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_0_OUT_USE_AVALONST_SINK 0
#define FIFO_4_TO_0_OUT_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_0_OUT_USE_BACKPRESSURE 1
#define FIFO_4_TO_0_OUT_USE_IRQ 0
#define FIFO_4_TO_0_OUT_USE_PACKET 1
#define FIFO_4_TO_0_OUT_USE_READ_CONTROL 1
#define FIFO_4_TO_0_OUT_USE_REGISTER 0
#define FIFO_4_TO_0_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_0_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_0_out_csr altera_avalon_fifo
#define FIFO_4_TO_0_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_0_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_0_OUT_CSR_BASE 0x1120
#define FIFO_4_TO_0_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_0_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_0_OUT_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_0_OUT_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_0_OUT_CSR_IRQ -1
#define FIFO_4_TO_0_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_0_OUT_CSR_NAME "/dev/fifo_4_to_0_out_csr"
#define FIFO_4_TO_0_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_0_OUT_CSR_SPAN 32
#define FIFO_4_TO_0_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_0_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_0_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_0_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_0_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_0_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_0_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_0_OUT_CSR_USE_IRQ 0
#define FIFO_4_TO_0_OUT_CSR_USE_PACKET 1
#define FIFO_4_TO_0_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_0_OUT_CSR_USE_REGISTER 0
#define FIFO_4_TO_0_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_0_out altera_avalon_fifo
#define FIFO_5_TO_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_0_OUT_BASE 0x1330
#define FIFO_5_TO_0_OUT_BITS_PER_SYMBOL 16
#define FIFO_5_TO_0_OUT_CHANNEL_WIDTH 8
#define FIFO_5_TO_0_OUT_ERROR_WIDTH 8
#define FIFO_5_TO_0_OUT_FIFO_DEPTH 16
#define FIFO_5_TO_0_OUT_IRQ -1
#define FIFO_5_TO_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_0_OUT_NAME "/dev/fifo_5_to_0_out"
#define FIFO_5_TO_0_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_0_OUT_SPAN 4
#define FIFO_5_TO_0_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_0_OUT_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_0_OUT_USE_AVALONST_SINK 0
#define FIFO_5_TO_0_OUT_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_0_OUT_USE_BACKPRESSURE 1
#define FIFO_5_TO_0_OUT_USE_IRQ 0
#define FIFO_5_TO_0_OUT_USE_PACKET 1
#define FIFO_5_TO_0_OUT_USE_READ_CONTROL 1
#define FIFO_5_TO_0_OUT_USE_REGISTER 0
#define FIFO_5_TO_0_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_0_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_0_out_csr altera_avalon_fifo
#define FIFO_5_TO_0_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_0_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_0_OUT_CSR_BASE 0x1100
#define FIFO_5_TO_0_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_0_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_0_OUT_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_0_OUT_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_0_OUT_CSR_IRQ -1
#define FIFO_5_TO_0_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_0_OUT_CSR_NAME "/dev/fifo_5_to_0_out_csr"
#define FIFO_5_TO_0_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_0_OUT_CSR_SPAN 32
#define FIFO_5_TO_0_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_0_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_0_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_0_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_0_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_0_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_0_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_0_OUT_CSR_USE_IRQ 0
#define FIFO_5_TO_0_OUT_CSR_USE_PACKET 1
#define FIFO_5_TO_0_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_0_OUT_CSR_USE_REGISTER 0
#define FIFO_5_TO_0_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_0_out altera_avalon_fifo
#define FIFO_6_TO_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_0_OUT_BASE 0x132c
#define FIFO_6_TO_0_OUT_BITS_PER_SYMBOL 16
#define FIFO_6_TO_0_OUT_CHANNEL_WIDTH 8
#define FIFO_6_TO_0_OUT_ERROR_WIDTH 8
#define FIFO_6_TO_0_OUT_FIFO_DEPTH 16
#define FIFO_6_TO_0_OUT_IRQ -1
#define FIFO_6_TO_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_0_OUT_NAME "/dev/fifo_6_to_0_out"
#define FIFO_6_TO_0_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_0_OUT_SPAN 4
#define FIFO_6_TO_0_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_0_OUT_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_0_OUT_USE_AVALONST_SINK 0
#define FIFO_6_TO_0_OUT_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_0_OUT_USE_BACKPRESSURE 1
#define FIFO_6_TO_0_OUT_USE_IRQ 0
#define FIFO_6_TO_0_OUT_USE_PACKET 1
#define FIFO_6_TO_0_OUT_USE_READ_CONTROL 1
#define FIFO_6_TO_0_OUT_USE_REGISTER 0
#define FIFO_6_TO_0_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_0_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_0_out_csr altera_avalon_fifo
#define FIFO_6_TO_0_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_0_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_0_OUT_CSR_BASE 0x10e0
#define FIFO_6_TO_0_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_0_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_0_OUT_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_0_OUT_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_0_OUT_CSR_IRQ -1
#define FIFO_6_TO_0_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_0_OUT_CSR_NAME "/dev/fifo_6_to_0_out_csr"
#define FIFO_6_TO_0_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_0_OUT_CSR_SPAN 32
#define FIFO_6_TO_0_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_0_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_0_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_0_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_0_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_0_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_0_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_0_OUT_CSR_USE_IRQ 0
#define FIFO_6_TO_0_OUT_CSR_USE_PACKET 1
#define FIFO_6_TO_0_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_0_OUT_CSR_USE_REGISTER 0
#define FIFO_6_TO_0_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_0_out altera_avalon_fifo
#define FIFO_7_TO_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_0_OUT_BASE 0x1328
#define FIFO_7_TO_0_OUT_BITS_PER_SYMBOL 16
#define FIFO_7_TO_0_OUT_CHANNEL_WIDTH 8
#define FIFO_7_TO_0_OUT_ERROR_WIDTH 8
#define FIFO_7_TO_0_OUT_FIFO_DEPTH 16
#define FIFO_7_TO_0_OUT_IRQ -1
#define FIFO_7_TO_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_0_OUT_NAME "/dev/fifo_7_to_0_out"
#define FIFO_7_TO_0_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_0_OUT_SPAN 4
#define FIFO_7_TO_0_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_0_OUT_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_0_OUT_USE_AVALONST_SINK 0
#define FIFO_7_TO_0_OUT_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_0_OUT_USE_BACKPRESSURE 1
#define FIFO_7_TO_0_OUT_USE_IRQ 0
#define FIFO_7_TO_0_OUT_USE_PACKET 1
#define FIFO_7_TO_0_OUT_USE_READ_CONTROL 1
#define FIFO_7_TO_0_OUT_USE_REGISTER 0
#define FIFO_7_TO_0_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_0_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_0_out_csr altera_avalon_fifo
#define FIFO_7_TO_0_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_0_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_0_OUT_CSR_BASE 0x10c0
#define FIFO_7_TO_0_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_0_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_0_OUT_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_0_OUT_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_0_OUT_CSR_IRQ -1
#define FIFO_7_TO_0_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_0_OUT_CSR_NAME "/dev/fifo_7_to_0_out_csr"
#define FIFO_7_TO_0_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_0_OUT_CSR_SPAN 32
#define FIFO_7_TO_0_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_0_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_0_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_0_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_0_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_0_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_0_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_0_OUT_CSR_USE_IRQ 0
#define FIFO_7_TO_0_OUT_CSR_USE_PACKET 1
#define FIFO_7_TO_0_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_0_OUT_CSR_USE_REGISTER 0
#define FIFO_7_TO_0_OUT_CSR_USE_WRITE_CONTROL 1


/********************/
/* system.h - CPU 1 */
/********************/


/*
 * fifo_0_to_1_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_1_out altera_avalon_fifo
#define FIFO_0_TO_1_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_1_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_1_OUT_BASE 0x135c
#define FIFO_0_TO_1_OUT_BITS_PER_SYMBOL 16
#define FIFO_0_TO_1_OUT_CHANNEL_WIDTH 8
#define FIFO_0_TO_1_OUT_ERROR_WIDTH 8
#define FIFO_0_TO_1_OUT_FIFO_DEPTH 16
#define FIFO_0_TO_1_OUT_IRQ -1
#define FIFO_0_TO_1_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_1_OUT_NAME "/dev/fifo_0_to_1_out"
#define FIFO_0_TO_1_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_1_OUT_SPAN 4
#define FIFO_0_TO_1_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_1_OUT_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_1_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_1_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_1_OUT_USE_AVALONST_SINK 0
#define FIFO_0_TO_1_OUT_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_1_OUT_USE_BACKPRESSURE 1
#define FIFO_0_TO_1_OUT_USE_IRQ 0
#define FIFO_0_TO_1_OUT_USE_PACKET 1
#define FIFO_0_TO_1_OUT_USE_READ_CONTROL 1
#define FIFO_0_TO_1_OUT_USE_REGISTER 0
#define FIFO_0_TO_1_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_1_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_1_out_csr altera_avalon_fifo
#define FIFO_0_TO_1_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_1_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_1_OUT_CSR_BASE 0x1280
#define FIFO_0_TO_1_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_1_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_1_OUT_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_1_OUT_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_1_OUT_CSR_IRQ -1
#define FIFO_0_TO_1_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_1_OUT_CSR_NAME "/dev/fifo_0_to_1_out_csr"
#define FIFO_0_TO_1_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_1_OUT_CSR_SPAN 32
#define FIFO_0_TO_1_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_1_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_1_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_1_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_1_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_1_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_1_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_1_OUT_CSR_USE_IRQ 0
#define FIFO_0_TO_1_OUT_CSR_USE_PACKET 1
#define FIFO_0_TO_1_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_1_OUT_CSR_USE_REGISTER 0
#define FIFO_0_TO_1_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_0_in altera_avalon_fifo
#define FIFO_1_TO_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_0_IN_BASE 0x1358
#define FIFO_1_TO_0_IN_BITS_PER_SYMBOL 16
#define FIFO_1_TO_0_IN_CHANNEL_WIDTH 8
#define FIFO_1_TO_0_IN_ERROR_WIDTH 8
#define FIFO_1_TO_0_IN_FIFO_DEPTH 16
#define FIFO_1_TO_0_IN_IRQ -1
#define FIFO_1_TO_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_0_IN_NAME "/dev/fifo_1_to_0_in"
#define FIFO_1_TO_0_IN_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_0_IN_SPAN 4
#define FIFO_1_TO_0_IN_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_0_IN_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_0_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_0_IN_USE_AVALONST_SINK 0
#define FIFO_1_TO_0_IN_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_0_IN_USE_BACKPRESSURE 1
#define FIFO_1_TO_0_IN_USE_IRQ 0
#define FIFO_1_TO_0_IN_USE_PACKET 1
#define FIFO_1_TO_0_IN_USE_READ_CONTROL 1
#define FIFO_1_TO_0_IN_USE_REGISTER 0
#define FIFO_1_TO_0_IN_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_0_in_csr altera_avalon_fifo
#define FIFO_1_TO_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_0_IN_CSR_BASE 0x1260
#define FIFO_1_TO_0_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_0_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_0_IN_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_0_IN_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_0_IN_CSR_IRQ -1
#define FIFO_1_TO_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_0_IN_CSR_NAME "/dev/fifo_1_to_0_in_csr"
#define FIFO_1_TO_0_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_0_IN_CSR_SPAN 32
#define FIFO_1_TO_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_0_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_0_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_0_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_0_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_0_IN_CSR_USE_IRQ 0
#define FIFO_1_TO_0_IN_CSR_USE_PACKET 1
#define FIFO_1_TO_0_IN_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_0_IN_CSR_USE_REGISTER 0
#define FIFO_1_TO_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_2_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_2_in altera_avalon_fifo
#define FIFO_1_TO_2_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_2_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_2_IN_BASE 0x1354
#define FIFO_1_TO_2_IN_BITS_PER_SYMBOL 16
#define FIFO_1_TO_2_IN_CHANNEL_WIDTH 8
#define FIFO_1_TO_2_IN_ERROR_WIDTH 8
#define FIFO_1_TO_2_IN_FIFO_DEPTH 16
#define FIFO_1_TO_2_IN_IRQ -1
#define FIFO_1_TO_2_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_2_IN_NAME "/dev/fifo_1_to_2_in"
#define FIFO_1_TO_2_IN_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_2_IN_SPAN 4
#define FIFO_1_TO_2_IN_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_2_IN_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_2_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_2_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_2_IN_USE_AVALONST_SINK 0
#define FIFO_1_TO_2_IN_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_2_IN_USE_BACKPRESSURE 1
#define FIFO_1_TO_2_IN_USE_IRQ 0
#define FIFO_1_TO_2_IN_USE_PACKET 1
#define FIFO_1_TO_2_IN_USE_READ_CONTROL 1
#define FIFO_1_TO_2_IN_USE_REGISTER 0
#define FIFO_1_TO_2_IN_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_2_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_2_in_csr altera_avalon_fifo
#define FIFO_1_TO_2_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_2_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_2_IN_CSR_BASE 0x1240
#define FIFO_1_TO_2_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_2_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_2_IN_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_2_IN_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_2_IN_CSR_IRQ -1
#define FIFO_1_TO_2_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_2_IN_CSR_NAME "/dev/fifo_1_to_2_in_csr"
#define FIFO_1_TO_2_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_2_IN_CSR_SPAN 32
#define FIFO_1_TO_2_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_2_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_2_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_2_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_2_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_2_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_2_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_2_IN_CSR_USE_IRQ 0
#define FIFO_1_TO_2_IN_CSR_USE_PACKET 1
#define FIFO_1_TO_2_IN_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_2_IN_CSR_USE_REGISTER 0
#define FIFO_1_TO_2_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_3_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_3_in altera_avalon_fifo
#define FIFO_1_TO_3_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_3_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_3_IN_BASE 0x1350
#define FIFO_1_TO_3_IN_BITS_PER_SYMBOL 16
#define FIFO_1_TO_3_IN_CHANNEL_WIDTH 8
#define FIFO_1_TO_3_IN_ERROR_WIDTH 8
#define FIFO_1_TO_3_IN_FIFO_DEPTH 16
#define FIFO_1_TO_3_IN_IRQ -1
#define FIFO_1_TO_3_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_3_IN_NAME "/dev/fifo_1_to_3_in"
#define FIFO_1_TO_3_IN_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_3_IN_SPAN 4
#define FIFO_1_TO_3_IN_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_3_IN_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_3_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_3_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_3_IN_USE_AVALONST_SINK 0
#define FIFO_1_TO_3_IN_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_3_IN_USE_BACKPRESSURE 1
#define FIFO_1_TO_3_IN_USE_IRQ 0
#define FIFO_1_TO_3_IN_USE_PACKET 1
#define FIFO_1_TO_3_IN_USE_READ_CONTROL 1
#define FIFO_1_TO_3_IN_USE_REGISTER 0
#define FIFO_1_TO_3_IN_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_3_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_3_in_csr altera_avalon_fifo
#define FIFO_1_TO_3_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_3_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_3_IN_CSR_BASE 0x1220
#define FIFO_1_TO_3_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_3_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_3_IN_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_3_IN_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_3_IN_CSR_IRQ -1
#define FIFO_1_TO_3_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_3_IN_CSR_NAME "/dev/fifo_1_to_3_in_csr"
#define FIFO_1_TO_3_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_3_IN_CSR_SPAN 32
#define FIFO_1_TO_3_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_3_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_3_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_3_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_3_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_3_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_3_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_3_IN_CSR_USE_IRQ 0
#define FIFO_1_TO_3_IN_CSR_USE_PACKET 1
#define FIFO_1_TO_3_IN_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_3_IN_CSR_USE_REGISTER 0
#define FIFO_1_TO_3_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_4_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_4_in altera_avalon_fifo
#define FIFO_1_TO_4_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_4_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_4_IN_BASE 0x1344
#define FIFO_1_TO_4_IN_BITS_PER_SYMBOL 16
#define FIFO_1_TO_4_IN_CHANNEL_WIDTH 8
#define FIFO_1_TO_4_IN_ERROR_WIDTH 8
#define FIFO_1_TO_4_IN_FIFO_DEPTH 16
#define FIFO_1_TO_4_IN_IRQ -1
#define FIFO_1_TO_4_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_4_IN_NAME "/dev/fifo_1_to_4_in"
#define FIFO_1_TO_4_IN_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_4_IN_SPAN 4
#define FIFO_1_TO_4_IN_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_4_IN_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_4_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_4_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_4_IN_USE_AVALONST_SINK 0
#define FIFO_1_TO_4_IN_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_4_IN_USE_BACKPRESSURE 1
#define FIFO_1_TO_4_IN_USE_IRQ 0
#define FIFO_1_TO_4_IN_USE_PACKET 1
#define FIFO_1_TO_4_IN_USE_READ_CONTROL 1
#define FIFO_1_TO_4_IN_USE_REGISTER 0
#define FIFO_1_TO_4_IN_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_4_in_csr altera_avalon_fifo
#define FIFO_1_TO_4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_4_IN_CSR_BASE 0x11a0
#define FIFO_1_TO_4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_4_IN_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_4_IN_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_4_IN_CSR_IRQ -1
#define FIFO_1_TO_4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_4_IN_CSR_NAME "/dev/fifo_1_to_4_in_csr"
#define FIFO_1_TO_4_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_4_IN_CSR_SPAN 32
#define FIFO_1_TO_4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_4_IN_CSR_USE_IRQ 0
#define FIFO_1_TO_4_IN_CSR_USE_PACKET 1
#define FIFO_1_TO_4_IN_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_4_IN_CSR_USE_REGISTER 0
#define FIFO_1_TO_4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_5_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_5_in altera_avalon_fifo
#define FIFO_1_TO_5_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_5_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_5_IN_BASE 0x1340
#define FIFO_1_TO_5_IN_BITS_PER_SYMBOL 16
#define FIFO_1_TO_5_IN_CHANNEL_WIDTH 8
#define FIFO_1_TO_5_IN_ERROR_WIDTH 8
#define FIFO_1_TO_5_IN_FIFO_DEPTH 16
#define FIFO_1_TO_5_IN_IRQ -1
#define FIFO_1_TO_5_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_5_IN_NAME "/dev/fifo_1_to_5_in"
#define FIFO_1_TO_5_IN_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_5_IN_SPAN 4
#define FIFO_1_TO_5_IN_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_5_IN_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_5_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_5_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_5_IN_USE_AVALONST_SINK 0
#define FIFO_1_TO_5_IN_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_5_IN_USE_BACKPRESSURE 1
#define FIFO_1_TO_5_IN_USE_IRQ 0
#define FIFO_1_TO_5_IN_USE_PACKET 1
#define FIFO_1_TO_5_IN_USE_READ_CONTROL 1
#define FIFO_1_TO_5_IN_USE_REGISTER 0
#define FIFO_1_TO_5_IN_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_5_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_5_in_csr altera_avalon_fifo
#define FIFO_1_TO_5_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_5_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_5_IN_CSR_BASE 0x1180
#define FIFO_1_TO_5_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_5_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_5_IN_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_5_IN_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_5_IN_CSR_IRQ -1
#define FIFO_1_TO_5_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_5_IN_CSR_NAME "/dev/fifo_1_to_5_in_csr"
#define FIFO_1_TO_5_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_5_IN_CSR_SPAN 32
#define FIFO_1_TO_5_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_5_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_5_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_5_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_5_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_5_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_5_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_5_IN_CSR_USE_IRQ 0
#define FIFO_1_TO_5_IN_CSR_USE_PACKET 1
#define FIFO_1_TO_5_IN_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_5_IN_CSR_USE_REGISTER 0
#define FIFO_1_TO_5_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_6_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_6_in altera_avalon_fifo
#define FIFO_1_TO_6_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_6_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_6_IN_BASE 0x133c
#define FIFO_1_TO_6_IN_BITS_PER_SYMBOL 16
#define FIFO_1_TO_6_IN_CHANNEL_WIDTH 8
#define FIFO_1_TO_6_IN_ERROR_WIDTH 8
#define FIFO_1_TO_6_IN_FIFO_DEPTH 16
#define FIFO_1_TO_6_IN_IRQ -1
#define FIFO_1_TO_6_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_6_IN_NAME "/dev/fifo_1_to_6_in"
#define FIFO_1_TO_6_IN_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_6_IN_SPAN 4
#define FIFO_1_TO_6_IN_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_6_IN_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_6_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_6_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_6_IN_USE_AVALONST_SINK 0
#define FIFO_1_TO_6_IN_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_6_IN_USE_BACKPRESSURE 1
#define FIFO_1_TO_6_IN_USE_IRQ 0
#define FIFO_1_TO_6_IN_USE_PACKET 1
#define FIFO_1_TO_6_IN_USE_READ_CONTROL 1
#define FIFO_1_TO_6_IN_USE_REGISTER 0
#define FIFO_1_TO_6_IN_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_6_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_6_in_csr altera_avalon_fifo
#define FIFO_1_TO_6_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_6_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_6_IN_CSR_BASE 0x1160
#define FIFO_1_TO_6_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_6_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_6_IN_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_6_IN_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_6_IN_CSR_IRQ -1
#define FIFO_1_TO_6_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_6_IN_CSR_NAME "/dev/fifo_1_to_6_in_csr"
#define FIFO_1_TO_6_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_6_IN_CSR_SPAN 32
#define FIFO_1_TO_6_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_6_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_6_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_6_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_6_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_6_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_6_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_6_IN_CSR_USE_IRQ 0
#define FIFO_1_TO_6_IN_CSR_USE_PACKET 1
#define FIFO_1_TO_6_IN_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_6_IN_CSR_USE_REGISTER 0
#define FIFO_1_TO_6_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_7_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_7_in altera_avalon_fifo
#define FIFO_1_TO_7_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_7_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_7_IN_BASE 0x1338
#define FIFO_1_TO_7_IN_BITS_PER_SYMBOL 16
#define FIFO_1_TO_7_IN_CHANNEL_WIDTH 8
#define FIFO_1_TO_7_IN_ERROR_WIDTH 8
#define FIFO_1_TO_7_IN_FIFO_DEPTH 16
#define FIFO_1_TO_7_IN_IRQ -1
#define FIFO_1_TO_7_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_7_IN_NAME "/dev/fifo_1_to_7_in"
#define FIFO_1_TO_7_IN_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_7_IN_SPAN 4
#define FIFO_1_TO_7_IN_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_7_IN_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_7_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_7_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_7_IN_USE_AVALONST_SINK 0
#define FIFO_1_TO_7_IN_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_7_IN_USE_BACKPRESSURE 1
#define FIFO_1_TO_7_IN_USE_IRQ 0
#define FIFO_1_TO_7_IN_USE_PACKET 1
#define FIFO_1_TO_7_IN_USE_READ_CONTROL 1
#define FIFO_1_TO_7_IN_USE_REGISTER 0
#define FIFO_1_TO_7_IN_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_7_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_7_in_csr altera_avalon_fifo
#define FIFO_1_TO_7_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_7_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_7_IN_CSR_BASE 0x1140
#define FIFO_1_TO_7_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_7_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_7_IN_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_7_IN_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_7_IN_CSR_IRQ -1
#define FIFO_1_TO_7_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_7_IN_CSR_NAME "/dev/fifo_1_to_7_in_csr"
#define FIFO_1_TO_7_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_7_IN_CSR_SPAN 32
#define FIFO_1_TO_7_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_7_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_7_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_7_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_7_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_7_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_7_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_7_IN_CSR_USE_IRQ 0
#define FIFO_1_TO_7_IN_CSR_USE_PACKET 1
#define FIFO_1_TO_7_IN_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_7_IN_CSR_USE_REGISTER 0
#define FIFO_1_TO_7_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_1_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_1_out altera_avalon_fifo
#define FIFO_2_TO_1_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_1_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_1_OUT_BASE 0x134c
#define FIFO_2_TO_1_OUT_BITS_PER_SYMBOL 16
#define FIFO_2_TO_1_OUT_CHANNEL_WIDTH 8
#define FIFO_2_TO_1_OUT_ERROR_WIDTH 8
#define FIFO_2_TO_1_OUT_FIFO_DEPTH 16
#define FIFO_2_TO_1_OUT_IRQ -1
#define FIFO_2_TO_1_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_1_OUT_NAME "/dev/fifo_2_to_1_out"
#define FIFO_2_TO_1_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_1_OUT_SPAN 4
#define FIFO_2_TO_1_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_1_OUT_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_1_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_1_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_1_OUT_USE_AVALONST_SINK 0
#define FIFO_2_TO_1_OUT_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_1_OUT_USE_BACKPRESSURE 1
#define FIFO_2_TO_1_OUT_USE_IRQ 0
#define FIFO_2_TO_1_OUT_USE_PACKET 1
#define FIFO_2_TO_1_OUT_USE_READ_CONTROL 1
#define FIFO_2_TO_1_OUT_USE_REGISTER 0
#define FIFO_2_TO_1_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_1_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_1_out_csr altera_avalon_fifo
#define FIFO_2_TO_1_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_1_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_1_OUT_CSR_BASE 0x1200
#define FIFO_2_TO_1_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_1_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_1_OUT_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_1_OUT_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_1_OUT_CSR_IRQ -1
#define FIFO_2_TO_1_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_1_OUT_CSR_NAME "/dev/fifo_2_to_1_out_csr"
#define FIFO_2_TO_1_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_1_OUT_CSR_SPAN 32
#define FIFO_2_TO_1_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_1_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_1_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_1_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_1_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_1_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_1_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_1_OUT_CSR_USE_IRQ 0
#define FIFO_2_TO_1_OUT_CSR_USE_PACKET 1
#define FIFO_2_TO_1_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_1_OUT_CSR_USE_REGISTER 0
#define FIFO_2_TO_1_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_1_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_1_out altera_avalon_fifo
#define FIFO_3_TO_1_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_1_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_1_OUT_BASE 0x1348
#define FIFO_3_TO_1_OUT_BITS_PER_SYMBOL 16
#define FIFO_3_TO_1_OUT_CHANNEL_WIDTH 8
#define FIFO_3_TO_1_OUT_ERROR_WIDTH 8
#define FIFO_3_TO_1_OUT_FIFO_DEPTH 16
#define FIFO_3_TO_1_OUT_IRQ -1
#define FIFO_3_TO_1_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_1_OUT_NAME "/dev/fifo_3_to_1_out"
#define FIFO_3_TO_1_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_1_OUT_SPAN 4
#define FIFO_3_TO_1_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_1_OUT_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_1_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_1_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_1_OUT_USE_AVALONST_SINK 0
#define FIFO_3_TO_1_OUT_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_1_OUT_USE_BACKPRESSURE 1
#define FIFO_3_TO_1_OUT_USE_IRQ 0
#define FIFO_3_TO_1_OUT_USE_PACKET 1
#define FIFO_3_TO_1_OUT_USE_READ_CONTROL 1
#define FIFO_3_TO_1_OUT_USE_REGISTER 0
#define FIFO_3_TO_1_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_1_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_1_out_csr altera_avalon_fifo
#define FIFO_3_TO_1_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_1_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_1_OUT_CSR_BASE 0x11e0
#define FIFO_3_TO_1_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_1_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_1_OUT_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_1_OUT_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_1_OUT_CSR_IRQ -1
#define FIFO_3_TO_1_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_1_OUT_CSR_NAME "/dev/fifo_3_to_1_out_csr"
#define FIFO_3_TO_1_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_1_OUT_CSR_SPAN 32
#define FIFO_3_TO_1_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_1_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_1_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_1_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_1_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_1_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_1_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_1_OUT_CSR_USE_IRQ 0
#define FIFO_3_TO_1_OUT_CSR_USE_PACKET 1
#define FIFO_3_TO_1_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_1_OUT_CSR_USE_REGISTER 0
#define FIFO_3_TO_1_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_1_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_1_out altera_avalon_fifo
#define FIFO_4_TO_1_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_1_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_1_OUT_BASE 0x1334
#define FIFO_4_TO_1_OUT_BITS_PER_SYMBOL 16
#define FIFO_4_TO_1_OUT_CHANNEL_WIDTH 8
#define FIFO_4_TO_1_OUT_ERROR_WIDTH 8
#define FIFO_4_TO_1_OUT_FIFO_DEPTH 16
#define FIFO_4_TO_1_OUT_IRQ -1
#define FIFO_4_TO_1_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_1_OUT_NAME "/dev/fifo_4_to_1_out"
#define FIFO_4_TO_1_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_1_OUT_SPAN 4
#define FIFO_4_TO_1_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_1_OUT_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_1_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_1_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_1_OUT_USE_AVALONST_SINK 0
#define FIFO_4_TO_1_OUT_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_1_OUT_USE_BACKPRESSURE 1
#define FIFO_4_TO_1_OUT_USE_IRQ 0
#define FIFO_4_TO_1_OUT_USE_PACKET 1
#define FIFO_4_TO_1_OUT_USE_READ_CONTROL 1
#define FIFO_4_TO_1_OUT_USE_REGISTER 0
#define FIFO_4_TO_1_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_1_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_1_out_csr altera_avalon_fifo
#define FIFO_4_TO_1_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_1_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_1_OUT_CSR_BASE 0x1120
#define FIFO_4_TO_1_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_1_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_1_OUT_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_1_OUT_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_1_OUT_CSR_IRQ -1
#define FIFO_4_TO_1_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_1_OUT_CSR_NAME "/dev/fifo_4_to_1_out_csr"
#define FIFO_4_TO_1_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_1_OUT_CSR_SPAN 32
#define FIFO_4_TO_1_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_1_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_1_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_1_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_1_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_1_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_1_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_1_OUT_CSR_USE_IRQ 0
#define FIFO_4_TO_1_OUT_CSR_USE_PACKET 1
#define FIFO_4_TO_1_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_1_OUT_CSR_USE_REGISTER 0
#define FIFO_4_TO_1_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_1_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_1_out altera_avalon_fifo
#define FIFO_5_TO_1_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_1_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_1_OUT_BASE 0x1330
#define FIFO_5_TO_1_OUT_BITS_PER_SYMBOL 16
#define FIFO_5_TO_1_OUT_CHANNEL_WIDTH 8
#define FIFO_5_TO_1_OUT_ERROR_WIDTH 8
#define FIFO_5_TO_1_OUT_FIFO_DEPTH 16
#define FIFO_5_TO_1_OUT_IRQ -1
#define FIFO_5_TO_1_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_1_OUT_NAME "/dev/fifo_5_to_1_out"
#define FIFO_5_TO_1_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_1_OUT_SPAN 4
#define FIFO_5_TO_1_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_1_OUT_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_1_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_1_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_1_OUT_USE_AVALONST_SINK 0
#define FIFO_5_TO_1_OUT_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_1_OUT_USE_BACKPRESSURE 1
#define FIFO_5_TO_1_OUT_USE_IRQ 0
#define FIFO_5_TO_1_OUT_USE_PACKET 1
#define FIFO_5_TO_1_OUT_USE_READ_CONTROL 1
#define FIFO_5_TO_1_OUT_USE_REGISTER 0
#define FIFO_5_TO_1_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_1_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_1_out_csr altera_avalon_fifo
#define FIFO_5_TO_1_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_1_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_1_OUT_CSR_BASE 0x1100
#define FIFO_5_TO_1_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_1_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_1_OUT_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_1_OUT_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_1_OUT_CSR_IRQ -1
#define FIFO_5_TO_1_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_1_OUT_CSR_NAME "/dev/fifo_5_to_1_out_csr"
#define FIFO_5_TO_1_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_1_OUT_CSR_SPAN 32
#define FIFO_5_TO_1_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_1_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_1_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_1_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_1_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_1_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_1_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_1_OUT_CSR_USE_IRQ 0
#define FIFO_5_TO_1_OUT_CSR_USE_PACKET 1
#define FIFO_5_TO_1_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_1_OUT_CSR_USE_REGISTER 0
#define FIFO_5_TO_1_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_1_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_1_out altera_avalon_fifo
#define FIFO_6_TO_1_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_1_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_1_OUT_BASE 0x132c
#define FIFO_6_TO_1_OUT_BITS_PER_SYMBOL 16
#define FIFO_6_TO_1_OUT_CHANNEL_WIDTH 8
#define FIFO_6_TO_1_OUT_ERROR_WIDTH 8
#define FIFO_6_TO_1_OUT_FIFO_DEPTH 16
#define FIFO_6_TO_1_OUT_IRQ -1
#define FIFO_6_TO_1_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_1_OUT_NAME "/dev/fifo_6_to_1_out"
#define FIFO_6_TO_1_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_1_OUT_SPAN 4
#define FIFO_6_TO_1_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_1_OUT_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_1_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_1_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_1_OUT_USE_AVALONST_SINK 0
#define FIFO_6_TO_1_OUT_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_1_OUT_USE_BACKPRESSURE 1
#define FIFO_6_TO_1_OUT_USE_IRQ 0
#define FIFO_6_TO_1_OUT_USE_PACKET 1
#define FIFO_6_TO_1_OUT_USE_READ_CONTROL 1
#define FIFO_6_TO_1_OUT_USE_REGISTER 0
#define FIFO_6_TO_1_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_1_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_1_out_csr altera_avalon_fifo
#define FIFO_6_TO_1_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_1_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_1_OUT_CSR_BASE 0x10e0
#define FIFO_6_TO_1_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_1_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_1_OUT_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_1_OUT_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_1_OUT_CSR_IRQ -1
#define FIFO_6_TO_1_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_1_OUT_CSR_NAME "/dev/fifo_6_to_1_out_csr"
#define FIFO_6_TO_1_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_1_OUT_CSR_SPAN 32
#define FIFO_6_TO_1_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_1_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_1_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_1_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_1_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_1_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_1_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_1_OUT_CSR_USE_IRQ 0
#define FIFO_6_TO_1_OUT_CSR_USE_PACKET 1
#define FIFO_6_TO_1_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_1_OUT_CSR_USE_REGISTER 0
#define FIFO_6_TO_1_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_1_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_1_out altera_avalon_fifo
#define FIFO_7_TO_1_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_1_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_1_OUT_BASE 0x1328
#define FIFO_7_TO_1_OUT_BITS_PER_SYMBOL 16
#define FIFO_7_TO_1_OUT_CHANNEL_WIDTH 8
#define FIFO_7_TO_1_OUT_ERROR_WIDTH 8
#define FIFO_7_TO_1_OUT_FIFO_DEPTH 16
#define FIFO_7_TO_1_OUT_IRQ -1
#define FIFO_7_TO_1_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_1_OUT_NAME "/dev/fifo_7_to_1_out"
#define FIFO_7_TO_1_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_1_OUT_SPAN 4
#define FIFO_7_TO_1_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_1_OUT_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_1_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_1_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_1_OUT_USE_AVALONST_SINK 0
#define FIFO_7_TO_1_OUT_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_1_OUT_USE_BACKPRESSURE 1
#define FIFO_7_TO_1_OUT_USE_IRQ 0
#define FIFO_7_TO_1_OUT_USE_PACKET 1
#define FIFO_7_TO_1_OUT_USE_READ_CONTROL 1
#define FIFO_7_TO_1_OUT_USE_REGISTER 0
#define FIFO_7_TO_1_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_1_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_1_out_csr altera_avalon_fifo
#define FIFO_7_TO_1_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_1_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_1_OUT_CSR_BASE 0x10c0
#define FIFO_7_TO_1_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_1_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_1_OUT_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_1_OUT_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_1_OUT_CSR_IRQ -1
#define FIFO_7_TO_1_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_1_OUT_CSR_NAME "/dev/fifo_7_to_1_out_csr"
#define FIFO_7_TO_1_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_1_OUT_CSR_SPAN 32
#define FIFO_7_TO_1_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_1_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_1_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_1_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_1_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_1_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_1_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_1_OUT_CSR_USE_IRQ 0
#define FIFO_7_TO_1_OUT_CSR_USE_PACKET 1
#define FIFO_7_TO_1_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_1_OUT_CSR_USE_REGISTER 0
#define FIFO_7_TO_1_OUT_CSR_USE_WRITE_CONTROL 1




/********************/
/* system.h - CPU 2 */
/********************/


/*
 * fifo_0_to_2_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_2_out altera_avalon_fifo
#define FIFO_0_TO_2_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_2_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_2_OUT_BASE 0x135c
#define FIFO_0_TO_2_OUT_BITS_PER_SYMBOL 16
#define FIFO_0_TO_2_OUT_CHANNEL_WIDTH 8
#define FIFO_0_TO_2_OUT_ERROR_WIDTH 8
#define FIFO_0_TO_2_OUT_FIFO_DEPTH 16
#define FIFO_0_TO_2_OUT_IRQ -1
#define FIFO_0_TO_2_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_2_OUT_NAME "/dev/fifo_0_to_2_out"
#define FIFO_0_TO_2_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_2_OUT_SPAN 4
#define FIFO_0_TO_2_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_2_OUT_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_2_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_2_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_2_OUT_USE_AVALONST_SINK 0
#define FIFO_0_TO_2_OUT_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_2_OUT_USE_BACKPRESSURE 1
#define FIFO_0_TO_2_OUT_USE_IRQ 0
#define FIFO_0_TO_2_OUT_USE_PACKET 1
#define FIFO_0_TO_2_OUT_USE_READ_CONTROL 1
#define FIFO_0_TO_2_OUT_USE_REGISTER 0
#define FIFO_0_TO_2_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_2_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_2_out_csr altera_avalon_fifo
#define FIFO_0_TO_2_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_2_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_2_OUT_CSR_BASE 0x1280
#define FIFO_0_TO_2_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_2_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_2_OUT_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_2_OUT_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_2_OUT_CSR_IRQ -1
#define FIFO_0_TO_2_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_2_OUT_CSR_NAME "/dev/fifo_0_to_2_out_csr"
#define FIFO_0_TO_2_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_2_OUT_CSR_SPAN 32
#define FIFO_0_TO_2_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_2_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_2_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_2_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_2_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_2_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_2_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_2_OUT_CSR_USE_IRQ 0
#define FIFO_0_TO_2_OUT_CSR_USE_PACKET 1
#define FIFO_0_TO_2_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_2_OUT_CSR_USE_REGISTER 0
#define FIFO_0_TO_2_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_2_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_2_out altera_avalon_fifo
#define FIFO_1_TO_2_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_2_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_2_OUT_BASE 0x1358
#define FIFO_1_TO_2_OUT_BITS_PER_SYMBOL 16
#define FIFO_1_TO_2_OUT_CHANNEL_WIDTH 8
#define FIFO_1_TO_2_OUT_ERROR_WIDTH 8
#define FIFO_1_TO_2_OUT_FIFO_DEPTH 16
#define FIFO_1_TO_2_OUT_IRQ -1
#define FIFO_1_TO_2_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_2_OUT_NAME "/dev/fifo_1_to_2_out"
#define FIFO_1_TO_2_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_2_OUT_SPAN 4
#define FIFO_1_TO_2_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_2_OUT_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_2_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_2_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_2_OUT_USE_AVALONST_SINK 0
#define FIFO_1_TO_2_OUT_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_2_OUT_USE_BACKPRESSURE 1
#define FIFO_1_TO_2_OUT_USE_IRQ 0
#define FIFO_1_TO_2_OUT_USE_PACKET 1
#define FIFO_1_TO_2_OUT_USE_READ_CONTROL 1
#define FIFO_1_TO_2_OUT_USE_REGISTER 0
#define FIFO_1_TO_2_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_2_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_2_out_csr altera_avalon_fifo
#define FIFO_1_TO_2_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_2_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_2_OUT_CSR_BASE 0x1260
#define FIFO_1_TO_2_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_2_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_2_OUT_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_2_OUT_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_2_OUT_CSR_IRQ -1
#define FIFO_1_TO_2_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_2_OUT_CSR_NAME "/dev/fifo_1_to_2_out_csr"
#define FIFO_1_TO_2_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_2_OUT_CSR_SPAN 32
#define FIFO_1_TO_2_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_2_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_2_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_2_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_2_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_2_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_2_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_2_OUT_CSR_USE_IRQ 0
#define FIFO_1_TO_2_OUT_CSR_USE_PACKET 1
#define FIFO_1_TO_2_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_2_OUT_CSR_USE_REGISTER 0
#define FIFO_1_TO_2_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_0_in altera_avalon_fifo
#define FIFO_2_TO_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_0_IN_BASE 0x1354
#define FIFO_2_TO_0_IN_BITS_PER_SYMBOL 16
#define FIFO_2_TO_0_IN_CHANNEL_WIDTH 8
#define FIFO_2_TO_0_IN_ERROR_WIDTH 8
#define FIFO_2_TO_0_IN_FIFO_DEPTH 16
#define FIFO_2_TO_0_IN_IRQ -1
#define FIFO_2_TO_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_0_IN_NAME "/dev/fifo_2_to_0_in"
#define FIFO_2_TO_0_IN_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_0_IN_SPAN 4
#define FIFO_2_TO_0_IN_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_0_IN_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_0_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_0_IN_USE_AVALONST_SINK 0
#define FIFO_2_TO_0_IN_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_0_IN_USE_BACKPRESSURE 1
#define FIFO_2_TO_0_IN_USE_IRQ 0
#define FIFO_2_TO_0_IN_USE_PACKET 1
#define FIFO_2_TO_0_IN_USE_READ_CONTROL 1
#define FIFO_2_TO_0_IN_USE_REGISTER 0
#define FIFO_2_TO_0_IN_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_0_in_csr altera_avalon_fifo
#define FIFO_2_TO_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_0_IN_CSR_BASE 0x1240
#define FIFO_2_TO_0_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_0_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_0_IN_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_0_IN_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_0_IN_CSR_IRQ -1
#define FIFO_2_TO_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_0_IN_CSR_NAME "/dev/fifo_2_to_0_in_csr"
#define FIFO_2_TO_0_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_0_IN_CSR_SPAN 32
#define FIFO_2_TO_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_0_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_0_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_0_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_0_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_0_IN_CSR_USE_IRQ 0
#define FIFO_2_TO_0_IN_CSR_USE_PACKET 1
#define FIFO_2_TO_0_IN_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_0_IN_CSR_USE_REGISTER 0
#define FIFO_2_TO_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_1_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_1_in altera_avalon_fifo
#define FIFO_2_TO_1_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_1_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_1_IN_BASE 0x1350
#define FIFO_2_TO_1_IN_BITS_PER_SYMBOL 16
#define FIFO_2_TO_1_IN_CHANNEL_WIDTH 8
#define FIFO_2_TO_1_IN_ERROR_WIDTH 8
#define FIFO_2_TO_1_IN_FIFO_DEPTH 16
#define FIFO_2_TO_1_IN_IRQ -1
#define FIFO_2_TO_1_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_1_IN_NAME "/dev/fifo_2_to_1_in"
#define FIFO_2_TO_1_IN_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_1_IN_SPAN 4
#define FIFO_2_TO_1_IN_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_1_IN_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_1_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_1_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_1_IN_USE_AVALONST_SINK 0
#define FIFO_2_TO_1_IN_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_1_IN_USE_BACKPRESSURE 1
#define FIFO_2_TO_1_IN_USE_IRQ 0
#define FIFO_2_TO_1_IN_USE_PACKET 1
#define FIFO_2_TO_1_IN_USE_READ_CONTROL 1
#define FIFO_2_TO_1_IN_USE_REGISTER 0
#define FIFO_2_TO_1_IN_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_1_in_csr altera_avalon_fifo
#define FIFO_2_TO_1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_1_IN_CSR_BASE 0x1220
#define FIFO_2_TO_1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_1_IN_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_1_IN_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_1_IN_CSR_IRQ -1
#define FIFO_2_TO_1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_1_IN_CSR_NAME "/dev/fifo_2_to_1_in_csr"
#define FIFO_2_TO_1_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_1_IN_CSR_SPAN 32
#define FIFO_2_TO_1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_1_IN_CSR_USE_IRQ 0
#define FIFO_2_TO_1_IN_CSR_USE_PACKET 1
#define FIFO_2_TO_1_IN_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_1_IN_CSR_USE_REGISTER 0
#define FIFO_2_TO_1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_3_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_3_in altera_avalon_fifo
#define FIFO_2_TO_3_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_3_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_3_IN_BASE 0x134c
#define FIFO_2_TO_3_IN_BITS_PER_SYMBOL 16
#define FIFO_2_TO_3_IN_CHANNEL_WIDTH 8
#define FIFO_2_TO_3_IN_ERROR_WIDTH 8
#define FIFO_2_TO_3_IN_FIFO_DEPTH 16
#define FIFO_2_TO_3_IN_IRQ -1
#define FIFO_2_TO_3_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_3_IN_NAME "/dev/fifo_2_to_3_in"
#define FIFO_2_TO_3_IN_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_3_IN_SPAN 4
#define FIFO_2_TO_3_IN_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_3_IN_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_3_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_3_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_3_IN_USE_AVALONST_SINK 0
#define FIFO_2_TO_3_IN_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_3_IN_USE_BACKPRESSURE 1
#define FIFO_2_TO_3_IN_USE_IRQ 0
#define FIFO_2_TO_3_IN_USE_PACKET 1
#define FIFO_2_TO_3_IN_USE_READ_CONTROL 1
#define FIFO_2_TO_3_IN_USE_REGISTER 0
#define FIFO_2_TO_3_IN_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_3_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_3_in_csr altera_avalon_fifo
#define FIFO_2_TO_3_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_3_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_3_IN_CSR_BASE 0x1200
#define FIFO_2_TO_3_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_3_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_3_IN_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_3_IN_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_3_IN_CSR_IRQ -1
#define FIFO_2_TO_3_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_3_IN_CSR_NAME "/dev/fifo_2_to_3_in_csr"
#define FIFO_2_TO_3_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_3_IN_CSR_SPAN 32
#define FIFO_2_TO_3_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_3_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_3_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_3_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_3_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_3_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_3_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_3_IN_CSR_USE_IRQ 0
#define FIFO_2_TO_3_IN_CSR_USE_PACKET 1
#define FIFO_2_TO_3_IN_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_3_IN_CSR_USE_REGISTER 0
#define FIFO_2_TO_3_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_4_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_4_in altera_avalon_fifo
#define FIFO_2_TO_4_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_4_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_4_IN_BASE 0x1344
#define FIFO_2_TO_4_IN_BITS_PER_SYMBOL 16
#define FIFO_2_TO_4_IN_CHANNEL_WIDTH 8
#define FIFO_2_TO_4_IN_ERROR_WIDTH 8
#define FIFO_2_TO_4_IN_FIFO_DEPTH 16
#define FIFO_2_TO_4_IN_IRQ -1
#define FIFO_2_TO_4_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_4_IN_NAME "/dev/fifo_2_to_4_in"
#define FIFO_2_TO_4_IN_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_4_IN_SPAN 4
#define FIFO_2_TO_4_IN_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_4_IN_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_4_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_4_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_4_IN_USE_AVALONST_SINK 0
#define FIFO_2_TO_4_IN_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_4_IN_USE_BACKPRESSURE 1
#define FIFO_2_TO_4_IN_USE_IRQ 0
#define FIFO_2_TO_4_IN_USE_PACKET 1
#define FIFO_2_TO_4_IN_USE_READ_CONTROL 1
#define FIFO_2_TO_4_IN_USE_REGISTER 0
#define FIFO_2_TO_4_IN_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_4_in_csr altera_avalon_fifo
#define FIFO_2_TO_4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_4_IN_CSR_BASE 0x11a0
#define FIFO_2_TO_4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_4_IN_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_4_IN_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_4_IN_CSR_IRQ -1
#define FIFO_2_TO_4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_4_IN_CSR_NAME "/dev/fifo_2_to_4_in_csr"
#define FIFO_2_TO_4_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_4_IN_CSR_SPAN 32
#define FIFO_2_TO_4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_4_IN_CSR_USE_IRQ 0
#define FIFO_2_TO_4_IN_CSR_USE_PACKET 1
#define FIFO_2_TO_4_IN_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_4_IN_CSR_USE_REGISTER 0
#define FIFO_2_TO_4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_5_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_5_in altera_avalon_fifo
#define FIFO_2_TO_5_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_5_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_5_IN_BASE 0x1340
#define FIFO_2_TO_5_IN_BITS_PER_SYMBOL 16
#define FIFO_2_TO_5_IN_CHANNEL_WIDTH 8
#define FIFO_2_TO_5_IN_ERROR_WIDTH 8
#define FIFO_2_TO_5_IN_FIFO_DEPTH 16
#define FIFO_2_TO_5_IN_IRQ -1
#define FIFO_2_TO_5_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_5_IN_NAME "/dev/fifo_2_to_5_in"
#define FIFO_2_TO_5_IN_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_5_IN_SPAN 4
#define FIFO_2_TO_5_IN_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_5_IN_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_5_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_5_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_5_IN_USE_AVALONST_SINK 0
#define FIFO_2_TO_5_IN_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_5_IN_USE_BACKPRESSURE 1
#define FIFO_2_TO_5_IN_USE_IRQ 0
#define FIFO_2_TO_5_IN_USE_PACKET 1
#define FIFO_2_TO_5_IN_USE_READ_CONTROL 1
#define FIFO_2_TO_5_IN_USE_REGISTER 0
#define FIFO_2_TO_5_IN_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_5_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_5_in_csr altera_avalon_fifo
#define FIFO_2_TO_5_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_5_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_5_IN_CSR_BASE 0x1180
#define FIFO_2_TO_5_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_5_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_5_IN_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_5_IN_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_5_IN_CSR_IRQ -1
#define FIFO_2_TO_5_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_5_IN_CSR_NAME "/dev/fifo_2_to_5_in_csr"
#define FIFO_2_TO_5_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_5_IN_CSR_SPAN 32
#define FIFO_2_TO_5_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_5_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_5_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_5_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_5_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_5_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_5_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_5_IN_CSR_USE_IRQ 0
#define FIFO_2_TO_5_IN_CSR_USE_PACKET 1
#define FIFO_2_TO_5_IN_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_5_IN_CSR_USE_REGISTER 0
#define FIFO_2_TO_5_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_6_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_6_in altera_avalon_fifo
#define FIFO_2_TO_6_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_6_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_6_IN_BASE 0x133c
#define FIFO_2_TO_6_IN_BITS_PER_SYMBOL 16
#define FIFO_2_TO_6_IN_CHANNEL_WIDTH 8
#define FIFO_2_TO_6_IN_ERROR_WIDTH 8
#define FIFO_2_TO_6_IN_FIFO_DEPTH 16
#define FIFO_2_TO_6_IN_IRQ -1
#define FIFO_2_TO_6_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_6_IN_NAME "/dev/fifo_2_to_6_in"
#define FIFO_2_TO_6_IN_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_6_IN_SPAN 4
#define FIFO_2_TO_6_IN_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_6_IN_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_6_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_6_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_6_IN_USE_AVALONST_SINK 0
#define FIFO_2_TO_6_IN_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_6_IN_USE_BACKPRESSURE 1
#define FIFO_2_TO_6_IN_USE_IRQ 0
#define FIFO_2_TO_6_IN_USE_PACKET 1
#define FIFO_2_TO_6_IN_USE_READ_CONTROL 1
#define FIFO_2_TO_6_IN_USE_REGISTER 0
#define FIFO_2_TO_6_IN_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_6_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_6_in_csr altera_avalon_fifo
#define FIFO_2_TO_6_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_6_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_6_IN_CSR_BASE 0x1160
#define FIFO_2_TO_6_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_6_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_6_IN_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_6_IN_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_6_IN_CSR_IRQ -1
#define FIFO_2_TO_6_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_6_IN_CSR_NAME "/dev/fifo_2_to_6_in_csr"
#define FIFO_2_TO_6_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_6_IN_CSR_SPAN 32
#define FIFO_2_TO_6_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_6_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_6_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_6_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_6_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_6_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_6_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_6_IN_CSR_USE_IRQ 0
#define FIFO_2_TO_6_IN_CSR_USE_PACKET 1
#define FIFO_2_TO_6_IN_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_6_IN_CSR_USE_REGISTER 0
#define FIFO_2_TO_6_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_7_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_7_in altera_avalon_fifo
#define FIFO_2_TO_7_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_7_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_7_IN_BASE 0x1338
#define FIFO_2_TO_7_IN_BITS_PER_SYMBOL 16
#define FIFO_2_TO_7_IN_CHANNEL_WIDTH 8
#define FIFO_2_TO_7_IN_ERROR_WIDTH 8
#define FIFO_2_TO_7_IN_FIFO_DEPTH 16
#define FIFO_2_TO_7_IN_IRQ -1
#define FIFO_2_TO_7_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_7_IN_NAME "/dev/fifo_2_to_7_in"
#define FIFO_2_TO_7_IN_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_7_IN_SPAN 4
#define FIFO_2_TO_7_IN_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_7_IN_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_7_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_7_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_7_IN_USE_AVALONST_SINK 0
#define FIFO_2_TO_7_IN_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_7_IN_USE_BACKPRESSURE 1
#define FIFO_2_TO_7_IN_USE_IRQ 0
#define FIFO_2_TO_7_IN_USE_PACKET 1
#define FIFO_2_TO_7_IN_USE_READ_CONTROL 1
#define FIFO_2_TO_7_IN_USE_REGISTER 0
#define FIFO_2_TO_7_IN_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_7_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_7_in_csr altera_avalon_fifo
#define FIFO_2_TO_7_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_7_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_7_IN_CSR_BASE 0x1140
#define FIFO_2_TO_7_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_7_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_7_IN_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_7_IN_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_7_IN_CSR_IRQ -1
#define FIFO_2_TO_7_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_7_IN_CSR_NAME "/dev/fifo_2_to_7_in_csr"
#define FIFO_2_TO_7_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_7_IN_CSR_SPAN 32
#define FIFO_2_TO_7_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_7_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_7_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_7_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_7_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_7_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_7_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_7_IN_CSR_USE_IRQ 0
#define FIFO_2_TO_7_IN_CSR_USE_PACKET 1
#define FIFO_2_TO_7_IN_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_7_IN_CSR_USE_REGISTER 0
#define FIFO_2_TO_7_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_2_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_2_out altera_avalon_fifo
#define FIFO_3_TO_2_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_2_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_2_OUT_BASE 0x1348
#define FIFO_3_TO_2_OUT_BITS_PER_SYMBOL 16
#define FIFO_3_TO_2_OUT_CHANNEL_WIDTH 8
#define FIFO_3_TO_2_OUT_ERROR_WIDTH 8
#define FIFO_3_TO_2_OUT_FIFO_DEPTH 16
#define FIFO_3_TO_2_OUT_IRQ -1
#define FIFO_3_TO_2_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_2_OUT_NAME "/dev/fifo_3_to_2_out"
#define FIFO_3_TO_2_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_2_OUT_SPAN 4
#define FIFO_3_TO_2_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_2_OUT_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_2_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_2_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_2_OUT_USE_AVALONST_SINK 0
#define FIFO_3_TO_2_OUT_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_2_OUT_USE_BACKPRESSURE 1
#define FIFO_3_TO_2_OUT_USE_IRQ 0
#define FIFO_3_TO_2_OUT_USE_PACKET 1
#define FIFO_3_TO_2_OUT_USE_READ_CONTROL 1
#define FIFO_3_TO_2_OUT_USE_REGISTER 0
#define FIFO_3_TO_2_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_2_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_2_out_csr altera_avalon_fifo
#define FIFO_3_TO_2_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_2_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_2_OUT_CSR_BASE 0x11e0
#define FIFO_3_TO_2_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_2_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_2_OUT_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_2_OUT_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_2_OUT_CSR_IRQ -1
#define FIFO_3_TO_2_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_2_OUT_CSR_NAME "/dev/fifo_3_to_2_out_csr"
#define FIFO_3_TO_2_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_2_OUT_CSR_SPAN 32
#define FIFO_3_TO_2_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_2_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_2_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_2_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_2_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_2_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_2_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_2_OUT_CSR_USE_IRQ 0
#define FIFO_3_TO_2_OUT_CSR_USE_PACKET 1
#define FIFO_3_TO_2_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_2_OUT_CSR_USE_REGISTER 0
#define FIFO_3_TO_2_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_2_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_2_out altera_avalon_fifo
#define FIFO_4_TO_2_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_2_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_2_OUT_BASE 0x1334
#define FIFO_4_TO_2_OUT_BITS_PER_SYMBOL 16
#define FIFO_4_TO_2_OUT_CHANNEL_WIDTH 8
#define FIFO_4_TO_2_OUT_ERROR_WIDTH 8
#define FIFO_4_TO_2_OUT_FIFO_DEPTH 16
#define FIFO_4_TO_2_OUT_IRQ -1
#define FIFO_4_TO_2_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_2_OUT_NAME "/dev/fifo_4_to_2_out"
#define FIFO_4_TO_2_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_2_OUT_SPAN 4
#define FIFO_4_TO_2_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_2_OUT_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_2_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_2_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_2_OUT_USE_AVALONST_SINK 0
#define FIFO_4_TO_2_OUT_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_2_OUT_USE_BACKPRESSURE 1
#define FIFO_4_TO_2_OUT_USE_IRQ 0
#define FIFO_4_TO_2_OUT_USE_PACKET 1
#define FIFO_4_TO_2_OUT_USE_READ_CONTROL 1
#define FIFO_4_TO_2_OUT_USE_REGISTER 0
#define FIFO_4_TO_2_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_2_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_2_out_csr altera_avalon_fifo
#define FIFO_4_TO_2_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_2_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_2_OUT_CSR_BASE 0x1120
#define FIFO_4_TO_2_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_2_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_2_OUT_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_2_OUT_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_2_OUT_CSR_IRQ -1
#define FIFO_4_TO_2_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_2_OUT_CSR_NAME "/dev/fifo_4_to_2_out_csr"
#define FIFO_4_TO_2_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_2_OUT_CSR_SPAN 32
#define FIFO_4_TO_2_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_2_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_2_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_2_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_2_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_2_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_2_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_2_OUT_CSR_USE_IRQ 0
#define FIFO_4_TO_2_OUT_CSR_USE_PACKET 1
#define FIFO_4_TO_2_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_2_OUT_CSR_USE_REGISTER 0
#define FIFO_4_TO_2_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_2_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_2_out altera_avalon_fifo
#define FIFO_5_TO_2_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_2_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_2_OUT_BASE 0x1330
#define FIFO_5_TO_2_OUT_BITS_PER_SYMBOL 16
#define FIFO_5_TO_2_OUT_CHANNEL_WIDTH 8
#define FIFO_5_TO_2_OUT_ERROR_WIDTH 8
#define FIFO_5_TO_2_OUT_FIFO_DEPTH 16
#define FIFO_5_TO_2_OUT_IRQ -1
#define FIFO_5_TO_2_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_2_OUT_NAME "/dev/fifo_5_to_2_out"
#define FIFO_5_TO_2_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_2_OUT_SPAN 4
#define FIFO_5_TO_2_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_2_OUT_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_2_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_2_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_2_OUT_USE_AVALONST_SINK 0
#define FIFO_5_TO_2_OUT_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_2_OUT_USE_BACKPRESSURE 1
#define FIFO_5_TO_2_OUT_USE_IRQ 0
#define FIFO_5_TO_2_OUT_USE_PACKET 1
#define FIFO_5_TO_2_OUT_USE_READ_CONTROL 1
#define FIFO_5_TO_2_OUT_USE_REGISTER 0
#define FIFO_5_TO_2_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_2_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_2_out_csr altera_avalon_fifo
#define FIFO_5_TO_2_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_2_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_2_OUT_CSR_BASE 0x1100
#define FIFO_5_TO_2_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_2_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_2_OUT_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_2_OUT_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_2_OUT_CSR_IRQ -1
#define FIFO_5_TO_2_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_2_OUT_CSR_NAME "/dev/fifo_5_to_2_out_csr"
#define FIFO_5_TO_2_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_2_OUT_CSR_SPAN 32
#define FIFO_5_TO_2_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_2_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_2_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_2_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_2_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_2_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_2_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_2_OUT_CSR_USE_IRQ 0
#define FIFO_5_TO_2_OUT_CSR_USE_PACKET 1
#define FIFO_5_TO_2_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_2_OUT_CSR_USE_REGISTER 0
#define FIFO_5_TO_2_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_2_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_2_out altera_avalon_fifo
#define FIFO_6_TO_2_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_2_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_2_OUT_BASE 0x132c
#define FIFO_6_TO_2_OUT_BITS_PER_SYMBOL 16
#define FIFO_6_TO_2_OUT_CHANNEL_WIDTH 8
#define FIFO_6_TO_2_OUT_ERROR_WIDTH 8
#define FIFO_6_TO_2_OUT_FIFO_DEPTH 16
#define FIFO_6_TO_2_OUT_IRQ -1
#define FIFO_6_TO_2_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_2_OUT_NAME "/dev/fifo_6_to_2_out"
#define FIFO_6_TO_2_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_2_OUT_SPAN 4
#define FIFO_6_TO_2_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_2_OUT_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_2_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_2_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_2_OUT_USE_AVALONST_SINK 0
#define FIFO_6_TO_2_OUT_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_2_OUT_USE_BACKPRESSURE 1
#define FIFO_6_TO_2_OUT_USE_IRQ 0
#define FIFO_6_TO_2_OUT_USE_PACKET 1
#define FIFO_6_TO_2_OUT_USE_READ_CONTROL 1
#define FIFO_6_TO_2_OUT_USE_REGISTER 0
#define FIFO_6_TO_2_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_2_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_2_out_csr altera_avalon_fifo
#define FIFO_6_TO_2_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_2_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_2_OUT_CSR_BASE 0x10e0
#define FIFO_6_TO_2_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_2_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_2_OUT_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_2_OUT_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_2_OUT_CSR_IRQ -1
#define FIFO_6_TO_2_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_2_OUT_CSR_NAME "/dev/fifo_6_to_2_out_csr"
#define FIFO_6_TO_2_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_2_OUT_CSR_SPAN 32
#define FIFO_6_TO_2_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_2_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_2_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_2_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_2_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_2_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_2_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_2_OUT_CSR_USE_IRQ 0
#define FIFO_6_TO_2_OUT_CSR_USE_PACKET 1
#define FIFO_6_TO_2_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_2_OUT_CSR_USE_REGISTER 0
#define FIFO_6_TO_2_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_2_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_2_out altera_avalon_fifo
#define FIFO_7_TO_2_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_2_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_2_OUT_BASE 0x1328
#define FIFO_7_TO_2_OUT_BITS_PER_SYMBOL 16
#define FIFO_7_TO_2_OUT_CHANNEL_WIDTH 8
#define FIFO_7_TO_2_OUT_ERROR_WIDTH 8
#define FIFO_7_TO_2_OUT_FIFO_DEPTH 16
#define FIFO_7_TO_2_OUT_IRQ -1
#define FIFO_7_TO_2_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_2_OUT_NAME "/dev/fifo_7_to_2_out"
#define FIFO_7_TO_2_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_2_OUT_SPAN 4
#define FIFO_7_TO_2_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_2_OUT_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_2_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_2_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_2_OUT_USE_AVALONST_SINK 0
#define FIFO_7_TO_2_OUT_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_2_OUT_USE_BACKPRESSURE 1
#define FIFO_7_TO_2_OUT_USE_IRQ 0
#define FIFO_7_TO_2_OUT_USE_PACKET 1
#define FIFO_7_TO_2_OUT_USE_READ_CONTROL 1
#define FIFO_7_TO_2_OUT_USE_REGISTER 0
#define FIFO_7_TO_2_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_2_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_2_out_csr altera_avalon_fifo
#define FIFO_7_TO_2_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_2_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_2_OUT_CSR_BASE 0x10c0
#define FIFO_7_TO_2_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_2_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_2_OUT_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_2_OUT_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_2_OUT_CSR_IRQ -1
#define FIFO_7_TO_2_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_2_OUT_CSR_NAME "/dev/fifo_7_to_2_out_csr"
#define FIFO_7_TO_2_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_2_OUT_CSR_SPAN 32
#define FIFO_7_TO_2_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_2_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_2_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_2_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_2_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_2_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_2_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_2_OUT_CSR_USE_IRQ 0
#define FIFO_7_TO_2_OUT_CSR_USE_PACKET 1
#define FIFO_7_TO_2_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_2_OUT_CSR_USE_REGISTER 0
#define FIFO_7_TO_2_OUT_CSR_USE_WRITE_CONTROL 1



/********************/
/* system.h - CPU 3 */
/********************/


/*
 * fifo_0_to_3_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_3_out altera_avalon_fifo
#define FIFO_0_TO_3_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_3_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_3_OUT_BASE 0x135c
#define FIFO_0_TO_3_OUT_BITS_PER_SYMBOL 16
#define FIFO_0_TO_3_OUT_CHANNEL_WIDTH 8
#define FIFO_0_TO_3_OUT_ERROR_WIDTH 8
#define FIFO_0_TO_3_OUT_FIFO_DEPTH 16
#define FIFO_0_TO_3_OUT_IRQ -1
#define FIFO_0_TO_3_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_3_OUT_NAME "/dev/fifo_0_to_3_out"
#define FIFO_0_TO_3_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_3_OUT_SPAN 4
#define FIFO_0_TO_3_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_3_OUT_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_3_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_3_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_3_OUT_USE_AVALONST_SINK 0
#define FIFO_0_TO_3_OUT_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_3_OUT_USE_BACKPRESSURE 1
#define FIFO_0_TO_3_OUT_USE_IRQ 0
#define FIFO_0_TO_3_OUT_USE_PACKET 1
#define FIFO_0_TO_3_OUT_USE_READ_CONTROL 1
#define FIFO_0_TO_3_OUT_USE_REGISTER 0
#define FIFO_0_TO_3_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_3_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_3_out_csr altera_avalon_fifo
#define FIFO_0_TO_3_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_3_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_3_OUT_CSR_BASE 0x1280
#define FIFO_0_TO_3_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_3_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_3_OUT_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_3_OUT_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_3_OUT_CSR_IRQ -1
#define FIFO_0_TO_3_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_3_OUT_CSR_NAME "/dev/fifo_0_to_3_out_csr"
#define FIFO_0_TO_3_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_3_OUT_CSR_SPAN 32
#define FIFO_0_TO_3_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_3_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_3_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_3_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_3_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_3_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_3_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_3_OUT_CSR_USE_IRQ 0
#define FIFO_0_TO_3_OUT_CSR_USE_PACKET 1
#define FIFO_0_TO_3_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_3_OUT_CSR_USE_REGISTER 0
#define FIFO_0_TO_3_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_3_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_3_out altera_avalon_fifo
#define FIFO_1_TO_3_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_3_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_3_OUT_BASE 0x1358
#define FIFO_1_TO_3_OUT_BITS_PER_SYMBOL 16
#define FIFO_1_TO_3_OUT_CHANNEL_WIDTH 8
#define FIFO_1_TO_3_OUT_ERROR_WIDTH 8
#define FIFO_1_TO_3_OUT_FIFO_DEPTH 16
#define FIFO_1_TO_3_OUT_IRQ -1
#define FIFO_1_TO_3_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_3_OUT_NAME "/dev/fifo_1_to_3_out"
#define FIFO_1_TO_3_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_3_OUT_SPAN 4
#define FIFO_1_TO_3_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_3_OUT_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_3_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_3_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_3_OUT_USE_AVALONST_SINK 0
#define FIFO_1_TO_3_OUT_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_3_OUT_USE_BACKPRESSURE 1
#define FIFO_1_TO_3_OUT_USE_IRQ 0
#define FIFO_1_TO_3_OUT_USE_PACKET 1
#define FIFO_1_TO_3_OUT_USE_READ_CONTROL 1
#define FIFO_1_TO_3_OUT_USE_REGISTER 0
#define FIFO_1_TO_3_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_3_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_3_out_csr altera_avalon_fifo
#define FIFO_1_TO_3_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_3_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_3_OUT_CSR_BASE 0x1260
#define FIFO_1_TO_3_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_3_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_3_OUT_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_3_OUT_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_3_OUT_CSR_IRQ -1
#define FIFO_1_TO_3_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_3_OUT_CSR_NAME "/dev/fifo_1_to_3_out_csr"
#define FIFO_1_TO_3_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_3_OUT_CSR_SPAN 32
#define FIFO_1_TO_3_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_3_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_3_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_3_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_3_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_3_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_3_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_3_OUT_CSR_USE_IRQ 0
#define FIFO_1_TO_3_OUT_CSR_USE_PACKET 1
#define FIFO_1_TO_3_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_3_OUT_CSR_USE_REGISTER 0
#define FIFO_1_TO_3_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_3_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_3_out altera_avalon_fifo
#define FIFO_2_TO_3_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_3_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_3_OUT_BASE 0x1354
#define FIFO_2_TO_3_OUT_BITS_PER_SYMBOL 16
#define FIFO_2_TO_3_OUT_CHANNEL_WIDTH 8
#define FIFO_2_TO_3_OUT_ERROR_WIDTH 8
#define FIFO_2_TO_3_OUT_FIFO_DEPTH 16
#define FIFO_2_TO_3_OUT_IRQ -1
#define FIFO_2_TO_3_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_3_OUT_NAME "/dev/fifo_2_to_3_out"
#define FIFO_2_TO_3_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_3_OUT_SPAN 4
#define FIFO_2_TO_3_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_3_OUT_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_3_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_3_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_3_OUT_USE_AVALONST_SINK 0
#define FIFO_2_TO_3_OUT_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_3_OUT_USE_BACKPRESSURE 1
#define FIFO_2_TO_3_OUT_USE_IRQ 0
#define FIFO_2_TO_3_OUT_USE_PACKET 1
#define FIFO_2_TO_3_OUT_USE_READ_CONTROL 1
#define FIFO_2_TO_3_OUT_USE_REGISTER 0
#define FIFO_2_TO_3_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_3_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_3_out_csr altera_avalon_fifo
#define FIFO_2_TO_3_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_3_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_3_OUT_CSR_BASE 0x1240
#define FIFO_2_TO_3_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_3_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_3_OUT_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_3_OUT_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_3_OUT_CSR_IRQ -1
#define FIFO_2_TO_3_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_3_OUT_CSR_NAME "/dev/fifo_2_to_3_out_csr"
#define FIFO_2_TO_3_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_3_OUT_CSR_SPAN 32
#define FIFO_2_TO_3_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_3_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_3_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_3_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_3_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_3_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_3_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_3_OUT_CSR_USE_IRQ 0
#define FIFO_2_TO_3_OUT_CSR_USE_PACKET 1
#define FIFO_2_TO_3_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_3_OUT_CSR_USE_REGISTER 0
#define FIFO_2_TO_3_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_0_in altera_avalon_fifo
#define FIFO_3_TO_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_0_IN_BASE 0x1350
#define FIFO_3_TO_0_IN_BITS_PER_SYMBOL 16
#define FIFO_3_TO_0_IN_CHANNEL_WIDTH 8
#define FIFO_3_TO_0_IN_ERROR_WIDTH 8
#define FIFO_3_TO_0_IN_FIFO_DEPTH 16
#define FIFO_3_TO_0_IN_IRQ -1
#define FIFO_3_TO_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_0_IN_NAME "/dev/fifo_3_to_0_in"
#define FIFO_3_TO_0_IN_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_0_IN_SPAN 4
#define FIFO_3_TO_0_IN_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_0_IN_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_0_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_0_IN_USE_AVALONST_SINK 0
#define FIFO_3_TO_0_IN_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_0_IN_USE_BACKPRESSURE 1
#define FIFO_3_TO_0_IN_USE_IRQ 0
#define FIFO_3_TO_0_IN_USE_PACKET 1
#define FIFO_3_TO_0_IN_USE_READ_CONTROL 1
#define FIFO_3_TO_0_IN_USE_REGISTER 0
#define FIFO_3_TO_0_IN_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_0_in_csr altera_avalon_fifo
#define FIFO_3_TO_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_0_IN_CSR_BASE 0x1220
#define FIFO_3_TO_0_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_0_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_0_IN_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_0_IN_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_0_IN_CSR_IRQ -1
#define FIFO_3_TO_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_0_IN_CSR_NAME "/dev/fifo_3_to_0_in_csr"
#define FIFO_3_TO_0_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_0_IN_CSR_SPAN 32
#define FIFO_3_TO_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_0_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_0_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_0_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_0_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_0_IN_CSR_USE_IRQ 0
#define FIFO_3_TO_0_IN_CSR_USE_PACKET 1
#define FIFO_3_TO_0_IN_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_0_IN_CSR_USE_REGISTER 0
#define FIFO_3_TO_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_1_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_1_in altera_avalon_fifo
#define FIFO_3_TO_1_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_1_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_1_IN_BASE 0x134c
#define FIFO_3_TO_1_IN_BITS_PER_SYMBOL 16
#define FIFO_3_TO_1_IN_CHANNEL_WIDTH 8
#define FIFO_3_TO_1_IN_ERROR_WIDTH 8
#define FIFO_3_TO_1_IN_FIFO_DEPTH 16
#define FIFO_3_TO_1_IN_IRQ -1
#define FIFO_3_TO_1_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_1_IN_NAME "/dev/fifo_3_to_1_in"
#define FIFO_3_TO_1_IN_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_1_IN_SPAN 4
#define FIFO_3_TO_1_IN_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_1_IN_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_1_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_1_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_1_IN_USE_AVALONST_SINK 0
#define FIFO_3_TO_1_IN_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_1_IN_USE_BACKPRESSURE 1
#define FIFO_3_TO_1_IN_USE_IRQ 0
#define FIFO_3_TO_1_IN_USE_PACKET 1
#define FIFO_3_TO_1_IN_USE_READ_CONTROL 1
#define FIFO_3_TO_1_IN_USE_REGISTER 0
#define FIFO_3_TO_1_IN_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_1_in_csr altera_avalon_fifo
#define FIFO_3_TO_1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_1_IN_CSR_BASE 0x1200
#define FIFO_3_TO_1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_1_IN_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_1_IN_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_1_IN_CSR_IRQ -1
#define FIFO_3_TO_1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_1_IN_CSR_NAME "/dev/fifo_3_to_1_in_csr"
#define FIFO_3_TO_1_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_1_IN_CSR_SPAN 32
#define FIFO_3_TO_1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_1_IN_CSR_USE_IRQ 0
#define FIFO_3_TO_1_IN_CSR_USE_PACKET 1
#define FIFO_3_TO_1_IN_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_1_IN_CSR_USE_REGISTER 0
#define FIFO_3_TO_1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_2_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_2_in altera_avalon_fifo
#define FIFO_3_TO_2_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_2_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_2_IN_BASE 0x1348
#define FIFO_3_TO_2_IN_BITS_PER_SYMBOL 16
#define FIFO_3_TO_2_IN_CHANNEL_WIDTH 8
#define FIFO_3_TO_2_IN_ERROR_WIDTH 8
#define FIFO_3_TO_2_IN_FIFO_DEPTH 16
#define FIFO_3_TO_2_IN_IRQ -1
#define FIFO_3_TO_2_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_2_IN_NAME "/dev/fifo_3_to_2_in"
#define FIFO_3_TO_2_IN_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_2_IN_SPAN 4
#define FIFO_3_TO_2_IN_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_2_IN_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_2_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_2_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_2_IN_USE_AVALONST_SINK 0
#define FIFO_3_TO_2_IN_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_2_IN_USE_BACKPRESSURE 1
#define FIFO_3_TO_2_IN_USE_IRQ 0
#define FIFO_3_TO_2_IN_USE_PACKET 1
#define FIFO_3_TO_2_IN_USE_READ_CONTROL 1
#define FIFO_3_TO_2_IN_USE_REGISTER 0
#define FIFO_3_TO_2_IN_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_2_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_2_in_csr altera_avalon_fifo
#define FIFO_3_TO_2_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_2_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_2_IN_CSR_BASE 0x11e0
#define FIFO_3_TO_2_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_2_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_2_IN_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_2_IN_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_2_IN_CSR_IRQ -1
#define FIFO_3_TO_2_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_2_IN_CSR_NAME "/dev/fifo_3_to_2_in_csr"
#define FIFO_3_TO_2_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_2_IN_CSR_SPAN 32
#define FIFO_3_TO_2_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_2_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_2_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_2_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_2_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_2_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_2_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_2_IN_CSR_USE_IRQ 0
#define FIFO_3_TO_2_IN_CSR_USE_PACKET 1
#define FIFO_3_TO_2_IN_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_2_IN_CSR_USE_REGISTER 0
#define FIFO_3_TO_2_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_4_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_4_in altera_avalon_fifo
#define FIFO_3_TO_4_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_4_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_4_IN_BASE 0x1344
#define FIFO_3_TO_4_IN_BITS_PER_SYMBOL 16
#define FIFO_3_TO_4_IN_CHANNEL_WIDTH 8
#define FIFO_3_TO_4_IN_ERROR_WIDTH 8
#define FIFO_3_TO_4_IN_FIFO_DEPTH 16
#define FIFO_3_TO_4_IN_IRQ -1
#define FIFO_3_TO_4_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_4_IN_NAME "/dev/fifo_3_to_4_in"
#define FIFO_3_TO_4_IN_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_4_IN_SPAN 4
#define FIFO_3_TO_4_IN_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_4_IN_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_4_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_4_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_4_IN_USE_AVALONST_SINK 0
#define FIFO_3_TO_4_IN_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_4_IN_USE_BACKPRESSURE 1
#define FIFO_3_TO_4_IN_USE_IRQ 0
#define FIFO_3_TO_4_IN_USE_PACKET 1
#define FIFO_3_TO_4_IN_USE_READ_CONTROL 1
#define FIFO_3_TO_4_IN_USE_REGISTER 0
#define FIFO_3_TO_4_IN_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_4_in_csr altera_avalon_fifo
#define FIFO_3_TO_4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_4_IN_CSR_BASE 0x11a0
#define FIFO_3_TO_4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_4_IN_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_4_IN_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_4_IN_CSR_IRQ -1
#define FIFO_3_TO_4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_4_IN_CSR_NAME "/dev/fifo_3_to_4_in_csr"
#define FIFO_3_TO_4_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_4_IN_CSR_SPAN 32
#define FIFO_3_TO_4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_4_IN_CSR_USE_IRQ 0
#define FIFO_3_TO_4_IN_CSR_USE_PACKET 1
#define FIFO_3_TO_4_IN_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_4_IN_CSR_USE_REGISTER 0
#define FIFO_3_TO_4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_5_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_5_in altera_avalon_fifo
#define FIFO_3_TO_5_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_5_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_5_IN_BASE 0x1340
#define FIFO_3_TO_5_IN_BITS_PER_SYMBOL 16
#define FIFO_3_TO_5_IN_CHANNEL_WIDTH 8
#define FIFO_3_TO_5_IN_ERROR_WIDTH 8
#define FIFO_3_TO_5_IN_FIFO_DEPTH 16
#define FIFO_3_TO_5_IN_IRQ -1
#define FIFO_3_TO_5_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_5_IN_NAME "/dev/fifo_3_to_5_in"
#define FIFO_3_TO_5_IN_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_5_IN_SPAN 4
#define FIFO_3_TO_5_IN_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_5_IN_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_5_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_5_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_5_IN_USE_AVALONST_SINK 0
#define FIFO_3_TO_5_IN_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_5_IN_USE_BACKPRESSURE 1
#define FIFO_3_TO_5_IN_USE_IRQ 0
#define FIFO_3_TO_5_IN_USE_PACKET 1
#define FIFO_3_TO_5_IN_USE_READ_CONTROL 1
#define FIFO_3_TO_5_IN_USE_REGISTER 0
#define FIFO_3_TO_5_IN_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_5_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_5_in_csr altera_avalon_fifo
#define FIFO_3_TO_5_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_5_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_5_IN_CSR_BASE 0x1180
#define FIFO_3_TO_5_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_5_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_5_IN_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_5_IN_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_5_IN_CSR_IRQ -1
#define FIFO_3_TO_5_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_5_IN_CSR_NAME "/dev/fifo_3_to_5_in_csr"
#define FIFO_3_TO_5_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_5_IN_CSR_SPAN 32
#define FIFO_3_TO_5_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_5_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_5_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_5_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_5_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_5_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_5_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_5_IN_CSR_USE_IRQ 0
#define FIFO_3_TO_5_IN_CSR_USE_PACKET 1
#define FIFO_3_TO_5_IN_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_5_IN_CSR_USE_REGISTER 0
#define FIFO_3_TO_5_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_6_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_6_in altera_avalon_fifo
#define FIFO_3_TO_6_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_6_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_6_IN_BASE 0x133c
#define FIFO_3_TO_6_IN_BITS_PER_SYMBOL 16
#define FIFO_3_TO_6_IN_CHANNEL_WIDTH 8
#define FIFO_3_TO_6_IN_ERROR_WIDTH 8
#define FIFO_3_TO_6_IN_FIFO_DEPTH 16
#define FIFO_3_TO_6_IN_IRQ -1
#define FIFO_3_TO_6_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_6_IN_NAME "/dev/fifo_3_to_6_in"
#define FIFO_3_TO_6_IN_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_6_IN_SPAN 4
#define FIFO_3_TO_6_IN_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_6_IN_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_6_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_6_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_6_IN_USE_AVALONST_SINK 0
#define FIFO_3_TO_6_IN_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_6_IN_USE_BACKPRESSURE 1
#define FIFO_3_TO_6_IN_USE_IRQ 0
#define FIFO_3_TO_6_IN_USE_PACKET 1
#define FIFO_3_TO_6_IN_USE_READ_CONTROL 1
#define FIFO_3_TO_6_IN_USE_REGISTER 0
#define FIFO_3_TO_6_IN_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_6_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_6_in_csr altera_avalon_fifo
#define FIFO_3_TO_6_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_6_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_6_IN_CSR_BASE 0x1160
#define FIFO_3_TO_6_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_6_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_6_IN_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_6_IN_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_6_IN_CSR_IRQ -1
#define FIFO_3_TO_6_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_6_IN_CSR_NAME "/dev/fifo_3_to_6_in_csr"
#define FIFO_3_TO_6_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_6_IN_CSR_SPAN 32
#define FIFO_3_TO_6_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_6_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_6_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_6_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_6_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_6_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_6_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_6_IN_CSR_USE_IRQ 0
#define FIFO_3_TO_6_IN_CSR_USE_PACKET 1
#define FIFO_3_TO_6_IN_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_6_IN_CSR_USE_REGISTER 0
#define FIFO_3_TO_6_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_7_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_7_in altera_avalon_fifo
#define FIFO_3_TO_7_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_7_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_7_IN_BASE 0x1338
#define FIFO_3_TO_7_IN_BITS_PER_SYMBOL 16
#define FIFO_3_TO_7_IN_CHANNEL_WIDTH 8
#define FIFO_3_TO_7_IN_ERROR_WIDTH 8
#define FIFO_3_TO_7_IN_FIFO_DEPTH 16
#define FIFO_3_TO_7_IN_IRQ -1
#define FIFO_3_TO_7_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_7_IN_NAME "/dev/fifo_3_to_7_in"
#define FIFO_3_TO_7_IN_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_7_IN_SPAN 4
#define FIFO_3_TO_7_IN_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_7_IN_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_7_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_7_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_7_IN_USE_AVALONST_SINK 0
#define FIFO_3_TO_7_IN_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_7_IN_USE_BACKPRESSURE 1
#define FIFO_3_TO_7_IN_USE_IRQ 0
#define FIFO_3_TO_7_IN_USE_PACKET 1
#define FIFO_3_TO_7_IN_USE_READ_CONTROL 1
#define FIFO_3_TO_7_IN_USE_REGISTER 0
#define FIFO_3_TO_7_IN_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_7_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_7_in_csr altera_avalon_fifo
#define FIFO_3_TO_7_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_7_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_7_IN_CSR_BASE 0x1140
#define FIFO_3_TO_7_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_7_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_7_IN_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_7_IN_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_7_IN_CSR_IRQ -1
#define FIFO_3_TO_7_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_7_IN_CSR_NAME "/dev/fifo_3_to_7_in_csr"
#define FIFO_3_TO_7_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_7_IN_CSR_SPAN 32
#define FIFO_3_TO_7_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_7_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_7_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_7_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_7_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_7_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_7_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_7_IN_CSR_USE_IRQ 0
#define FIFO_3_TO_7_IN_CSR_USE_PACKET 1
#define FIFO_3_TO_7_IN_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_7_IN_CSR_USE_REGISTER 0
#define FIFO_3_TO_7_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_3_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_3_out altera_avalon_fifo
#define FIFO_4_TO_3_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_3_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_3_OUT_BASE 0x1334
#define FIFO_4_TO_3_OUT_BITS_PER_SYMBOL 16
#define FIFO_4_TO_3_OUT_CHANNEL_WIDTH 8
#define FIFO_4_TO_3_OUT_ERROR_WIDTH 8
#define FIFO_4_TO_3_OUT_FIFO_DEPTH 16
#define FIFO_4_TO_3_OUT_IRQ -1
#define FIFO_4_TO_3_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_3_OUT_NAME "/dev/fifo_4_to_3_out"
#define FIFO_4_TO_3_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_3_OUT_SPAN 4
#define FIFO_4_TO_3_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_3_OUT_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_3_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_3_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_3_OUT_USE_AVALONST_SINK 0
#define FIFO_4_TO_3_OUT_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_3_OUT_USE_BACKPRESSURE 1
#define FIFO_4_TO_3_OUT_USE_IRQ 0
#define FIFO_4_TO_3_OUT_USE_PACKET 1
#define FIFO_4_TO_3_OUT_USE_READ_CONTROL 1
#define FIFO_4_TO_3_OUT_USE_REGISTER 0
#define FIFO_4_TO_3_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_3_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_3_out_csr altera_avalon_fifo
#define FIFO_4_TO_3_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_3_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_3_OUT_CSR_BASE 0x1120
#define FIFO_4_TO_3_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_3_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_3_OUT_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_3_OUT_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_3_OUT_CSR_IRQ -1
#define FIFO_4_TO_3_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_3_OUT_CSR_NAME "/dev/fifo_4_to_3_out_csr"
#define FIFO_4_TO_3_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_3_OUT_CSR_SPAN 32
#define FIFO_4_TO_3_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_3_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_3_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_3_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_3_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_3_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_3_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_3_OUT_CSR_USE_IRQ 0
#define FIFO_4_TO_3_OUT_CSR_USE_PACKET 1
#define FIFO_4_TO_3_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_3_OUT_CSR_USE_REGISTER 0
#define FIFO_4_TO_3_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_3_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_3_out altera_avalon_fifo
#define FIFO_5_TO_3_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_3_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_3_OUT_BASE 0x1330
#define FIFO_5_TO_3_OUT_BITS_PER_SYMBOL 16
#define FIFO_5_TO_3_OUT_CHANNEL_WIDTH 8
#define FIFO_5_TO_3_OUT_ERROR_WIDTH 8
#define FIFO_5_TO_3_OUT_FIFO_DEPTH 16
#define FIFO_5_TO_3_OUT_IRQ -1
#define FIFO_5_TO_3_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_3_OUT_NAME "/dev/fifo_5_to_3_out"
#define FIFO_5_TO_3_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_3_OUT_SPAN 4
#define FIFO_5_TO_3_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_3_OUT_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_3_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_3_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_3_OUT_USE_AVALONST_SINK 0
#define FIFO_5_TO_3_OUT_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_3_OUT_USE_BACKPRESSURE 1
#define FIFO_5_TO_3_OUT_USE_IRQ 0
#define FIFO_5_TO_3_OUT_USE_PACKET 1
#define FIFO_5_TO_3_OUT_USE_READ_CONTROL 1
#define FIFO_5_TO_3_OUT_USE_REGISTER 0
#define FIFO_5_TO_3_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_3_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_3_out_csr altera_avalon_fifo
#define FIFO_5_TO_3_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_3_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_3_OUT_CSR_BASE 0x1100
#define FIFO_5_TO_3_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_3_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_3_OUT_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_3_OUT_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_3_OUT_CSR_IRQ -1
#define FIFO_5_TO_3_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_3_OUT_CSR_NAME "/dev/fifo_5_to_3_out_csr"
#define FIFO_5_TO_3_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_3_OUT_CSR_SPAN 32
#define FIFO_5_TO_3_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_3_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_3_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_3_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_3_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_3_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_3_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_3_OUT_CSR_USE_IRQ 0
#define FIFO_5_TO_3_OUT_CSR_USE_PACKET 1
#define FIFO_5_TO_3_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_3_OUT_CSR_USE_REGISTER 0
#define FIFO_5_TO_3_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_3_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_3_out altera_avalon_fifo
#define FIFO_6_TO_3_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_3_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_3_OUT_BASE 0x132c
#define FIFO_6_TO_3_OUT_BITS_PER_SYMBOL 16
#define FIFO_6_TO_3_OUT_CHANNEL_WIDTH 8
#define FIFO_6_TO_3_OUT_ERROR_WIDTH 8
#define FIFO_6_TO_3_OUT_FIFO_DEPTH 16
#define FIFO_6_TO_3_OUT_IRQ -1
#define FIFO_6_TO_3_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_3_OUT_NAME "/dev/fifo_6_to_3_out"
#define FIFO_6_TO_3_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_3_OUT_SPAN 4
#define FIFO_6_TO_3_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_3_OUT_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_3_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_3_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_3_OUT_USE_AVALONST_SINK 0
#define FIFO_6_TO_3_OUT_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_3_OUT_USE_BACKPRESSURE 1
#define FIFO_6_TO_3_OUT_USE_IRQ 0
#define FIFO_6_TO_3_OUT_USE_PACKET 1
#define FIFO_6_TO_3_OUT_USE_READ_CONTROL 1
#define FIFO_6_TO_3_OUT_USE_REGISTER 0
#define FIFO_6_TO_3_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_3_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_3_out_csr altera_avalon_fifo
#define FIFO_6_TO_3_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_3_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_3_OUT_CSR_BASE 0x10e0
#define FIFO_6_TO_3_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_3_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_3_OUT_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_3_OUT_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_3_OUT_CSR_IRQ -1
#define FIFO_6_TO_3_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_3_OUT_CSR_NAME "/dev/fifo_6_to_3_out_csr"
#define FIFO_6_TO_3_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_3_OUT_CSR_SPAN 32
#define FIFO_6_TO_3_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_3_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_3_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_3_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_3_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_3_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_3_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_3_OUT_CSR_USE_IRQ 0
#define FIFO_6_TO_3_OUT_CSR_USE_PACKET 1
#define FIFO_6_TO_3_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_3_OUT_CSR_USE_REGISTER 0
#define FIFO_6_TO_3_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_3_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_3_out altera_avalon_fifo
#define FIFO_7_TO_3_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_3_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_3_OUT_BASE 0x1328
#define FIFO_7_TO_3_OUT_BITS_PER_SYMBOL 16
#define FIFO_7_TO_3_OUT_CHANNEL_WIDTH 8
#define FIFO_7_TO_3_OUT_ERROR_WIDTH 8
#define FIFO_7_TO_3_OUT_FIFO_DEPTH 16
#define FIFO_7_TO_3_OUT_IRQ -1
#define FIFO_7_TO_3_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_3_OUT_NAME "/dev/fifo_7_to_3_out"
#define FIFO_7_TO_3_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_3_OUT_SPAN 4
#define FIFO_7_TO_3_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_3_OUT_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_3_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_3_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_3_OUT_USE_AVALONST_SINK 0
#define FIFO_7_TO_3_OUT_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_3_OUT_USE_BACKPRESSURE 1
#define FIFO_7_TO_3_OUT_USE_IRQ 0
#define FIFO_7_TO_3_OUT_USE_PACKET 1
#define FIFO_7_TO_3_OUT_USE_READ_CONTROL 1
#define FIFO_7_TO_3_OUT_USE_REGISTER 0
#define FIFO_7_TO_3_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_3_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_3_out_csr altera_avalon_fifo
#define FIFO_7_TO_3_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_3_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_3_OUT_CSR_BASE 0x10c0
#define FIFO_7_TO_3_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_3_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_3_OUT_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_3_OUT_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_3_OUT_CSR_IRQ -1
#define FIFO_7_TO_3_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_3_OUT_CSR_NAME "/dev/fifo_7_to_3_out_csr"
#define FIFO_7_TO_3_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_3_OUT_CSR_SPAN 32
#define FIFO_7_TO_3_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_3_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_3_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_3_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_3_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_3_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_3_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_3_OUT_CSR_USE_IRQ 0
#define FIFO_7_TO_3_OUT_CSR_USE_PACKET 1
#define FIFO_7_TO_3_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_3_OUT_CSR_USE_REGISTER 0
#define FIFO_7_TO_3_OUT_CSR_USE_WRITE_CONTROL 1



/********************/
/* system.h - CPU 4 */
/********************/


/*
 * fifo_0_to_4_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_4_out altera_avalon_fifo
#define FIFO_0_TO_4_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_4_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_4_OUT_BASE 0x135c
#define FIFO_0_TO_4_OUT_BITS_PER_SYMBOL 16
#define FIFO_0_TO_4_OUT_CHANNEL_WIDTH 8
#define FIFO_0_TO_4_OUT_ERROR_WIDTH 8
#define FIFO_0_TO_4_OUT_FIFO_DEPTH 16
#define FIFO_0_TO_4_OUT_IRQ -1
#define FIFO_0_TO_4_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_4_OUT_NAME "/dev/fifo_0_to_4_out"
#define FIFO_0_TO_4_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_4_OUT_SPAN 4
#define FIFO_0_TO_4_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_4_OUT_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_4_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_4_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_4_OUT_USE_AVALONST_SINK 0
#define FIFO_0_TO_4_OUT_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_4_OUT_USE_BACKPRESSURE 1
#define FIFO_0_TO_4_OUT_USE_IRQ 0
#define FIFO_0_TO_4_OUT_USE_PACKET 1
#define FIFO_0_TO_4_OUT_USE_READ_CONTROL 1
#define FIFO_0_TO_4_OUT_USE_REGISTER 0
#define FIFO_0_TO_4_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_4_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_4_out_csr altera_avalon_fifo
#define FIFO_0_TO_4_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_4_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_4_OUT_CSR_BASE 0x1280
#define FIFO_0_TO_4_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_4_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_4_OUT_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_4_OUT_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_4_OUT_CSR_IRQ -1
#define FIFO_0_TO_4_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_4_OUT_CSR_NAME "/dev/fifo_0_to_4_out_csr"
#define FIFO_0_TO_4_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_4_OUT_CSR_SPAN 32
#define FIFO_0_TO_4_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_4_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_4_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_4_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_4_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_4_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_4_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_4_OUT_CSR_USE_IRQ 0
#define FIFO_0_TO_4_OUT_CSR_USE_PACKET 1
#define FIFO_0_TO_4_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_4_OUT_CSR_USE_REGISTER 0
#define FIFO_0_TO_4_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_4_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_4_out altera_avalon_fifo
#define FIFO_1_TO_4_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_4_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_4_OUT_BASE 0x1358
#define FIFO_1_TO_4_OUT_BITS_PER_SYMBOL 16
#define FIFO_1_TO_4_OUT_CHANNEL_WIDTH 8
#define FIFO_1_TO_4_OUT_ERROR_WIDTH 8
#define FIFO_1_TO_4_OUT_FIFO_DEPTH 16
#define FIFO_1_TO_4_OUT_IRQ -1
#define FIFO_1_TO_4_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_4_OUT_NAME "/dev/fifo_1_to_4_out"
#define FIFO_1_TO_4_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_4_OUT_SPAN 4
#define FIFO_1_TO_4_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_4_OUT_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_4_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_4_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_4_OUT_USE_AVALONST_SINK 0
#define FIFO_1_TO_4_OUT_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_4_OUT_USE_BACKPRESSURE 1
#define FIFO_1_TO_4_OUT_USE_IRQ 0
#define FIFO_1_TO_4_OUT_USE_PACKET 1
#define FIFO_1_TO_4_OUT_USE_READ_CONTROL 1
#define FIFO_1_TO_4_OUT_USE_REGISTER 0
#define FIFO_1_TO_4_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_4_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_4_out_csr altera_avalon_fifo
#define FIFO_1_TO_4_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_4_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_4_OUT_CSR_BASE 0x1260
#define FIFO_1_TO_4_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_4_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_4_OUT_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_4_OUT_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_4_OUT_CSR_IRQ -1
#define FIFO_1_TO_4_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_4_OUT_CSR_NAME "/dev/fifo_1_to_4_out_csr"
#define FIFO_1_TO_4_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_4_OUT_CSR_SPAN 32
#define FIFO_1_TO_4_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_4_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_4_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_4_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_4_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_4_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_4_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_4_OUT_CSR_USE_IRQ 0
#define FIFO_1_TO_4_OUT_CSR_USE_PACKET 1
#define FIFO_1_TO_4_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_4_OUT_CSR_USE_REGISTER 0
#define FIFO_1_TO_4_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_4_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_4_out altera_avalon_fifo
#define FIFO_2_TO_4_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_4_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_4_OUT_BASE 0x1354
#define FIFO_2_TO_4_OUT_BITS_PER_SYMBOL 16
#define FIFO_2_TO_4_OUT_CHANNEL_WIDTH 8
#define FIFO_2_TO_4_OUT_ERROR_WIDTH 8
#define FIFO_2_TO_4_OUT_FIFO_DEPTH 16
#define FIFO_2_TO_4_OUT_IRQ -1
#define FIFO_2_TO_4_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_4_OUT_NAME "/dev/fifo_2_to_4_out"
#define FIFO_2_TO_4_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_4_OUT_SPAN 4
#define FIFO_2_TO_4_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_4_OUT_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_4_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_4_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_4_OUT_USE_AVALONST_SINK 0
#define FIFO_2_TO_4_OUT_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_4_OUT_USE_BACKPRESSURE 1
#define FIFO_2_TO_4_OUT_USE_IRQ 0
#define FIFO_2_TO_4_OUT_USE_PACKET 1
#define FIFO_2_TO_4_OUT_USE_READ_CONTROL 1
#define FIFO_2_TO_4_OUT_USE_REGISTER 0
#define FIFO_2_TO_4_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_4_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_4_out_csr altera_avalon_fifo
#define FIFO_2_TO_4_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_4_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_4_OUT_CSR_BASE 0x1240
#define FIFO_2_TO_4_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_4_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_4_OUT_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_4_OUT_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_4_OUT_CSR_IRQ -1
#define FIFO_2_TO_4_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_4_OUT_CSR_NAME "/dev/fifo_2_to_4_out_csr"
#define FIFO_2_TO_4_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_4_OUT_CSR_SPAN 32
#define FIFO_2_TO_4_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_4_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_4_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_4_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_4_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_4_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_4_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_4_OUT_CSR_USE_IRQ 0
#define FIFO_2_TO_4_OUT_CSR_USE_PACKET 1
#define FIFO_2_TO_4_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_4_OUT_CSR_USE_REGISTER 0
#define FIFO_2_TO_4_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_4_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_4_out altera_avalon_fifo
#define FIFO_3_TO_4_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_4_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_4_OUT_BASE 0x1350
#define FIFO_3_TO_4_OUT_BITS_PER_SYMBOL 16
#define FIFO_3_TO_4_OUT_CHANNEL_WIDTH 8
#define FIFO_3_TO_4_OUT_ERROR_WIDTH 8
#define FIFO_3_TO_4_OUT_FIFO_DEPTH 16
#define FIFO_3_TO_4_OUT_IRQ -1
#define FIFO_3_TO_4_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_4_OUT_NAME "/dev/fifo_3_to_4_out"
#define FIFO_3_TO_4_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_4_OUT_SPAN 4
#define FIFO_3_TO_4_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_4_OUT_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_4_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_4_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_4_OUT_USE_AVALONST_SINK 0
#define FIFO_3_TO_4_OUT_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_4_OUT_USE_BACKPRESSURE 1
#define FIFO_3_TO_4_OUT_USE_IRQ 0
#define FIFO_3_TO_4_OUT_USE_PACKET 1
#define FIFO_3_TO_4_OUT_USE_READ_CONTROL 1
#define FIFO_3_TO_4_OUT_USE_REGISTER 0
#define FIFO_3_TO_4_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_4_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_4_out_csr altera_avalon_fifo
#define FIFO_3_TO_4_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_4_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_4_OUT_CSR_BASE 0x1220
#define FIFO_3_TO_4_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_4_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_4_OUT_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_4_OUT_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_4_OUT_CSR_IRQ -1
#define FIFO_3_TO_4_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_4_OUT_CSR_NAME "/dev/fifo_3_to_4_out_csr"
#define FIFO_3_TO_4_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_4_OUT_CSR_SPAN 32
#define FIFO_3_TO_4_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_4_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_4_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_4_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_4_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_4_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_4_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_4_OUT_CSR_USE_IRQ 0
#define FIFO_3_TO_4_OUT_CSR_USE_PACKET 1
#define FIFO_3_TO_4_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_4_OUT_CSR_USE_REGISTER 0
#define FIFO_3_TO_4_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_0_in altera_avalon_fifo
#define FIFO_4_TO_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_0_IN_BASE 0x134c
#define FIFO_4_TO_0_IN_BITS_PER_SYMBOL 16
#define FIFO_4_TO_0_IN_CHANNEL_WIDTH 8
#define FIFO_4_TO_0_IN_ERROR_WIDTH 8
#define FIFO_4_TO_0_IN_FIFO_DEPTH 16
#define FIFO_4_TO_0_IN_IRQ -1
#define FIFO_4_TO_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_0_IN_NAME "/dev/fifo_4_to_0_in"
#define FIFO_4_TO_0_IN_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_0_IN_SPAN 4
#define FIFO_4_TO_0_IN_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_0_IN_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_0_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_0_IN_USE_AVALONST_SINK 0
#define FIFO_4_TO_0_IN_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_0_IN_USE_BACKPRESSURE 1
#define FIFO_4_TO_0_IN_USE_IRQ 0
#define FIFO_4_TO_0_IN_USE_PACKET 1
#define FIFO_4_TO_0_IN_USE_READ_CONTROL 1
#define FIFO_4_TO_0_IN_USE_REGISTER 0
#define FIFO_4_TO_0_IN_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_0_in_csr altera_avalon_fifo
#define FIFO_4_TO_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_0_IN_CSR_BASE 0x1200
#define FIFO_4_TO_0_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_0_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_0_IN_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_0_IN_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_0_IN_CSR_IRQ -1
#define FIFO_4_TO_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_0_IN_CSR_NAME "/dev/fifo_4_to_0_in_csr"
#define FIFO_4_TO_0_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_0_IN_CSR_SPAN 32
#define FIFO_4_TO_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_0_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_0_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_0_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_0_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_0_IN_CSR_USE_IRQ 0
#define FIFO_4_TO_0_IN_CSR_USE_PACKET 1
#define FIFO_4_TO_0_IN_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_0_IN_CSR_USE_REGISTER 0
#define FIFO_4_TO_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_1_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_1_in altera_avalon_fifo
#define FIFO_4_TO_1_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_1_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_1_IN_BASE 0x1348
#define FIFO_4_TO_1_IN_BITS_PER_SYMBOL 16
#define FIFO_4_TO_1_IN_CHANNEL_WIDTH 8
#define FIFO_4_TO_1_IN_ERROR_WIDTH 8
#define FIFO_4_TO_1_IN_FIFO_DEPTH 16
#define FIFO_4_TO_1_IN_IRQ -1
#define FIFO_4_TO_1_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_1_IN_NAME "/dev/fifo_4_to_1_in"
#define FIFO_4_TO_1_IN_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_1_IN_SPAN 4
#define FIFO_4_TO_1_IN_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_1_IN_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_1_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_1_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_1_IN_USE_AVALONST_SINK 0
#define FIFO_4_TO_1_IN_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_1_IN_USE_BACKPRESSURE 1
#define FIFO_4_TO_1_IN_USE_IRQ 0
#define FIFO_4_TO_1_IN_USE_PACKET 1
#define FIFO_4_TO_1_IN_USE_READ_CONTROL 1
#define FIFO_4_TO_1_IN_USE_REGISTER 0
#define FIFO_4_TO_1_IN_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_1_in_csr altera_avalon_fifo
#define FIFO_4_TO_1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_1_IN_CSR_BASE 0x11e0
#define FIFO_4_TO_1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_1_IN_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_1_IN_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_1_IN_CSR_IRQ -1
#define FIFO_4_TO_1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_1_IN_CSR_NAME "/dev/fifo_4_to_1_in_csr"
#define FIFO_4_TO_1_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_1_IN_CSR_SPAN 32
#define FIFO_4_TO_1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_1_IN_CSR_USE_IRQ 0
#define FIFO_4_TO_1_IN_CSR_USE_PACKET 1
#define FIFO_4_TO_1_IN_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_1_IN_CSR_USE_REGISTER 0
#define FIFO_4_TO_1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_2_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_2_in altera_avalon_fifo
#define FIFO_4_TO_2_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_2_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_2_IN_BASE 0x1344
#define FIFO_4_TO_2_IN_BITS_PER_SYMBOL 16
#define FIFO_4_TO_2_IN_CHANNEL_WIDTH 8
#define FIFO_4_TO_2_IN_ERROR_WIDTH 8
#define FIFO_4_TO_2_IN_FIFO_DEPTH 16
#define FIFO_4_TO_2_IN_IRQ -1
#define FIFO_4_TO_2_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_2_IN_NAME "/dev/fifo_4_to_2_in"
#define FIFO_4_TO_2_IN_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_2_IN_SPAN 4
#define FIFO_4_TO_2_IN_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_2_IN_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_2_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_2_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_2_IN_USE_AVALONST_SINK 0
#define FIFO_4_TO_2_IN_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_2_IN_USE_BACKPRESSURE 1
#define FIFO_4_TO_2_IN_USE_IRQ 0
#define FIFO_4_TO_2_IN_USE_PACKET 1
#define FIFO_4_TO_2_IN_USE_READ_CONTROL 1
#define FIFO_4_TO_2_IN_USE_REGISTER 0
#define FIFO_4_TO_2_IN_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_2_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_2_in_csr altera_avalon_fifo
#define FIFO_4_TO_2_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_2_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_2_IN_CSR_BASE 0x11a0
#define FIFO_4_TO_2_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_2_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_2_IN_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_2_IN_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_2_IN_CSR_IRQ -1
#define FIFO_4_TO_2_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_2_IN_CSR_NAME "/dev/fifo_4_to_2_in_csr"
#define FIFO_4_TO_2_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_2_IN_CSR_SPAN 32
#define FIFO_4_TO_2_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_2_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_2_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_2_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_2_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_2_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_2_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_2_IN_CSR_USE_IRQ 0
#define FIFO_4_TO_2_IN_CSR_USE_PACKET 1
#define FIFO_4_TO_2_IN_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_2_IN_CSR_USE_REGISTER 0
#define FIFO_4_TO_2_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_3_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_3_in altera_avalon_fifo
#define FIFO_4_TO_3_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_3_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_3_IN_BASE 0x1340
#define FIFO_4_TO_3_IN_BITS_PER_SYMBOL 16
#define FIFO_4_TO_3_IN_CHANNEL_WIDTH 8
#define FIFO_4_TO_3_IN_ERROR_WIDTH 8
#define FIFO_4_TO_3_IN_FIFO_DEPTH 16
#define FIFO_4_TO_3_IN_IRQ -1
#define FIFO_4_TO_3_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_3_IN_NAME "/dev/fifo_4_to_3_in"
#define FIFO_4_TO_3_IN_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_3_IN_SPAN 4
#define FIFO_4_TO_3_IN_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_3_IN_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_3_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_3_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_3_IN_USE_AVALONST_SINK 0
#define FIFO_4_TO_3_IN_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_3_IN_USE_BACKPRESSURE 1
#define FIFO_4_TO_3_IN_USE_IRQ 0
#define FIFO_4_TO_3_IN_USE_PACKET 1
#define FIFO_4_TO_3_IN_USE_READ_CONTROL 1
#define FIFO_4_TO_3_IN_USE_REGISTER 0
#define FIFO_4_TO_3_IN_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_3_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_3_in_csr altera_avalon_fifo
#define FIFO_4_TO_3_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_3_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_3_IN_CSR_BASE 0x1180
#define FIFO_4_TO_3_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_3_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_3_IN_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_3_IN_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_3_IN_CSR_IRQ -1
#define FIFO_4_TO_3_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_3_IN_CSR_NAME "/dev/fifo_4_to_3_in_csr"
#define FIFO_4_TO_3_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_3_IN_CSR_SPAN 32
#define FIFO_4_TO_3_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_3_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_3_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_3_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_3_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_3_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_3_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_3_IN_CSR_USE_IRQ 0
#define FIFO_4_TO_3_IN_CSR_USE_PACKET 1
#define FIFO_4_TO_3_IN_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_3_IN_CSR_USE_REGISTER 0
#define FIFO_4_TO_3_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_5_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_5_in altera_avalon_fifo
#define FIFO_4_TO_5_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_5_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_5_IN_BASE 0x133c
#define FIFO_4_TO_5_IN_BITS_PER_SYMBOL 16
#define FIFO_4_TO_5_IN_CHANNEL_WIDTH 8
#define FIFO_4_TO_5_IN_ERROR_WIDTH 8
#define FIFO_4_TO_5_IN_FIFO_DEPTH 16
#define FIFO_4_TO_5_IN_IRQ -1
#define FIFO_4_TO_5_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_5_IN_NAME "/dev/fifo_4_to_5_in"
#define FIFO_4_TO_5_IN_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_5_IN_SPAN 4
#define FIFO_4_TO_5_IN_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_5_IN_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_5_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_5_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_5_IN_USE_AVALONST_SINK 0
#define FIFO_4_TO_5_IN_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_5_IN_USE_BACKPRESSURE 1
#define FIFO_4_TO_5_IN_USE_IRQ 0
#define FIFO_4_TO_5_IN_USE_PACKET 1
#define FIFO_4_TO_5_IN_USE_READ_CONTROL 1
#define FIFO_4_TO_5_IN_USE_REGISTER 0
#define FIFO_4_TO_5_IN_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_5_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_5_in_csr altera_avalon_fifo
#define FIFO_4_TO_5_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_5_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_5_IN_CSR_BASE 0x1160
#define FIFO_4_TO_5_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_5_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_5_IN_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_5_IN_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_5_IN_CSR_IRQ -1
#define FIFO_4_TO_5_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_5_IN_CSR_NAME "/dev/fifo_4_to_5_in_csr"
#define FIFO_4_TO_5_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_5_IN_CSR_SPAN 32
#define FIFO_4_TO_5_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_5_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_5_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_5_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_5_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_5_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_5_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_5_IN_CSR_USE_IRQ 0
#define FIFO_4_TO_5_IN_CSR_USE_PACKET 1
#define FIFO_4_TO_5_IN_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_5_IN_CSR_USE_REGISTER 0
#define FIFO_4_TO_5_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_6_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_6_in altera_avalon_fifo
#define FIFO_4_TO_6_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_6_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_6_IN_BASE 0x1338
#define FIFO_4_TO_6_IN_BITS_PER_SYMBOL 16
#define FIFO_4_TO_6_IN_CHANNEL_WIDTH 8
#define FIFO_4_TO_6_IN_ERROR_WIDTH 8
#define FIFO_4_TO_6_IN_FIFO_DEPTH 16
#define FIFO_4_TO_6_IN_IRQ -1
#define FIFO_4_TO_6_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_6_IN_NAME "/dev/fifo_4_to_6_in"
#define FIFO_4_TO_6_IN_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_6_IN_SPAN 4
#define FIFO_4_TO_6_IN_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_6_IN_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_6_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_6_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_6_IN_USE_AVALONST_SINK 0
#define FIFO_4_TO_6_IN_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_6_IN_USE_BACKPRESSURE 1
#define FIFO_4_TO_6_IN_USE_IRQ 0
#define FIFO_4_TO_6_IN_USE_PACKET 1
#define FIFO_4_TO_6_IN_USE_READ_CONTROL 1
#define FIFO_4_TO_6_IN_USE_REGISTER 0
#define FIFO_4_TO_6_IN_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_6_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_6_in_csr altera_avalon_fifo
#define FIFO_4_TO_6_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_6_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_6_IN_CSR_BASE 0x1140
#define FIFO_4_TO_6_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_6_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_6_IN_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_6_IN_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_6_IN_CSR_IRQ -1
#define FIFO_4_TO_6_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_6_IN_CSR_NAME "/dev/fifo_4_to_6_in_csr"
#define FIFO_4_TO_6_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_6_IN_CSR_SPAN 32
#define FIFO_4_TO_6_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_6_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_6_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_6_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_6_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_6_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_6_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_6_IN_CSR_USE_IRQ 0
#define FIFO_4_TO_6_IN_CSR_USE_PACKET 1
#define FIFO_4_TO_6_IN_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_6_IN_CSR_USE_REGISTER 0
#define FIFO_4_TO_6_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_7_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_7_in altera_avalon_fifo
#define FIFO_4_TO_7_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_7_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_7_IN_BASE 0x1334
#define FIFO_4_TO_7_IN_BITS_PER_SYMBOL 16
#define FIFO_4_TO_7_IN_CHANNEL_WIDTH 8
#define FIFO_4_TO_7_IN_ERROR_WIDTH 8
#define FIFO_4_TO_7_IN_FIFO_DEPTH 16
#define FIFO_4_TO_7_IN_IRQ -1
#define FIFO_4_TO_7_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_7_IN_NAME "/dev/fifo_4_to_7_in"
#define FIFO_4_TO_7_IN_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_7_IN_SPAN 4
#define FIFO_4_TO_7_IN_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_7_IN_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_7_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_7_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_7_IN_USE_AVALONST_SINK 0
#define FIFO_4_TO_7_IN_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_7_IN_USE_BACKPRESSURE 1
#define FIFO_4_TO_7_IN_USE_IRQ 0
#define FIFO_4_TO_7_IN_USE_PACKET 1
#define FIFO_4_TO_7_IN_USE_READ_CONTROL 1
#define FIFO_4_TO_7_IN_USE_REGISTER 0
#define FIFO_4_TO_7_IN_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_7_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_7_in_csr altera_avalon_fifo
#define FIFO_4_TO_7_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_7_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_7_IN_CSR_BASE 0x1120
#define FIFO_4_TO_7_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_7_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_7_IN_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_7_IN_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_7_IN_CSR_IRQ -1
#define FIFO_4_TO_7_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_7_IN_CSR_NAME "/dev/fifo_4_to_7_in_csr"
#define FIFO_4_TO_7_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_7_IN_CSR_SPAN 32
#define FIFO_4_TO_7_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_7_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_7_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_7_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_7_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_7_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_7_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_7_IN_CSR_USE_IRQ 0
#define FIFO_4_TO_7_IN_CSR_USE_PACKET 1
#define FIFO_4_TO_7_IN_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_7_IN_CSR_USE_REGISTER 0
#define FIFO_4_TO_7_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_4_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_4_out altera_avalon_fifo
#define FIFO_5_TO_4_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_4_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_4_OUT_BASE 0x1330
#define FIFO_5_TO_4_OUT_BITS_PER_SYMBOL 16
#define FIFO_5_TO_4_OUT_CHANNEL_WIDTH 8
#define FIFO_5_TO_4_OUT_ERROR_WIDTH 8
#define FIFO_5_TO_4_OUT_FIFO_DEPTH 16
#define FIFO_5_TO_4_OUT_IRQ -1
#define FIFO_5_TO_4_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_4_OUT_NAME "/dev/fifo_5_to_4_out"
#define FIFO_5_TO_4_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_4_OUT_SPAN 4
#define FIFO_5_TO_4_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_4_OUT_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_4_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_4_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_4_OUT_USE_AVALONST_SINK 0
#define FIFO_5_TO_4_OUT_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_4_OUT_USE_BACKPRESSURE 1
#define FIFO_5_TO_4_OUT_USE_IRQ 0
#define FIFO_5_TO_4_OUT_USE_PACKET 1
#define FIFO_5_TO_4_OUT_USE_READ_CONTROL 1
#define FIFO_5_TO_4_OUT_USE_REGISTER 0
#define FIFO_5_TO_4_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_4_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_4_out_csr altera_avalon_fifo
#define FIFO_5_TO_4_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_4_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_4_OUT_CSR_BASE 0x1100
#define FIFO_5_TO_4_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_4_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_4_OUT_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_4_OUT_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_4_OUT_CSR_IRQ -1
#define FIFO_5_TO_4_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_4_OUT_CSR_NAME "/dev/fifo_5_to_4_out_csr"
#define FIFO_5_TO_4_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_4_OUT_CSR_SPAN 32
#define FIFO_5_TO_4_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_4_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_4_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_4_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_4_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_4_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_4_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_4_OUT_CSR_USE_IRQ 0
#define FIFO_5_TO_4_OUT_CSR_USE_PACKET 1
#define FIFO_5_TO_4_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_4_OUT_CSR_USE_REGISTER 0
#define FIFO_5_TO_4_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_4_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_4_out altera_avalon_fifo
#define FIFO_6_TO_4_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_4_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_4_OUT_BASE 0x132c
#define FIFO_6_TO_4_OUT_BITS_PER_SYMBOL 16
#define FIFO_6_TO_4_OUT_CHANNEL_WIDTH 8
#define FIFO_6_TO_4_OUT_ERROR_WIDTH 8
#define FIFO_6_TO_4_OUT_FIFO_DEPTH 16
#define FIFO_6_TO_4_OUT_IRQ -1
#define FIFO_6_TO_4_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_4_OUT_NAME "/dev/fifo_6_to_4_out"
#define FIFO_6_TO_4_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_4_OUT_SPAN 4
#define FIFO_6_TO_4_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_4_OUT_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_4_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_4_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_4_OUT_USE_AVALONST_SINK 0
#define FIFO_6_TO_4_OUT_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_4_OUT_USE_BACKPRESSURE 1
#define FIFO_6_TO_4_OUT_USE_IRQ 0
#define FIFO_6_TO_4_OUT_USE_PACKET 1
#define FIFO_6_TO_4_OUT_USE_READ_CONTROL 1
#define FIFO_6_TO_4_OUT_USE_REGISTER 0
#define FIFO_6_TO_4_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_4_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_4_out_csr altera_avalon_fifo
#define FIFO_6_TO_4_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_4_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_4_OUT_CSR_BASE 0x10e0
#define FIFO_6_TO_4_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_4_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_4_OUT_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_4_OUT_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_4_OUT_CSR_IRQ -1
#define FIFO_6_TO_4_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_4_OUT_CSR_NAME "/dev/fifo_6_to_4_out_csr"
#define FIFO_6_TO_4_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_4_OUT_CSR_SPAN 32
#define FIFO_6_TO_4_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_4_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_4_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_4_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_4_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_4_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_4_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_4_OUT_CSR_USE_IRQ 0
#define FIFO_6_TO_4_OUT_CSR_USE_PACKET 1
#define FIFO_6_TO_4_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_4_OUT_CSR_USE_REGISTER 0
#define FIFO_6_TO_4_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_4_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_4_out altera_avalon_fifo
#define FIFO_7_TO_4_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_4_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_4_OUT_BASE 0x1328
#define FIFO_7_TO_4_OUT_BITS_PER_SYMBOL 16
#define FIFO_7_TO_4_OUT_CHANNEL_WIDTH 8
#define FIFO_7_TO_4_OUT_ERROR_WIDTH 8
#define FIFO_7_TO_4_OUT_FIFO_DEPTH 16
#define FIFO_7_TO_4_OUT_IRQ -1
#define FIFO_7_TO_4_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_4_OUT_NAME "/dev/fifo_7_to_4_out"
#define FIFO_7_TO_4_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_4_OUT_SPAN 4
#define FIFO_7_TO_4_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_4_OUT_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_4_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_4_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_4_OUT_USE_AVALONST_SINK 0
#define FIFO_7_TO_4_OUT_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_4_OUT_USE_BACKPRESSURE 1
#define FIFO_7_TO_4_OUT_USE_IRQ 0
#define FIFO_7_TO_4_OUT_USE_PACKET 1
#define FIFO_7_TO_4_OUT_USE_READ_CONTROL 1
#define FIFO_7_TO_4_OUT_USE_REGISTER 0
#define FIFO_7_TO_4_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_4_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_4_out_csr altera_avalon_fifo
#define FIFO_7_TO_4_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_4_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_4_OUT_CSR_BASE 0x10c0
#define FIFO_7_TO_4_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_4_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_4_OUT_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_4_OUT_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_4_OUT_CSR_IRQ -1
#define FIFO_7_TO_4_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_4_OUT_CSR_NAME "/dev/fifo_7_to_4_out_csr"
#define FIFO_7_TO_4_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_4_OUT_CSR_SPAN 32
#define FIFO_7_TO_4_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_4_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_4_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_4_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_4_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_4_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_4_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_4_OUT_CSR_USE_IRQ 0
#define FIFO_7_TO_4_OUT_CSR_USE_PACKET 1
#define FIFO_7_TO_4_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_4_OUT_CSR_USE_REGISTER 0
#define FIFO_7_TO_4_OUT_CSR_USE_WRITE_CONTROL 1



/********************/
/* system.h - CPU 5 */
/********************/


/*
 * fifo_0_to_5_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_5_out altera_avalon_fifo
#define FIFO_0_TO_5_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_5_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_5_OUT_BASE 0x135c
#define FIFO_0_TO_5_OUT_BITS_PER_SYMBOL 16
#define FIFO_0_TO_5_OUT_CHANNEL_WIDTH 8
#define FIFO_0_TO_5_OUT_ERROR_WIDTH 8
#define FIFO_0_TO_5_OUT_FIFO_DEPTH 16
#define FIFO_0_TO_5_OUT_IRQ -1
#define FIFO_0_TO_5_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_5_OUT_NAME "/dev/fifo_0_to_5_out"
#define FIFO_0_TO_5_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_5_OUT_SPAN 4
#define FIFO_0_TO_5_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_5_OUT_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_5_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_5_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_5_OUT_USE_AVALONST_SINK 0
#define FIFO_0_TO_5_OUT_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_5_OUT_USE_BACKPRESSURE 1
#define FIFO_0_TO_5_OUT_USE_IRQ 0
#define FIFO_0_TO_5_OUT_USE_PACKET 1
#define FIFO_0_TO_5_OUT_USE_READ_CONTROL 1
#define FIFO_0_TO_5_OUT_USE_REGISTER 0
#define FIFO_0_TO_5_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_5_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_5_out_csr altera_avalon_fifo
#define FIFO_0_TO_5_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_5_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_5_OUT_CSR_BASE 0x1280
#define FIFO_0_TO_5_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_5_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_5_OUT_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_5_OUT_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_5_OUT_CSR_IRQ -1
#define FIFO_0_TO_5_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_5_OUT_CSR_NAME "/dev/fifo_0_to_5_out_csr"
#define FIFO_0_TO_5_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_5_OUT_CSR_SPAN 32
#define FIFO_0_TO_5_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_5_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_5_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_5_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_5_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_5_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_5_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_5_OUT_CSR_USE_IRQ 0
#define FIFO_0_TO_5_OUT_CSR_USE_PACKET 1
#define FIFO_0_TO_5_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_5_OUT_CSR_USE_REGISTER 0
#define FIFO_0_TO_5_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_5_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_5_out altera_avalon_fifo
#define FIFO_1_TO_5_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_5_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_5_OUT_BASE 0x1358
#define FIFO_1_TO_5_OUT_BITS_PER_SYMBOL 16
#define FIFO_1_TO_5_OUT_CHANNEL_WIDTH 8
#define FIFO_1_TO_5_OUT_ERROR_WIDTH 8
#define FIFO_1_TO_5_OUT_FIFO_DEPTH 16
#define FIFO_1_TO_5_OUT_IRQ -1
#define FIFO_1_TO_5_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_5_OUT_NAME "/dev/fifo_1_to_5_out"
#define FIFO_1_TO_5_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_5_OUT_SPAN 4
#define FIFO_1_TO_5_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_5_OUT_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_5_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_5_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_5_OUT_USE_AVALONST_SINK 0
#define FIFO_1_TO_5_OUT_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_5_OUT_USE_BACKPRESSURE 1
#define FIFO_1_TO_5_OUT_USE_IRQ 0
#define FIFO_1_TO_5_OUT_USE_PACKET 1
#define FIFO_1_TO_5_OUT_USE_READ_CONTROL 1
#define FIFO_1_TO_5_OUT_USE_REGISTER 0
#define FIFO_1_TO_5_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_5_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_5_out_csr altera_avalon_fifo
#define FIFO_1_TO_5_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_5_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_5_OUT_CSR_BASE 0x1260
#define FIFO_1_TO_5_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_5_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_5_OUT_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_5_OUT_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_5_OUT_CSR_IRQ -1
#define FIFO_1_TO_5_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_5_OUT_CSR_NAME "/dev/fifo_1_to_5_out_csr"
#define FIFO_1_TO_5_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_5_OUT_CSR_SPAN 32
#define FIFO_1_TO_5_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_5_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_5_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_5_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_5_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_5_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_5_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_5_OUT_CSR_USE_IRQ 0
#define FIFO_1_TO_5_OUT_CSR_USE_PACKET 1
#define FIFO_1_TO_5_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_5_OUT_CSR_USE_REGISTER 0
#define FIFO_1_TO_5_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_5_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_5_out altera_avalon_fifo
#define FIFO_2_TO_5_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_5_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_5_OUT_BASE 0x1354
#define FIFO_2_TO_5_OUT_BITS_PER_SYMBOL 16
#define FIFO_2_TO_5_OUT_CHANNEL_WIDTH 8
#define FIFO_2_TO_5_OUT_ERROR_WIDTH 8
#define FIFO_2_TO_5_OUT_FIFO_DEPTH 16
#define FIFO_2_TO_5_OUT_IRQ -1
#define FIFO_2_TO_5_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_5_OUT_NAME "/dev/fifo_2_to_5_out"
#define FIFO_2_TO_5_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_5_OUT_SPAN 4
#define FIFO_2_TO_5_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_5_OUT_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_5_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_5_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_5_OUT_USE_AVALONST_SINK 0
#define FIFO_2_TO_5_OUT_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_5_OUT_USE_BACKPRESSURE 1
#define FIFO_2_TO_5_OUT_USE_IRQ 0
#define FIFO_2_TO_5_OUT_USE_PACKET 1
#define FIFO_2_TO_5_OUT_USE_READ_CONTROL 1
#define FIFO_2_TO_5_OUT_USE_REGISTER 0
#define FIFO_2_TO_5_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_5_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_5_out_csr altera_avalon_fifo
#define FIFO_2_TO_5_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_5_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_5_OUT_CSR_BASE 0x1240
#define FIFO_2_TO_5_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_5_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_5_OUT_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_5_OUT_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_5_OUT_CSR_IRQ -1
#define FIFO_2_TO_5_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_5_OUT_CSR_NAME "/dev/fifo_2_to_5_out_csr"
#define FIFO_2_TO_5_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_5_OUT_CSR_SPAN 32
#define FIFO_2_TO_5_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_5_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_5_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_5_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_5_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_5_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_5_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_5_OUT_CSR_USE_IRQ 0
#define FIFO_2_TO_5_OUT_CSR_USE_PACKET 1
#define FIFO_2_TO_5_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_5_OUT_CSR_USE_REGISTER 0
#define FIFO_2_TO_5_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_5_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_5_out altera_avalon_fifo
#define FIFO_3_TO_5_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_5_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_5_OUT_BASE 0x1350
#define FIFO_3_TO_5_OUT_BITS_PER_SYMBOL 16
#define FIFO_3_TO_5_OUT_CHANNEL_WIDTH 8
#define FIFO_3_TO_5_OUT_ERROR_WIDTH 8
#define FIFO_3_TO_5_OUT_FIFO_DEPTH 16
#define FIFO_3_TO_5_OUT_IRQ -1
#define FIFO_3_TO_5_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_5_OUT_NAME "/dev/fifo_3_to_5_out"
#define FIFO_3_TO_5_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_5_OUT_SPAN 4
#define FIFO_3_TO_5_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_5_OUT_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_5_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_5_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_5_OUT_USE_AVALONST_SINK 0
#define FIFO_3_TO_5_OUT_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_5_OUT_USE_BACKPRESSURE 1
#define FIFO_3_TO_5_OUT_USE_IRQ 0
#define FIFO_3_TO_5_OUT_USE_PACKET 1
#define FIFO_3_TO_5_OUT_USE_READ_CONTROL 1
#define FIFO_3_TO_5_OUT_USE_REGISTER 0
#define FIFO_3_TO_5_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_5_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_5_out_csr altera_avalon_fifo
#define FIFO_3_TO_5_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_5_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_5_OUT_CSR_BASE 0x1220
#define FIFO_3_TO_5_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_5_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_5_OUT_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_5_OUT_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_5_OUT_CSR_IRQ -1
#define FIFO_3_TO_5_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_5_OUT_CSR_NAME "/dev/fifo_3_to_5_out_csr"
#define FIFO_3_TO_5_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_5_OUT_CSR_SPAN 32
#define FIFO_3_TO_5_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_5_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_5_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_5_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_5_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_5_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_5_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_5_OUT_CSR_USE_IRQ 0
#define FIFO_3_TO_5_OUT_CSR_USE_PACKET 1
#define FIFO_3_TO_5_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_5_OUT_CSR_USE_REGISTER 0
#define FIFO_3_TO_5_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_5_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_5_out altera_avalon_fifo
#define FIFO_4_TO_5_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_5_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_5_OUT_BASE 0x134c
#define FIFO_4_TO_5_OUT_BITS_PER_SYMBOL 16
#define FIFO_4_TO_5_OUT_CHANNEL_WIDTH 8
#define FIFO_4_TO_5_OUT_ERROR_WIDTH 8
#define FIFO_4_TO_5_OUT_FIFO_DEPTH 16
#define FIFO_4_TO_5_OUT_IRQ -1
#define FIFO_4_TO_5_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_5_OUT_NAME "/dev/fifo_4_to_5_out"
#define FIFO_4_TO_5_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_5_OUT_SPAN 4
#define FIFO_4_TO_5_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_5_OUT_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_5_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_5_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_5_OUT_USE_AVALONST_SINK 0
#define FIFO_4_TO_5_OUT_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_5_OUT_USE_BACKPRESSURE 1
#define FIFO_4_TO_5_OUT_USE_IRQ 0
#define FIFO_4_TO_5_OUT_USE_PACKET 1
#define FIFO_4_TO_5_OUT_USE_READ_CONTROL 1
#define FIFO_4_TO_5_OUT_USE_REGISTER 0
#define FIFO_4_TO_5_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_5_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_5_out_csr altera_avalon_fifo
#define FIFO_4_TO_5_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_5_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_5_OUT_CSR_BASE 0x1200
#define FIFO_4_TO_5_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_5_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_5_OUT_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_5_OUT_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_5_OUT_CSR_IRQ -1
#define FIFO_4_TO_5_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_5_OUT_CSR_NAME "/dev/fifo_4_to_5_out_csr"
#define FIFO_4_TO_5_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_5_OUT_CSR_SPAN 32
#define FIFO_4_TO_5_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_5_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_5_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_5_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_5_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_5_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_5_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_5_OUT_CSR_USE_IRQ 0
#define FIFO_4_TO_5_OUT_CSR_USE_PACKET 1
#define FIFO_4_TO_5_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_5_OUT_CSR_USE_REGISTER 0
#define FIFO_4_TO_5_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_0_in altera_avalon_fifo
#define FIFO_5_TO_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_0_IN_BASE 0x1348
#define FIFO_5_TO_0_IN_BITS_PER_SYMBOL 16
#define FIFO_5_TO_0_IN_CHANNEL_WIDTH 8
#define FIFO_5_TO_0_IN_ERROR_WIDTH 8
#define FIFO_5_TO_0_IN_FIFO_DEPTH 16
#define FIFO_5_TO_0_IN_IRQ -1
#define FIFO_5_TO_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_0_IN_NAME "/dev/fifo_5_to_0_in"
#define FIFO_5_TO_0_IN_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_0_IN_SPAN 4
#define FIFO_5_TO_0_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_0_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_0_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_0_IN_USE_AVALONST_SINK 0
#define FIFO_5_TO_0_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_0_IN_USE_BACKPRESSURE 1
#define FIFO_5_TO_0_IN_USE_IRQ 0
#define FIFO_5_TO_0_IN_USE_PACKET 1
#define FIFO_5_TO_0_IN_USE_READ_CONTROL 1
#define FIFO_5_TO_0_IN_USE_REGISTER 0
#define FIFO_5_TO_0_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_0_in_csr altera_avalon_fifo
#define FIFO_5_TO_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_0_IN_CSR_BASE 0x11e0
#define FIFO_5_TO_0_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_0_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_0_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_0_IN_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_0_IN_CSR_IRQ -1
#define FIFO_5_TO_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_0_IN_CSR_NAME "/dev/fifo_5_to_0_in_csr"
#define FIFO_5_TO_0_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_0_IN_CSR_SPAN 32
#define FIFO_5_TO_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_0_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_0_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_0_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_0_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_0_IN_CSR_USE_IRQ 0
#define FIFO_5_TO_0_IN_CSR_USE_PACKET 1
#define FIFO_5_TO_0_IN_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_0_IN_CSR_USE_REGISTER 0
#define FIFO_5_TO_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_1_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_1_in altera_avalon_fifo
#define FIFO_5_TO_1_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_1_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_1_IN_BASE 0x1344
#define FIFO_5_TO_1_IN_BITS_PER_SYMBOL 16
#define FIFO_5_TO_1_IN_CHANNEL_WIDTH 8
#define FIFO_5_TO_1_IN_ERROR_WIDTH 8
#define FIFO_5_TO_1_IN_FIFO_DEPTH 16
#define FIFO_5_TO_1_IN_IRQ -1
#define FIFO_5_TO_1_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_1_IN_NAME "/dev/fifo_5_to_1_in"
#define FIFO_5_TO_1_IN_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_1_IN_SPAN 4
#define FIFO_5_TO_1_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_1_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_1_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_1_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_1_IN_USE_AVALONST_SINK 0
#define FIFO_5_TO_1_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_1_IN_USE_BACKPRESSURE 1
#define FIFO_5_TO_1_IN_USE_IRQ 0
#define FIFO_5_TO_1_IN_USE_PACKET 1
#define FIFO_5_TO_1_IN_USE_READ_CONTROL 1
#define FIFO_5_TO_1_IN_USE_REGISTER 0
#define FIFO_5_TO_1_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_1_in_csr altera_avalon_fifo
#define FIFO_5_TO_1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_1_IN_CSR_BASE 0x11a0
#define FIFO_5_TO_1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_1_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_1_IN_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_1_IN_CSR_IRQ -1
#define FIFO_5_TO_1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_1_IN_CSR_NAME "/dev/fifo_5_to_1_in_csr"
#define FIFO_5_TO_1_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_1_IN_CSR_SPAN 32
#define FIFO_5_TO_1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_1_IN_CSR_USE_IRQ 0
#define FIFO_5_TO_1_IN_CSR_USE_PACKET 1
#define FIFO_5_TO_1_IN_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_1_IN_CSR_USE_REGISTER 0
#define FIFO_5_TO_1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_2_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_2_in altera_avalon_fifo
#define FIFO_5_TO_2_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_2_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_2_IN_BASE 0x1340
#define FIFO_5_TO_2_IN_BITS_PER_SYMBOL 16
#define FIFO_5_TO_2_IN_CHANNEL_WIDTH 8
#define FIFO_5_TO_2_IN_ERROR_WIDTH 8
#define FIFO_5_TO_2_IN_FIFO_DEPTH 16
#define FIFO_5_TO_2_IN_IRQ -1
#define FIFO_5_TO_2_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_2_IN_NAME "/dev/fifo_5_to_2_in"
#define FIFO_5_TO_2_IN_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_2_IN_SPAN 4
#define FIFO_5_TO_2_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_2_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_2_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_2_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_2_IN_USE_AVALONST_SINK 0
#define FIFO_5_TO_2_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_2_IN_USE_BACKPRESSURE 1
#define FIFO_5_TO_2_IN_USE_IRQ 0
#define FIFO_5_TO_2_IN_USE_PACKET 1
#define FIFO_5_TO_2_IN_USE_READ_CONTROL 1
#define FIFO_5_TO_2_IN_USE_REGISTER 0
#define FIFO_5_TO_2_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_2_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_2_in_csr altera_avalon_fifo
#define FIFO_5_TO_2_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_2_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_2_IN_CSR_BASE 0x1180
#define FIFO_5_TO_2_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_2_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_2_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_2_IN_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_2_IN_CSR_IRQ -1
#define FIFO_5_TO_2_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_2_IN_CSR_NAME "/dev/fifo_5_to_2_in_csr"
#define FIFO_5_TO_2_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_2_IN_CSR_SPAN 32
#define FIFO_5_TO_2_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_2_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_2_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_2_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_2_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_2_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_2_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_2_IN_CSR_USE_IRQ 0
#define FIFO_5_TO_2_IN_CSR_USE_PACKET 1
#define FIFO_5_TO_2_IN_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_2_IN_CSR_USE_REGISTER 0
#define FIFO_5_TO_2_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_3_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_3_in altera_avalon_fifo
#define FIFO_5_TO_3_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_3_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_3_IN_BASE 0x133c
#define FIFO_5_TO_3_IN_BITS_PER_SYMBOL 16
#define FIFO_5_TO_3_IN_CHANNEL_WIDTH 8
#define FIFO_5_TO_3_IN_ERROR_WIDTH 8
#define FIFO_5_TO_3_IN_FIFO_DEPTH 16
#define FIFO_5_TO_3_IN_IRQ -1
#define FIFO_5_TO_3_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_3_IN_NAME "/dev/fifo_5_to_3_in"
#define FIFO_5_TO_3_IN_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_3_IN_SPAN 4
#define FIFO_5_TO_3_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_3_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_3_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_3_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_3_IN_USE_AVALONST_SINK 0
#define FIFO_5_TO_3_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_3_IN_USE_BACKPRESSURE 1
#define FIFO_5_TO_3_IN_USE_IRQ 0
#define FIFO_5_TO_3_IN_USE_PACKET 1
#define FIFO_5_TO_3_IN_USE_READ_CONTROL 1
#define FIFO_5_TO_3_IN_USE_REGISTER 0
#define FIFO_5_TO_3_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_3_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_3_in_csr altera_avalon_fifo
#define FIFO_5_TO_3_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_3_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_3_IN_CSR_BASE 0x1160
#define FIFO_5_TO_3_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_3_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_3_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_3_IN_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_3_IN_CSR_IRQ -1
#define FIFO_5_TO_3_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_3_IN_CSR_NAME "/dev/fifo_5_to_3_in_csr"
#define FIFO_5_TO_3_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_3_IN_CSR_SPAN 32
#define FIFO_5_TO_3_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_3_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_3_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_3_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_3_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_3_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_3_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_3_IN_CSR_USE_IRQ 0
#define FIFO_5_TO_3_IN_CSR_USE_PACKET 1
#define FIFO_5_TO_3_IN_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_3_IN_CSR_USE_REGISTER 0
#define FIFO_5_TO_3_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_4_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_4_in altera_avalon_fifo
#define FIFO_5_TO_4_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_4_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_4_IN_BASE 0x1338
#define FIFO_5_TO_4_IN_BITS_PER_SYMBOL 16
#define FIFO_5_TO_4_IN_CHANNEL_WIDTH 8
#define FIFO_5_TO_4_IN_ERROR_WIDTH 8
#define FIFO_5_TO_4_IN_FIFO_DEPTH 16
#define FIFO_5_TO_4_IN_IRQ -1
#define FIFO_5_TO_4_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_4_IN_NAME "/dev/fifo_5_to_4_in"
#define FIFO_5_TO_4_IN_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_4_IN_SPAN 4
#define FIFO_5_TO_4_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_4_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_4_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_4_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_4_IN_USE_AVALONST_SINK 0
#define FIFO_5_TO_4_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_4_IN_USE_BACKPRESSURE 1
#define FIFO_5_TO_4_IN_USE_IRQ 0
#define FIFO_5_TO_4_IN_USE_PACKET 1
#define FIFO_5_TO_4_IN_USE_READ_CONTROL 1
#define FIFO_5_TO_4_IN_USE_REGISTER 0
#define FIFO_5_TO_4_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_4_in_csr altera_avalon_fifo
#define FIFO_5_TO_4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_4_IN_CSR_BASE 0x1140
#define FIFO_5_TO_4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_4_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_4_IN_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_4_IN_CSR_IRQ -1
#define FIFO_5_TO_4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_4_IN_CSR_NAME "/dev/fifo_5_to_4_in_csr"
#define FIFO_5_TO_4_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_4_IN_CSR_SPAN 32
#define FIFO_5_TO_4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_4_IN_CSR_USE_IRQ 0
#define FIFO_5_TO_4_IN_CSR_USE_PACKET 1
#define FIFO_5_TO_4_IN_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_4_IN_CSR_USE_REGISTER 0
#define FIFO_5_TO_4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_6_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_6_in altera_avalon_fifo
#define FIFO_5_TO_6_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_6_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_6_IN_BASE 0x1334
#define FIFO_5_TO_6_IN_BITS_PER_SYMBOL 16
#define FIFO_5_TO_6_IN_CHANNEL_WIDTH 8
#define FIFO_5_TO_6_IN_ERROR_WIDTH 8
#define FIFO_5_TO_6_IN_FIFO_DEPTH 16
#define FIFO_5_TO_6_IN_IRQ -1
#define FIFO_5_TO_6_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_6_IN_NAME "/dev/fifo_5_to_6_in"
#define FIFO_5_TO_6_IN_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_6_IN_SPAN 4
#define FIFO_5_TO_6_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_6_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_6_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_6_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_6_IN_USE_AVALONST_SINK 0
#define FIFO_5_TO_6_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_6_IN_USE_BACKPRESSURE 1
#define FIFO_5_TO_6_IN_USE_IRQ 0
#define FIFO_5_TO_6_IN_USE_PACKET 1
#define FIFO_5_TO_6_IN_USE_READ_CONTROL 1
#define FIFO_5_TO_6_IN_USE_REGISTER 0
#define FIFO_5_TO_6_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_6_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_6_in_csr altera_avalon_fifo
#define FIFO_5_TO_6_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_6_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_6_IN_CSR_BASE 0x1100
#define FIFO_5_TO_6_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_6_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_6_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_6_IN_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_6_IN_CSR_IRQ -1
#define FIFO_5_TO_6_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_6_IN_CSR_NAME "/dev/fifo_5_to_6_in_csr"
#define FIFO_5_TO_6_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_6_IN_CSR_SPAN 32
#define FIFO_5_TO_6_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_6_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_6_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_6_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_6_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_6_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_6_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_6_IN_CSR_USE_IRQ 0
#define FIFO_5_TO_6_IN_CSR_USE_PACKET 1
#define FIFO_5_TO_6_IN_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_6_IN_CSR_USE_REGISTER 0
#define FIFO_5_TO_6_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_7_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_7_in altera_avalon_fifo
#define FIFO_5_TO_7_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_7_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_7_IN_BASE 0x1330
#define FIFO_5_TO_7_IN_BITS_PER_SYMBOL 16
#define FIFO_5_TO_7_IN_CHANNEL_WIDTH 8
#define FIFO_5_TO_7_IN_ERROR_WIDTH 8
#define FIFO_5_TO_7_IN_FIFO_DEPTH 16
#define FIFO_5_TO_7_IN_IRQ -1
#define FIFO_5_TO_7_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_7_IN_NAME "/dev/fifo_5_to_7_in"
#define FIFO_5_TO_7_IN_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_7_IN_SPAN 4
#define FIFO_5_TO_7_IN_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_7_IN_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_7_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_7_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_7_IN_USE_AVALONST_SINK 0
#define FIFO_5_TO_7_IN_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_7_IN_USE_BACKPRESSURE 1
#define FIFO_5_TO_7_IN_USE_IRQ 0
#define FIFO_5_TO_7_IN_USE_PACKET 1
#define FIFO_5_TO_7_IN_USE_READ_CONTROL 1
#define FIFO_5_TO_7_IN_USE_REGISTER 0
#define FIFO_5_TO_7_IN_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_7_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_7_in_csr altera_avalon_fifo
#define FIFO_5_TO_7_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_7_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_7_IN_CSR_BASE 0x1120
#define FIFO_5_TO_7_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_7_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_7_IN_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_7_IN_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_7_IN_CSR_IRQ -1
#define FIFO_5_TO_7_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_7_IN_CSR_NAME "/dev/fifo_5_to_7_in_csr"
#define FIFO_5_TO_7_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_7_IN_CSR_SPAN 32
#define FIFO_5_TO_7_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_7_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_7_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_7_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_7_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_7_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_7_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_7_IN_CSR_USE_IRQ 0
#define FIFO_5_TO_7_IN_CSR_USE_PACKET 1
#define FIFO_5_TO_7_IN_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_7_IN_CSR_USE_REGISTER 0
#define FIFO_5_TO_7_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_5_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_5_out altera_avalon_fifo
#define FIFO_6_TO_5_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_5_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_5_OUT_BASE 0x132c
#define FIFO_6_TO_5_OUT_BITS_PER_SYMBOL 16
#define FIFO_6_TO_5_OUT_CHANNEL_WIDTH 8
#define FIFO_6_TO_5_OUT_ERROR_WIDTH 8
#define FIFO_6_TO_5_OUT_FIFO_DEPTH 16
#define FIFO_6_TO_5_OUT_IRQ -1
#define FIFO_6_TO_5_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_5_OUT_NAME "/dev/fifo_6_to_5_out"
#define FIFO_6_TO_5_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_5_OUT_SPAN 4
#define FIFO_6_TO_5_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_5_OUT_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_5_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_5_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_5_OUT_USE_AVALONST_SINK 0
#define FIFO_6_TO_5_OUT_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_5_OUT_USE_BACKPRESSURE 1
#define FIFO_6_TO_5_OUT_USE_IRQ 0
#define FIFO_6_TO_5_OUT_USE_PACKET 1
#define FIFO_6_TO_5_OUT_USE_READ_CONTROL 1
#define FIFO_6_TO_5_OUT_USE_REGISTER 0
#define FIFO_6_TO_5_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_5_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_5_out_csr altera_avalon_fifo
#define FIFO_6_TO_5_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_5_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_5_OUT_CSR_BASE 0x10e0
#define FIFO_6_TO_5_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_5_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_5_OUT_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_5_OUT_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_5_OUT_CSR_IRQ -1
#define FIFO_6_TO_5_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_5_OUT_CSR_NAME "/dev/fifo_6_to_5_out_csr"
#define FIFO_6_TO_5_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_5_OUT_CSR_SPAN 32
#define FIFO_6_TO_5_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_5_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_5_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_5_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_5_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_5_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_5_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_5_OUT_CSR_USE_IRQ 0
#define FIFO_6_TO_5_OUT_CSR_USE_PACKET 1
#define FIFO_6_TO_5_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_5_OUT_CSR_USE_REGISTER 0
#define FIFO_6_TO_5_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_5_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_5_out altera_avalon_fifo
#define FIFO_7_TO_5_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_5_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_5_OUT_BASE 0x1328
#define FIFO_7_TO_5_OUT_BITS_PER_SYMBOL 16
#define FIFO_7_TO_5_OUT_CHANNEL_WIDTH 8
#define FIFO_7_TO_5_OUT_ERROR_WIDTH 8
#define FIFO_7_TO_5_OUT_FIFO_DEPTH 16
#define FIFO_7_TO_5_OUT_IRQ -1
#define FIFO_7_TO_5_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_5_OUT_NAME "/dev/fifo_7_to_5_out"
#define FIFO_7_TO_5_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_5_OUT_SPAN 4
#define FIFO_7_TO_5_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_5_OUT_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_5_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_5_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_5_OUT_USE_AVALONST_SINK 0
#define FIFO_7_TO_5_OUT_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_5_OUT_USE_BACKPRESSURE 1
#define FIFO_7_TO_5_OUT_USE_IRQ 0
#define FIFO_7_TO_5_OUT_USE_PACKET 1
#define FIFO_7_TO_5_OUT_USE_READ_CONTROL 1
#define FIFO_7_TO_5_OUT_USE_REGISTER 0
#define FIFO_7_TO_5_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_5_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_5_out_csr altera_avalon_fifo
#define FIFO_7_TO_5_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_5_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_5_OUT_CSR_BASE 0x10c0
#define FIFO_7_TO_5_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_5_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_5_OUT_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_5_OUT_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_5_OUT_CSR_IRQ -1
#define FIFO_7_TO_5_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_5_OUT_CSR_NAME "/dev/fifo_7_to_5_out_csr"
#define FIFO_7_TO_5_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_5_OUT_CSR_SPAN 32
#define FIFO_7_TO_5_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_5_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_5_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_5_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_5_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_5_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_5_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_5_OUT_CSR_USE_IRQ 0
#define FIFO_7_TO_5_OUT_CSR_USE_PACKET 1
#define FIFO_7_TO_5_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_5_OUT_CSR_USE_REGISTER 0
#define FIFO_7_TO_5_OUT_CSR_USE_WRITE_CONTROL 1




/********************/
/* system.h - CPU 6 */
/********************/


/*
 * fifo_0_to_6_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_6_out altera_avalon_fifo
#define FIFO_0_TO_6_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_6_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_6_OUT_BASE 0x135c
#define FIFO_0_TO_6_OUT_BITS_PER_SYMBOL 16
#define FIFO_0_TO_6_OUT_CHANNEL_WIDTH 8
#define FIFO_0_TO_6_OUT_ERROR_WIDTH 8
#define FIFO_0_TO_6_OUT_FIFO_DEPTH 16
#define FIFO_0_TO_6_OUT_IRQ -1
#define FIFO_0_TO_6_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_6_OUT_NAME "/dev/fifo_0_to_6_out"
#define FIFO_0_TO_6_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_6_OUT_SPAN 4
#define FIFO_0_TO_6_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_6_OUT_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_6_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_6_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_6_OUT_USE_AVALONST_SINK 0
#define FIFO_0_TO_6_OUT_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_6_OUT_USE_BACKPRESSURE 1
#define FIFO_0_TO_6_OUT_USE_IRQ 0
#define FIFO_0_TO_6_OUT_USE_PACKET 1
#define FIFO_0_TO_6_OUT_USE_READ_CONTROL 1
#define FIFO_0_TO_6_OUT_USE_REGISTER 0
#define FIFO_0_TO_6_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_6_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_6_out_csr altera_avalon_fifo
#define FIFO_0_TO_6_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_6_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_6_OUT_CSR_BASE 0x1280
#define FIFO_0_TO_6_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_6_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_6_OUT_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_6_OUT_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_6_OUT_CSR_IRQ -1
#define FIFO_0_TO_6_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_6_OUT_CSR_NAME "/dev/fifo_0_to_6_out_csr"
#define FIFO_0_TO_6_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_6_OUT_CSR_SPAN 32
#define FIFO_0_TO_6_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_6_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_6_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_6_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_6_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_6_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_6_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_6_OUT_CSR_USE_IRQ 0
#define FIFO_0_TO_6_OUT_CSR_USE_PACKET 1
#define FIFO_0_TO_6_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_6_OUT_CSR_USE_REGISTER 0
#define FIFO_0_TO_6_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_6_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_6_out altera_avalon_fifo
#define FIFO_1_TO_6_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_6_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_6_OUT_BASE 0x1358
#define FIFO_1_TO_6_OUT_BITS_PER_SYMBOL 16
#define FIFO_1_TO_6_OUT_CHANNEL_WIDTH 8
#define FIFO_1_TO_6_OUT_ERROR_WIDTH 8
#define FIFO_1_TO_6_OUT_FIFO_DEPTH 16
#define FIFO_1_TO_6_OUT_IRQ -1
#define FIFO_1_TO_6_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_6_OUT_NAME "/dev/fifo_1_to_6_out"
#define FIFO_1_TO_6_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_6_OUT_SPAN 4
#define FIFO_1_TO_6_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_6_OUT_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_6_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_6_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_6_OUT_USE_AVALONST_SINK 0
#define FIFO_1_TO_6_OUT_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_6_OUT_USE_BACKPRESSURE 1
#define FIFO_1_TO_6_OUT_USE_IRQ 0
#define FIFO_1_TO_6_OUT_USE_PACKET 1
#define FIFO_1_TO_6_OUT_USE_READ_CONTROL 1
#define FIFO_1_TO_6_OUT_USE_REGISTER 0
#define FIFO_1_TO_6_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_6_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_6_out_csr altera_avalon_fifo
#define FIFO_1_TO_6_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_6_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_6_OUT_CSR_BASE 0x1260
#define FIFO_1_TO_6_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_6_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_6_OUT_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_6_OUT_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_6_OUT_CSR_IRQ -1
#define FIFO_1_TO_6_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_6_OUT_CSR_NAME "/dev/fifo_1_to_6_out_csr"
#define FIFO_1_TO_6_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_6_OUT_CSR_SPAN 32
#define FIFO_1_TO_6_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_6_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_6_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_6_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_6_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_6_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_6_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_6_OUT_CSR_USE_IRQ 0
#define FIFO_1_TO_6_OUT_CSR_USE_PACKET 1
#define FIFO_1_TO_6_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_6_OUT_CSR_USE_REGISTER 0
#define FIFO_1_TO_6_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_6_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_6_out altera_avalon_fifo
#define FIFO_2_TO_6_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_6_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_6_OUT_BASE 0x1354
#define FIFO_2_TO_6_OUT_BITS_PER_SYMBOL 16
#define FIFO_2_TO_6_OUT_CHANNEL_WIDTH 8
#define FIFO_2_TO_6_OUT_ERROR_WIDTH 8
#define FIFO_2_TO_6_OUT_FIFO_DEPTH 16
#define FIFO_2_TO_6_OUT_IRQ -1
#define FIFO_2_TO_6_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_6_OUT_NAME "/dev/fifo_2_to_6_out"
#define FIFO_2_TO_6_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_6_OUT_SPAN 4
#define FIFO_2_TO_6_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_6_OUT_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_6_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_6_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_6_OUT_USE_AVALONST_SINK 0
#define FIFO_2_TO_6_OUT_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_6_OUT_USE_BACKPRESSURE 1
#define FIFO_2_TO_6_OUT_USE_IRQ 0
#define FIFO_2_TO_6_OUT_USE_PACKET 1
#define FIFO_2_TO_6_OUT_USE_READ_CONTROL 1
#define FIFO_2_TO_6_OUT_USE_REGISTER 0
#define FIFO_2_TO_6_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_6_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_6_out_csr altera_avalon_fifo
#define FIFO_2_TO_6_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_6_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_6_OUT_CSR_BASE 0x1240
#define FIFO_2_TO_6_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_6_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_6_OUT_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_6_OUT_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_6_OUT_CSR_IRQ -1
#define FIFO_2_TO_6_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_6_OUT_CSR_NAME "/dev/fifo_2_to_6_out_csr"
#define FIFO_2_TO_6_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_6_OUT_CSR_SPAN 32
#define FIFO_2_TO_6_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_6_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_6_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_6_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_6_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_6_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_6_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_6_OUT_CSR_USE_IRQ 0
#define FIFO_2_TO_6_OUT_CSR_USE_PACKET 1
#define FIFO_2_TO_6_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_6_OUT_CSR_USE_REGISTER 0
#define FIFO_2_TO_6_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_6_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_6_out altera_avalon_fifo
#define FIFO_3_TO_6_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_6_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_6_OUT_BASE 0x1350
#define FIFO_3_TO_6_OUT_BITS_PER_SYMBOL 16
#define FIFO_3_TO_6_OUT_CHANNEL_WIDTH 8
#define FIFO_3_TO_6_OUT_ERROR_WIDTH 8
#define FIFO_3_TO_6_OUT_FIFO_DEPTH 16
#define FIFO_3_TO_6_OUT_IRQ -1
#define FIFO_3_TO_6_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_6_OUT_NAME "/dev/fifo_3_to_6_out"
#define FIFO_3_TO_6_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_6_OUT_SPAN 4
#define FIFO_3_TO_6_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_6_OUT_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_6_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_6_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_6_OUT_USE_AVALONST_SINK 0
#define FIFO_3_TO_6_OUT_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_6_OUT_USE_BACKPRESSURE 1
#define FIFO_3_TO_6_OUT_USE_IRQ 0
#define FIFO_3_TO_6_OUT_USE_PACKET 1
#define FIFO_3_TO_6_OUT_USE_READ_CONTROL 1
#define FIFO_3_TO_6_OUT_USE_REGISTER 0
#define FIFO_3_TO_6_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_6_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_6_out_csr altera_avalon_fifo
#define FIFO_3_TO_6_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_6_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_6_OUT_CSR_BASE 0x1220
#define FIFO_3_TO_6_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_6_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_6_OUT_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_6_OUT_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_6_OUT_CSR_IRQ -1
#define FIFO_3_TO_6_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_6_OUT_CSR_NAME "/dev/fifo_3_to_6_out_csr"
#define FIFO_3_TO_6_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_6_OUT_CSR_SPAN 32
#define FIFO_3_TO_6_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_6_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_6_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_6_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_6_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_6_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_6_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_6_OUT_CSR_USE_IRQ 0
#define FIFO_3_TO_6_OUT_CSR_USE_PACKET 1
#define FIFO_3_TO_6_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_6_OUT_CSR_USE_REGISTER 0
#define FIFO_3_TO_6_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_6_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_6_out altera_avalon_fifo
#define FIFO_4_TO_6_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_6_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_6_OUT_BASE 0x134c
#define FIFO_4_TO_6_OUT_BITS_PER_SYMBOL 16
#define FIFO_4_TO_6_OUT_CHANNEL_WIDTH 8
#define FIFO_4_TO_6_OUT_ERROR_WIDTH 8
#define FIFO_4_TO_6_OUT_FIFO_DEPTH 16
#define FIFO_4_TO_6_OUT_IRQ -1
#define FIFO_4_TO_6_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_6_OUT_NAME "/dev/fifo_4_to_6_out"
#define FIFO_4_TO_6_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_6_OUT_SPAN 4
#define FIFO_4_TO_6_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_6_OUT_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_6_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_6_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_6_OUT_USE_AVALONST_SINK 0
#define FIFO_4_TO_6_OUT_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_6_OUT_USE_BACKPRESSURE 1
#define FIFO_4_TO_6_OUT_USE_IRQ 0
#define FIFO_4_TO_6_OUT_USE_PACKET 1
#define FIFO_4_TO_6_OUT_USE_READ_CONTROL 1
#define FIFO_4_TO_6_OUT_USE_REGISTER 0
#define FIFO_4_TO_6_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_6_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_6_out_csr altera_avalon_fifo
#define FIFO_4_TO_6_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_6_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_6_OUT_CSR_BASE 0x1200
#define FIFO_4_TO_6_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_6_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_6_OUT_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_6_OUT_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_6_OUT_CSR_IRQ -1
#define FIFO_4_TO_6_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_6_OUT_CSR_NAME "/dev/fifo_4_to_6_out_csr"
#define FIFO_4_TO_6_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_6_OUT_CSR_SPAN 32
#define FIFO_4_TO_6_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_6_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_6_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_6_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_6_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_6_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_6_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_6_OUT_CSR_USE_IRQ 0
#define FIFO_4_TO_6_OUT_CSR_USE_PACKET 1
#define FIFO_4_TO_6_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_6_OUT_CSR_USE_REGISTER 0
#define FIFO_4_TO_6_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_6_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_6_out altera_avalon_fifo
#define FIFO_5_TO_6_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_6_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_6_OUT_BASE 0x1348
#define FIFO_5_TO_6_OUT_BITS_PER_SYMBOL 16
#define FIFO_5_TO_6_OUT_CHANNEL_WIDTH 8
#define FIFO_5_TO_6_OUT_ERROR_WIDTH 8
#define FIFO_5_TO_6_OUT_FIFO_DEPTH 16
#define FIFO_5_TO_6_OUT_IRQ -1
#define FIFO_5_TO_6_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_6_OUT_NAME "/dev/fifo_5_to_6_out"
#define FIFO_5_TO_6_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_6_OUT_SPAN 4
#define FIFO_5_TO_6_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_6_OUT_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_6_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_6_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_6_OUT_USE_AVALONST_SINK 0
#define FIFO_5_TO_6_OUT_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_6_OUT_USE_BACKPRESSURE 1
#define FIFO_5_TO_6_OUT_USE_IRQ 0
#define FIFO_5_TO_6_OUT_USE_PACKET 1
#define FIFO_5_TO_6_OUT_USE_READ_CONTROL 1
#define FIFO_5_TO_6_OUT_USE_REGISTER 0
#define FIFO_5_TO_6_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_6_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_6_out_csr altera_avalon_fifo
#define FIFO_5_TO_6_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_6_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_6_OUT_CSR_BASE 0x11e0
#define FIFO_5_TO_6_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_6_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_6_OUT_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_6_OUT_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_6_OUT_CSR_IRQ -1
#define FIFO_5_TO_6_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_6_OUT_CSR_NAME "/dev/fifo_5_to_6_out_csr"
#define FIFO_5_TO_6_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_6_OUT_CSR_SPAN 32
#define FIFO_5_TO_6_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_6_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_6_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_6_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_6_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_6_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_6_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_6_OUT_CSR_USE_IRQ 0
#define FIFO_5_TO_6_OUT_CSR_USE_PACKET 1
#define FIFO_5_TO_6_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_6_OUT_CSR_USE_REGISTER 0
#define FIFO_5_TO_6_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_0_in altera_avalon_fifo
#define FIFO_6_TO_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_0_IN_BASE 0x1344
#define FIFO_6_TO_0_IN_BITS_PER_SYMBOL 16
#define FIFO_6_TO_0_IN_CHANNEL_WIDTH 8
#define FIFO_6_TO_0_IN_ERROR_WIDTH 8
#define FIFO_6_TO_0_IN_FIFO_DEPTH 16
#define FIFO_6_TO_0_IN_IRQ -1
#define FIFO_6_TO_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_0_IN_NAME "/dev/fifo_6_to_0_in"
#define FIFO_6_TO_0_IN_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_0_IN_SPAN 4
#define FIFO_6_TO_0_IN_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_0_IN_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_0_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_0_IN_USE_AVALONST_SINK 0
#define FIFO_6_TO_0_IN_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_0_IN_USE_BACKPRESSURE 1
#define FIFO_6_TO_0_IN_USE_IRQ 0
#define FIFO_6_TO_0_IN_USE_PACKET 1
#define FIFO_6_TO_0_IN_USE_READ_CONTROL 1
#define FIFO_6_TO_0_IN_USE_REGISTER 0
#define FIFO_6_TO_0_IN_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_0_in_csr altera_avalon_fifo
#define FIFO_6_TO_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_0_IN_CSR_BASE 0x11a0
#define FIFO_6_TO_0_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_0_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_0_IN_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_0_IN_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_0_IN_CSR_IRQ -1
#define FIFO_6_TO_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_0_IN_CSR_NAME "/dev/fifo_6_to_0_in_csr"
#define FIFO_6_TO_0_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_0_IN_CSR_SPAN 32
#define FIFO_6_TO_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_0_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_0_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_0_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_0_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_0_IN_CSR_USE_IRQ 0
#define FIFO_6_TO_0_IN_CSR_USE_PACKET 1
#define FIFO_6_TO_0_IN_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_0_IN_CSR_USE_REGISTER 0
#define FIFO_6_TO_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_1_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_1_in altera_avalon_fifo
#define FIFO_6_TO_1_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_1_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_1_IN_BASE 0x1340
#define FIFO_6_TO_1_IN_BITS_PER_SYMBOL 16
#define FIFO_6_TO_1_IN_CHANNEL_WIDTH 8
#define FIFO_6_TO_1_IN_ERROR_WIDTH 8
#define FIFO_6_TO_1_IN_FIFO_DEPTH 16
#define FIFO_6_TO_1_IN_IRQ -1
#define FIFO_6_TO_1_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_1_IN_NAME "/dev/fifo_6_to_1_in"
#define FIFO_6_TO_1_IN_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_1_IN_SPAN 4
#define FIFO_6_TO_1_IN_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_1_IN_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_1_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_1_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_1_IN_USE_AVALONST_SINK 0
#define FIFO_6_TO_1_IN_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_1_IN_USE_BACKPRESSURE 1
#define FIFO_6_TO_1_IN_USE_IRQ 0
#define FIFO_6_TO_1_IN_USE_PACKET 1
#define FIFO_6_TO_1_IN_USE_READ_CONTROL 1
#define FIFO_6_TO_1_IN_USE_REGISTER 0
#define FIFO_6_TO_1_IN_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_1_in_csr altera_avalon_fifo
#define FIFO_6_TO_1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_1_IN_CSR_BASE 0x1180
#define FIFO_6_TO_1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_1_IN_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_1_IN_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_1_IN_CSR_IRQ -1
#define FIFO_6_TO_1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_1_IN_CSR_NAME "/dev/fifo_6_to_1_in_csr"
#define FIFO_6_TO_1_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_1_IN_CSR_SPAN 32
#define FIFO_6_TO_1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_1_IN_CSR_USE_IRQ 0
#define FIFO_6_TO_1_IN_CSR_USE_PACKET 1
#define FIFO_6_TO_1_IN_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_1_IN_CSR_USE_REGISTER 0
#define FIFO_6_TO_1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_2_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_2_in altera_avalon_fifo
#define FIFO_6_TO_2_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_2_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_2_IN_BASE 0x133c
#define FIFO_6_TO_2_IN_BITS_PER_SYMBOL 16
#define FIFO_6_TO_2_IN_CHANNEL_WIDTH 8
#define FIFO_6_TO_2_IN_ERROR_WIDTH 8
#define FIFO_6_TO_2_IN_FIFO_DEPTH 16
#define FIFO_6_TO_2_IN_IRQ -1
#define FIFO_6_TO_2_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_2_IN_NAME "/dev/fifo_6_to_2_in"
#define FIFO_6_TO_2_IN_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_2_IN_SPAN 4
#define FIFO_6_TO_2_IN_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_2_IN_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_2_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_2_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_2_IN_USE_AVALONST_SINK 0
#define FIFO_6_TO_2_IN_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_2_IN_USE_BACKPRESSURE 1
#define FIFO_6_TO_2_IN_USE_IRQ 0
#define FIFO_6_TO_2_IN_USE_PACKET 1
#define FIFO_6_TO_2_IN_USE_READ_CONTROL 1
#define FIFO_6_TO_2_IN_USE_REGISTER 0
#define FIFO_6_TO_2_IN_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_2_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_2_in_csr altera_avalon_fifo
#define FIFO_6_TO_2_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_2_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_2_IN_CSR_BASE 0x1160
#define FIFO_6_TO_2_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_2_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_2_IN_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_2_IN_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_2_IN_CSR_IRQ -1
#define FIFO_6_TO_2_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_2_IN_CSR_NAME "/dev/fifo_6_to_2_in_csr"
#define FIFO_6_TO_2_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_2_IN_CSR_SPAN 32
#define FIFO_6_TO_2_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_2_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_2_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_2_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_2_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_2_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_2_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_2_IN_CSR_USE_IRQ 0
#define FIFO_6_TO_2_IN_CSR_USE_PACKET 1
#define FIFO_6_TO_2_IN_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_2_IN_CSR_USE_REGISTER 0
#define FIFO_6_TO_2_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_3_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_3_in altera_avalon_fifo
#define FIFO_6_TO_3_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_3_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_3_IN_BASE 0x1338
#define FIFO_6_TO_3_IN_BITS_PER_SYMBOL 16
#define FIFO_6_TO_3_IN_CHANNEL_WIDTH 8
#define FIFO_6_TO_3_IN_ERROR_WIDTH 8
#define FIFO_6_TO_3_IN_FIFO_DEPTH 16
#define FIFO_6_TO_3_IN_IRQ -1
#define FIFO_6_TO_3_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_3_IN_NAME "/dev/fifo_6_to_3_in"
#define FIFO_6_TO_3_IN_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_3_IN_SPAN 4
#define FIFO_6_TO_3_IN_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_3_IN_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_3_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_3_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_3_IN_USE_AVALONST_SINK 0
#define FIFO_6_TO_3_IN_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_3_IN_USE_BACKPRESSURE 1
#define FIFO_6_TO_3_IN_USE_IRQ 0
#define FIFO_6_TO_3_IN_USE_PACKET 1
#define FIFO_6_TO_3_IN_USE_READ_CONTROL 1
#define FIFO_6_TO_3_IN_USE_REGISTER 0
#define FIFO_6_TO_3_IN_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_3_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_3_in_csr altera_avalon_fifo
#define FIFO_6_TO_3_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_3_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_3_IN_CSR_BASE 0x1140
#define FIFO_6_TO_3_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_3_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_3_IN_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_3_IN_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_3_IN_CSR_IRQ -1
#define FIFO_6_TO_3_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_3_IN_CSR_NAME "/dev/fifo_6_to_3_in_csr"
#define FIFO_6_TO_3_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_3_IN_CSR_SPAN 32
#define FIFO_6_TO_3_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_3_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_3_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_3_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_3_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_3_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_3_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_3_IN_CSR_USE_IRQ 0
#define FIFO_6_TO_3_IN_CSR_USE_PACKET 1
#define FIFO_6_TO_3_IN_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_3_IN_CSR_USE_REGISTER 0
#define FIFO_6_TO_3_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_4_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_4_in altera_avalon_fifo
#define FIFO_6_TO_4_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_4_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_4_IN_BASE 0x1334
#define FIFO_6_TO_4_IN_BITS_PER_SYMBOL 16
#define FIFO_6_TO_4_IN_CHANNEL_WIDTH 8
#define FIFO_6_TO_4_IN_ERROR_WIDTH 8
#define FIFO_6_TO_4_IN_FIFO_DEPTH 16
#define FIFO_6_TO_4_IN_IRQ -1
#define FIFO_6_TO_4_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_4_IN_NAME "/dev/fifo_6_to_4_in"
#define FIFO_6_TO_4_IN_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_4_IN_SPAN 4
#define FIFO_6_TO_4_IN_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_4_IN_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_4_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_4_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_4_IN_USE_AVALONST_SINK 0
#define FIFO_6_TO_4_IN_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_4_IN_USE_BACKPRESSURE 1
#define FIFO_6_TO_4_IN_USE_IRQ 0
#define FIFO_6_TO_4_IN_USE_PACKET 1
#define FIFO_6_TO_4_IN_USE_READ_CONTROL 1
#define FIFO_6_TO_4_IN_USE_REGISTER 0
#define FIFO_6_TO_4_IN_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_4_in_csr altera_avalon_fifo
#define FIFO_6_TO_4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_4_IN_CSR_BASE 0x1120
#define FIFO_6_TO_4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_4_IN_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_4_IN_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_4_IN_CSR_IRQ -1
#define FIFO_6_TO_4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_4_IN_CSR_NAME "/dev/fifo_6_to_4_in_csr"
#define FIFO_6_TO_4_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_4_IN_CSR_SPAN 32
#define FIFO_6_TO_4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_4_IN_CSR_USE_IRQ 0
#define FIFO_6_TO_4_IN_CSR_USE_PACKET 1
#define FIFO_6_TO_4_IN_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_4_IN_CSR_USE_REGISTER 0
#define FIFO_6_TO_4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_5_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_5_in altera_avalon_fifo
#define FIFO_6_TO_5_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_5_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_5_IN_BASE 0x1330
#define FIFO_6_TO_5_IN_BITS_PER_SYMBOL 16
#define FIFO_6_TO_5_IN_CHANNEL_WIDTH 8
#define FIFO_6_TO_5_IN_ERROR_WIDTH 8
#define FIFO_6_TO_5_IN_FIFO_DEPTH 16
#define FIFO_6_TO_5_IN_IRQ -1
#define FIFO_6_TO_5_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_5_IN_NAME "/dev/fifo_6_to_5_in"
#define FIFO_6_TO_5_IN_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_5_IN_SPAN 4
#define FIFO_6_TO_5_IN_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_5_IN_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_5_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_5_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_5_IN_USE_AVALONST_SINK 0
#define FIFO_6_TO_5_IN_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_5_IN_USE_BACKPRESSURE 1
#define FIFO_6_TO_5_IN_USE_IRQ 0
#define FIFO_6_TO_5_IN_USE_PACKET 1
#define FIFO_6_TO_5_IN_USE_READ_CONTROL 1
#define FIFO_6_TO_5_IN_USE_REGISTER 0
#define FIFO_6_TO_5_IN_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_5_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_5_in_csr altera_avalon_fifo
#define FIFO_6_TO_5_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_5_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_5_IN_CSR_BASE 0x1100
#define FIFO_6_TO_5_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_5_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_5_IN_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_5_IN_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_5_IN_CSR_IRQ -1
#define FIFO_6_TO_5_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_5_IN_CSR_NAME "/dev/fifo_6_to_5_in_csr"
#define FIFO_6_TO_5_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_5_IN_CSR_SPAN 32
#define FIFO_6_TO_5_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_5_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_5_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_5_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_5_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_5_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_5_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_5_IN_CSR_USE_IRQ 0
#define FIFO_6_TO_5_IN_CSR_USE_PACKET 1
#define FIFO_6_TO_5_IN_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_5_IN_CSR_USE_REGISTER 0
#define FIFO_6_TO_5_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_7_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_7_in altera_avalon_fifo
#define FIFO_6_TO_7_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_7_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_7_IN_BASE 0x132c
#define FIFO_6_TO_7_IN_BITS_PER_SYMBOL 16
#define FIFO_6_TO_7_IN_CHANNEL_WIDTH 8
#define FIFO_6_TO_7_IN_ERROR_WIDTH 8
#define FIFO_6_TO_7_IN_FIFO_DEPTH 16
#define FIFO_6_TO_7_IN_IRQ -1
#define FIFO_6_TO_7_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_7_IN_NAME "/dev/fifo_6_to_7_in"
#define FIFO_6_TO_7_IN_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_7_IN_SPAN 4
#define FIFO_6_TO_7_IN_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_7_IN_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_7_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_7_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_7_IN_USE_AVALONST_SINK 0
#define FIFO_6_TO_7_IN_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_7_IN_USE_BACKPRESSURE 1
#define FIFO_6_TO_7_IN_USE_IRQ 0
#define FIFO_6_TO_7_IN_USE_PACKET 1
#define FIFO_6_TO_7_IN_USE_READ_CONTROL 1
#define FIFO_6_TO_7_IN_USE_REGISTER 0
#define FIFO_6_TO_7_IN_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_7_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_7_in_csr altera_avalon_fifo
#define FIFO_6_TO_7_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_7_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_7_IN_CSR_BASE 0x10e0
#define FIFO_6_TO_7_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_7_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_7_IN_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_7_IN_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_7_IN_CSR_IRQ -1
#define FIFO_6_TO_7_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_7_IN_CSR_NAME "/dev/fifo_6_to_7_in_csr"
#define FIFO_6_TO_7_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_7_IN_CSR_SPAN 32
#define FIFO_6_TO_7_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_7_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_7_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_7_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_7_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_7_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_7_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_7_IN_CSR_USE_IRQ 0
#define FIFO_6_TO_7_IN_CSR_USE_PACKET 1
#define FIFO_6_TO_7_IN_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_7_IN_CSR_USE_REGISTER 0
#define FIFO_6_TO_7_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_6_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_6_out altera_avalon_fifo
#define FIFO_7_TO_6_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_6_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_6_OUT_BASE 0x1328
#define FIFO_7_TO_6_OUT_BITS_PER_SYMBOL 16
#define FIFO_7_TO_6_OUT_CHANNEL_WIDTH 8
#define FIFO_7_TO_6_OUT_ERROR_WIDTH 8
#define FIFO_7_TO_6_OUT_FIFO_DEPTH 16
#define FIFO_7_TO_6_OUT_IRQ -1
#define FIFO_7_TO_6_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_6_OUT_NAME "/dev/fifo_7_to_6_out"
#define FIFO_7_TO_6_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_6_OUT_SPAN 4
#define FIFO_7_TO_6_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_6_OUT_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_6_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_6_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_6_OUT_USE_AVALONST_SINK 0
#define FIFO_7_TO_6_OUT_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_6_OUT_USE_BACKPRESSURE 1
#define FIFO_7_TO_6_OUT_USE_IRQ 0
#define FIFO_7_TO_6_OUT_USE_PACKET 1
#define FIFO_7_TO_6_OUT_USE_READ_CONTROL 1
#define FIFO_7_TO_6_OUT_USE_REGISTER 0
#define FIFO_7_TO_6_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_6_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_6_out_csr altera_avalon_fifo
#define FIFO_7_TO_6_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_6_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_6_OUT_CSR_BASE 0x10c0
#define FIFO_7_TO_6_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_6_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_6_OUT_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_6_OUT_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_6_OUT_CSR_IRQ -1
#define FIFO_7_TO_6_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_6_OUT_CSR_NAME "/dev/fifo_7_to_6_out_csr"
#define FIFO_7_TO_6_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_6_OUT_CSR_SPAN 32
#define FIFO_7_TO_6_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_6_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_6_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_6_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_6_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_6_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_6_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_6_OUT_CSR_USE_IRQ 0
#define FIFO_7_TO_6_OUT_CSR_USE_PACKET 1
#define FIFO_7_TO_6_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_6_OUT_CSR_USE_REGISTER 0
#define FIFO_7_TO_6_OUT_CSR_USE_WRITE_CONTROL 1




/********************/
/* system.h - CPU 7 */
/********************/


/*
 * fifo_0_to_7_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_7_out altera_avalon_fifo
#define FIFO_0_TO_7_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_7_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_7_OUT_BASE 0x135c
#define FIFO_0_TO_7_OUT_BITS_PER_SYMBOL 16
#define FIFO_0_TO_7_OUT_CHANNEL_WIDTH 8
#define FIFO_0_TO_7_OUT_ERROR_WIDTH 8
#define FIFO_0_TO_7_OUT_FIFO_DEPTH 16
#define FIFO_0_TO_7_OUT_IRQ -1
#define FIFO_0_TO_7_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_7_OUT_NAME "/dev/fifo_0_to_7_out"
#define FIFO_0_TO_7_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_7_OUT_SPAN 4
#define FIFO_0_TO_7_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_7_OUT_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_7_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_7_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_7_OUT_USE_AVALONST_SINK 0
#define FIFO_0_TO_7_OUT_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_7_OUT_USE_BACKPRESSURE 1
#define FIFO_0_TO_7_OUT_USE_IRQ 0
#define FIFO_0_TO_7_OUT_USE_PACKET 1
#define FIFO_0_TO_7_OUT_USE_READ_CONTROL 1
#define FIFO_0_TO_7_OUT_USE_REGISTER 0
#define FIFO_0_TO_7_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_0_to_7_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_0_to_7_out_csr altera_avalon_fifo
#define FIFO_0_TO_7_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_0_TO_7_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_0_TO_7_OUT_CSR_BASE 0x1280
#define FIFO_0_TO_7_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_0_TO_7_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_0_TO_7_OUT_CSR_ERROR_WIDTH 8
#define FIFO_0_TO_7_OUT_CSR_FIFO_DEPTH 16
#define FIFO_0_TO_7_OUT_CSR_IRQ -1
#define FIFO_0_TO_7_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_0_TO_7_OUT_CSR_NAME "/dev/fifo_0_to_7_out_csr"
#define FIFO_0_TO_7_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_0_TO_7_OUT_CSR_SPAN 32
#define FIFO_0_TO_7_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_0_TO_7_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_0_TO_7_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_0_TO_7_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_0_TO_7_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_0_TO_7_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_0_TO_7_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_0_TO_7_OUT_CSR_USE_IRQ 0
#define FIFO_0_TO_7_OUT_CSR_USE_PACKET 1
#define FIFO_0_TO_7_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_0_TO_7_OUT_CSR_USE_REGISTER 0
#define FIFO_0_TO_7_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_7_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_7_out altera_avalon_fifo
#define FIFO_1_TO_7_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_7_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_7_OUT_BASE 0x1358
#define FIFO_1_TO_7_OUT_BITS_PER_SYMBOL 16
#define FIFO_1_TO_7_OUT_CHANNEL_WIDTH 8
#define FIFO_1_TO_7_OUT_ERROR_WIDTH 8
#define FIFO_1_TO_7_OUT_FIFO_DEPTH 16
#define FIFO_1_TO_7_OUT_IRQ -1
#define FIFO_1_TO_7_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_7_OUT_NAME "/dev/fifo_1_to_7_out"
#define FIFO_1_TO_7_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_7_OUT_SPAN 4
#define FIFO_1_TO_7_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_7_OUT_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_7_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_7_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_7_OUT_USE_AVALONST_SINK 0
#define FIFO_1_TO_7_OUT_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_7_OUT_USE_BACKPRESSURE 1
#define FIFO_1_TO_7_OUT_USE_IRQ 0
#define FIFO_1_TO_7_OUT_USE_PACKET 1
#define FIFO_1_TO_7_OUT_USE_READ_CONTROL 1
#define FIFO_1_TO_7_OUT_USE_REGISTER 0
#define FIFO_1_TO_7_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_1_to_7_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1_to_7_out_csr altera_avalon_fifo
#define FIFO_1_TO_7_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1_TO_7_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1_TO_7_OUT_CSR_BASE 0x1260
#define FIFO_1_TO_7_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_1_TO_7_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_1_TO_7_OUT_CSR_ERROR_WIDTH 8
#define FIFO_1_TO_7_OUT_CSR_FIFO_DEPTH 16
#define FIFO_1_TO_7_OUT_CSR_IRQ -1
#define FIFO_1_TO_7_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1_TO_7_OUT_CSR_NAME "/dev/fifo_1_to_7_out_csr"
#define FIFO_1_TO_7_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_1_TO_7_OUT_CSR_SPAN 32
#define FIFO_1_TO_7_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1_TO_7_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1_TO_7_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1_TO_7_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1_TO_7_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_1_TO_7_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1_TO_7_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_1_TO_7_OUT_CSR_USE_IRQ 0
#define FIFO_1_TO_7_OUT_CSR_USE_PACKET 1
#define FIFO_1_TO_7_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_1_TO_7_OUT_CSR_USE_REGISTER 0
#define FIFO_1_TO_7_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_7_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_7_out altera_avalon_fifo
#define FIFO_2_TO_7_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_7_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_7_OUT_BASE 0x1354
#define FIFO_2_TO_7_OUT_BITS_PER_SYMBOL 16
#define FIFO_2_TO_7_OUT_CHANNEL_WIDTH 8
#define FIFO_2_TO_7_OUT_ERROR_WIDTH 8
#define FIFO_2_TO_7_OUT_FIFO_DEPTH 16
#define FIFO_2_TO_7_OUT_IRQ -1
#define FIFO_2_TO_7_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_7_OUT_NAME "/dev/fifo_2_to_7_out"
#define FIFO_2_TO_7_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_7_OUT_SPAN 4
#define FIFO_2_TO_7_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_7_OUT_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_7_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_7_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_7_OUT_USE_AVALONST_SINK 0
#define FIFO_2_TO_7_OUT_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_7_OUT_USE_BACKPRESSURE 1
#define FIFO_2_TO_7_OUT_USE_IRQ 0
#define FIFO_2_TO_7_OUT_USE_PACKET 1
#define FIFO_2_TO_7_OUT_USE_READ_CONTROL 1
#define FIFO_2_TO_7_OUT_USE_REGISTER 0
#define FIFO_2_TO_7_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_2_to_7_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_2_to_7_out_csr altera_avalon_fifo
#define FIFO_2_TO_7_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_2_TO_7_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_2_TO_7_OUT_CSR_BASE 0x1240
#define FIFO_2_TO_7_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_2_TO_7_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_2_TO_7_OUT_CSR_ERROR_WIDTH 8
#define FIFO_2_TO_7_OUT_CSR_FIFO_DEPTH 16
#define FIFO_2_TO_7_OUT_CSR_IRQ -1
#define FIFO_2_TO_7_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_2_TO_7_OUT_CSR_NAME "/dev/fifo_2_to_7_out_csr"
#define FIFO_2_TO_7_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_2_TO_7_OUT_CSR_SPAN 32
#define FIFO_2_TO_7_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_2_TO_7_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_2_TO_7_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_2_TO_7_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_2_TO_7_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_2_TO_7_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_2_TO_7_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_2_TO_7_OUT_CSR_USE_IRQ 0
#define FIFO_2_TO_7_OUT_CSR_USE_PACKET 1
#define FIFO_2_TO_7_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_2_TO_7_OUT_CSR_USE_REGISTER 0
#define FIFO_2_TO_7_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_7_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_7_out altera_avalon_fifo
#define FIFO_3_TO_7_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_7_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_7_OUT_BASE 0x1350
#define FIFO_3_TO_7_OUT_BITS_PER_SYMBOL 16
#define FIFO_3_TO_7_OUT_CHANNEL_WIDTH 8
#define FIFO_3_TO_7_OUT_ERROR_WIDTH 8
#define FIFO_3_TO_7_OUT_FIFO_DEPTH 16
#define FIFO_3_TO_7_OUT_IRQ -1
#define FIFO_3_TO_7_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_7_OUT_NAME "/dev/fifo_3_to_7_out"
#define FIFO_3_TO_7_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_7_OUT_SPAN 4
#define FIFO_3_TO_7_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_7_OUT_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_7_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_7_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_7_OUT_USE_AVALONST_SINK 0
#define FIFO_3_TO_7_OUT_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_7_OUT_USE_BACKPRESSURE 1
#define FIFO_3_TO_7_OUT_USE_IRQ 0
#define FIFO_3_TO_7_OUT_USE_PACKET 1
#define FIFO_3_TO_7_OUT_USE_READ_CONTROL 1
#define FIFO_3_TO_7_OUT_USE_REGISTER 0
#define FIFO_3_TO_7_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_3_to_7_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_3_to_7_out_csr altera_avalon_fifo
#define FIFO_3_TO_7_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_3_TO_7_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_3_TO_7_OUT_CSR_BASE 0x1220
#define FIFO_3_TO_7_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_3_TO_7_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_3_TO_7_OUT_CSR_ERROR_WIDTH 8
#define FIFO_3_TO_7_OUT_CSR_FIFO_DEPTH 16
#define FIFO_3_TO_7_OUT_CSR_IRQ -1
#define FIFO_3_TO_7_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_3_TO_7_OUT_CSR_NAME "/dev/fifo_3_to_7_out_csr"
#define FIFO_3_TO_7_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_3_TO_7_OUT_CSR_SPAN 32
#define FIFO_3_TO_7_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_3_TO_7_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_3_TO_7_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_3_TO_7_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_3_TO_7_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_3_TO_7_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_3_TO_7_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_3_TO_7_OUT_CSR_USE_IRQ 0
#define FIFO_3_TO_7_OUT_CSR_USE_PACKET 1
#define FIFO_3_TO_7_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_3_TO_7_OUT_CSR_USE_REGISTER 0
#define FIFO_3_TO_7_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_7_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_7_out altera_avalon_fifo
#define FIFO_4_TO_7_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_7_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_7_OUT_BASE 0x134c
#define FIFO_4_TO_7_OUT_BITS_PER_SYMBOL 16
#define FIFO_4_TO_7_OUT_CHANNEL_WIDTH 8
#define FIFO_4_TO_7_OUT_ERROR_WIDTH 8
#define FIFO_4_TO_7_OUT_FIFO_DEPTH 16
#define FIFO_4_TO_7_OUT_IRQ -1
#define FIFO_4_TO_7_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_7_OUT_NAME "/dev/fifo_4_to_7_out"
#define FIFO_4_TO_7_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_7_OUT_SPAN 4
#define FIFO_4_TO_7_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_7_OUT_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_7_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_7_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_7_OUT_USE_AVALONST_SINK 0
#define FIFO_4_TO_7_OUT_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_7_OUT_USE_BACKPRESSURE 1
#define FIFO_4_TO_7_OUT_USE_IRQ 0
#define FIFO_4_TO_7_OUT_USE_PACKET 1
#define FIFO_4_TO_7_OUT_USE_READ_CONTROL 1
#define FIFO_4_TO_7_OUT_USE_REGISTER 0
#define FIFO_4_TO_7_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_4_to_7_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_4_to_7_out_csr altera_avalon_fifo
#define FIFO_4_TO_7_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_4_TO_7_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_4_TO_7_OUT_CSR_BASE 0x1200
#define FIFO_4_TO_7_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_4_TO_7_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_4_TO_7_OUT_CSR_ERROR_WIDTH 8
#define FIFO_4_TO_7_OUT_CSR_FIFO_DEPTH 16
#define FIFO_4_TO_7_OUT_CSR_IRQ -1
#define FIFO_4_TO_7_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_4_TO_7_OUT_CSR_NAME "/dev/fifo_4_to_7_out_csr"
#define FIFO_4_TO_7_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_4_TO_7_OUT_CSR_SPAN 32
#define FIFO_4_TO_7_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_4_TO_7_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_4_TO_7_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_4_TO_7_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_4_TO_7_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_4_TO_7_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_4_TO_7_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_4_TO_7_OUT_CSR_USE_IRQ 0
#define FIFO_4_TO_7_OUT_CSR_USE_PACKET 1
#define FIFO_4_TO_7_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_4_TO_7_OUT_CSR_USE_REGISTER 0
#define FIFO_4_TO_7_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_7_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_7_out altera_avalon_fifo
#define FIFO_5_TO_7_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_7_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_7_OUT_BASE 0x1348
#define FIFO_5_TO_7_OUT_BITS_PER_SYMBOL 16
#define FIFO_5_TO_7_OUT_CHANNEL_WIDTH 8
#define FIFO_5_TO_7_OUT_ERROR_WIDTH 8
#define FIFO_5_TO_7_OUT_FIFO_DEPTH 16
#define FIFO_5_TO_7_OUT_IRQ -1
#define FIFO_5_TO_7_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_7_OUT_NAME "/dev/fifo_5_to_7_out"
#define FIFO_5_TO_7_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_7_OUT_SPAN 4
#define FIFO_5_TO_7_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_7_OUT_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_7_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_7_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_7_OUT_USE_AVALONST_SINK 0
#define FIFO_5_TO_7_OUT_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_7_OUT_USE_BACKPRESSURE 1
#define FIFO_5_TO_7_OUT_USE_IRQ 0
#define FIFO_5_TO_7_OUT_USE_PACKET 1
#define FIFO_5_TO_7_OUT_USE_READ_CONTROL 1
#define FIFO_5_TO_7_OUT_USE_REGISTER 0
#define FIFO_5_TO_7_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_5_to_7_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_5_to_7_out_csr altera_avalon_fifo
#define FIFO_5_TO_7_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_5_TO_7_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_5_TO_7_OUT_CSR_BASE 0x11e0
#define FIFO_5_TO_7_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_5_TO_7_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_5_TO_7_OUT_CSR_ERROR_WIDTH 8
#define FIFO_5_TO_7_OUT_CSR_FIFO_DEPTH 16
#define FIFO_5_TO_7_OUT_CSR_IRQ -1
#define FIFO_5_TO_7_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_5_TO_7_OUT_CSR_NAME "/dev/fifo_5_to_7_out_csr"
#define FIFO_5_TO_7_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_5_TO_7_OUT_CSR_SPAN 32
#define FIFO_5_TO_7_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_5_TO_7_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_5_TO_7_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_5_TO_7_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_5_TO_7_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_5_TO_7_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_5_TO_7_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_5_TO_7_OUT_CSR_USE_IRQ 0
#define FIFO_5_TO_7_OUT_CSR_USE_PACKET 1
#define FIFO_5_TO_7_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_5_TO_7_OUT_CSR_USE_REGISTER 0
#define FIFO_5_TO_7_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_7_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_7_out altera_avalon_fifo
#define FIFO_6_TO_7_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_7_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_7_OUT_BASE 0x1344
#define FIFO_6_TO_7_OUT_BITS_PER_SYMBOL 16
#define FIFO_6_TO_7_OUT_CHANNEL_WIDTH 8
#define FIFO_6_TO_7_OUT_ERROR_WIDTH 8
#define FIFO_6_TO_7_OUT_FIFO_DEPTH 16
#define FIFO_6_TO_7_OUT_IRQ -1
#define FIFO_6_TO_7_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_7_OUT_NAME "/dev/fifo_6_to_7_out"
#define FIFO_6_TO_7_OUT_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_7_OUT_SPAN 4
#define FIFO_6_TO_7_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_7_OUT_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_7_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_7_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_7_OUT_USE_AVALONST_SINK 0
#define FIFO_6_TO_7_OUT_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_7_OUT_USE_BACKPRESSURE 1
#define FIFO_6_TO_7_OUT_USE_IRQ 0
#define FIFO_6_TO_7_OUT_USE_PACKET 1
#define FIFO_6_TO_7_OUT_USE_READ_CONTROL 1
#define FIFO_6_TO_7_OUT_USE_REGISTER 0
#define FIFO_6_TO_7_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_6_to_7_out_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_6_to_7_out_csr altera_avalon_fifo
#define FIFO_6_TO_7_OUT_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_6_TO_7_OUT_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_6_TO_7_OUT_CSR_BASE 0x11a0
#define FIFO_6_TO_7_OUT_CSR_BITS_PER_SYMBOL 16
#define FIFO_6_TO_7_OUT_CSR_CHANNEL_WIDTH 8
#define FIFO_6_TO_7_OUT_CSR_ERROR_WIDTH 8
#define FIFO_6_TO_7_OUT_CSR_FIFO_DEPTH 16
#define FIFO_6_TO_7_OUT_CSR_IRQ -1
#define FIFO_6_TO_7_OUT_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_6_TO_7_OUT_CSR_NAME "/dev/fifo_6_to_7_out_csr"
#define FIFO_6_TO_7_OUT_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_6_TO_7_OUT_CSR_SPAN 32
#define FIFO_6_TO_7_OUT_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_6_TO_7_OUT_CSR_TYPE "altera_avalon_fifo"
#define FIFO_6_TO_7_OUT_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_6_TO_7_OUT_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_6_TO_7_OUT_CSR_USE_AVALONST_SINK 0
#define FIFO_6_TO_7_OUT_CSR_USE_AVALONST_SOURCE 0
#define FIFO_6_TO_7_OUT_CSR_USE_BACKPRESSURE 1
#define FIFO_6_TO_7_OUT_CSR_USE_IRQ 0
#define FIFO_6_TO_7_OUT_CSR_USE_PACKET 1
#define FIFO_6_TO_7_OUT_CSR_USE_READ_CONTROL 1
#define FIFO_6_TO_7_OUT_CSR_USE_REGISTER 0
#define FIFO_6_TO_7_OUT_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_0_in altera_avalon_fifo
#define FIFO_7_TO_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_0_IN_BASE 0x1340
#define FIFO_7_TO_0_IN_BITS_PER_SYMBOL 16
#define FIFO_7_TO_0_IN_CHANNEL_WIDTH 8
#define FIFO_7_TO_0_IN_ERROR_WIDTH 8
#define FIFO_7_TO_0_IN_FIFO_DEPTH 16
#define FIFO_7_TO_0_IN_IRQ -1
#define FIFO_7_TO_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_0_IN_NAME "/dev/fifo_7_to_0_in"
#define FIFO_7_TO_0_IN_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_0_IN_SPAN 4
#define FIFO_7_TO_0_IN_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_0_IN_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_0_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_0_IN_USE_AVALONST_SINK 0
#define FIFO_7_TO_0_IN_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_0_IN_USE_BACKPRESSURE 1
#define FIFO_7_TO_0_IN_USE_IRQ 0
#define FIFO_7_TO_0_IN_USE_PACKET 1
#define FIFO_7_TO_0_IN_USE_READ_CONTROL 1
#define FIFO_7_TO_0_IN_USE_REGISTER 0
#define FIFO_7_TO_0_IN_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_0_in_csr altera_avalon_fifo
#define FIFO_7_TO_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_0_IN_CSR_BASE 0x1180
#define FIFO_7_TO_0_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_0_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_0_IN_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_0_IN_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_0_IN_CSR_IRQ -1
#define FIFO_7_TO_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_0_IN_CSR_NAME "/dev/fifo_7_to_0_in_csr"
#define FIFO_7_TO_0_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_0_IN_CSR_SPAN 32
#define FIFO_7_TO_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_0_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_0_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_0_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_0_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_0_IN_CSR_USE_IRQ 0
#define FIFO_7_TO_0_IN_CSR_USE_PACKET 1
#define FIFO_7_TO_0_IN_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_0_IN_CSR_USE_REGISTER 0
#define FIFO_7_TO_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_1_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_1_in altera_avalon_fifo
#define FIFO_7_TO_1_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_1_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_1_IN_BASE 0x133c
#define FIFO_7_TO_1_IN_BITS_PER_SYMBOL 16
#define FIFO_7_TO_1_IN_CHANNEL_WIDTH 8
#define FIFO_7_TO_1_IN_ERROR_WIDTH 8
#define FIFO_7_TO_1_IN_FIFO_DEPTH 16
#define FIFO_7_TO_1_IN_IRQ -1
#define FIFO_7_TO_1_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_1_IN_NAME "/dev/fifo_7_to_1_in"
#define FIFO_7_TO_1_IN_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_1_IN_SPAN 4
#define FIFO_7_TO_1_IN_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_1_IN_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_1_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_1_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_1_IN_USE_AVALONST_SINK 0
#define FIFO_7_TO_1_IN_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_1_IN_USE_BACKPRESSURE 1
#define FIFO_7_TO_1_IN_USE_IRQ 0
#define FIFO_7_TO_1_IN_USE_PACKET 1
#define FIFO_7_TO_1_IN_USE_READ_CONTROL 1
#define FIFO_7_TO_1_IN_USE_REGISTER 0
#define FIFO_7_TO_1_IN_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_1_in_csr altera_avalon_fifo
#define FIFO_7_TO_1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_1_IN_CSR_BASE 0x1160
#define FIFO_7_TO_1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_1_IN_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_1_IN_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_1_IN_CSR_IRQ -1
#define FIFO_7_TO_1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_1_IN_CSR_NAME "/dev/fifo_7_to_1_in_csr"
#define FIFO_7_TO_1_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_1_IN_CSR_SPAN 32
#define FIFO_7_TO_1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_1_IN_CSR_USE_IRQ 0
#define FIFO_7_TO_1_IN_CSR_USE_PACKET 1
#define FIFO_7_TO_1_IN_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_1_IN_CSR_USE_REGISTER 0
#define FIFO_7_TO_1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_2_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_2_in altera_avalon_fifo
#define FIFO_7_TO_2_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_2_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_2_IN_BASE 0x1338
#define FIFO_7_TO_2_IN_BITS_PER_SYMBOL 16
#define FIFO_7_TO_2_IN_CHANNEL_WIDTH 8
#define FIFO_7_TO_2_IN_ERROR_WIDTH 8
#define FIFO_7_TO_2_IN_FIFO_DEPTH 16
#define FIFO_7_TO_2_IN_IRQ -1
#define FIFO_7_TO_2_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_2_IN_NAME "/dev/fifo_7_to_2_in"
#define FIFO_7_TO_2_IN_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_2_IN_SPAN 4
#define FIFO_7_TO_2_IN_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_2_IN_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_2_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_2_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_2_IN_USE_AVALONST_SINK 0
#define FIFO_7_TO_2_IN_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_2_IN_USE_BACKPRESSURE 1
#define FIFO_7_TO_2_IN_USE_IRQ 0
#define FIFO_7_TO_2_IN_USE_PACKET 1
#define FIFO_7_TO_2_IN_USE_READ_CONTROL 1
#define FIFO_7_TO_2_IN_USE_REGISTER 0
#define FIFO_7_TO_2_IN_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_2_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_2_in_csr altera_avalon_fifo
#define FIFO_7_TO_2_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_2_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_2_IN_CSR_BASE 0x1140
#define FIFO_7_TO_2_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_2_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_2_IN_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_2_IN_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_2_IN_CSR_IRQ -1
#define FIFO_7_TO_2_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_2_IN_CSR_NAME "/dev/fifo_7_to_2_in_csr"
#define FIFO_7_TO_2_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_2_IN_CSR_SPAN 32
#define FIFO_7_TO_2_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_2_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_2_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_2_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_2_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_2_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_2_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_2_IN_CSR_USE_IRQ 0
#define FIFO_7_TO_2_IN_CSR_USE_PACKET 1
#define FIFO_7_TO_2_IN_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_2_IN_CSR_USE_REGISTER 0
#define FIFO_7_TO_2_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_3_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_3_in altera_avalon_fifo
#define FIFO_7_TO_3_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_3_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_3_IN_BASE 0x1328
#define FIFO_7_TO_3_IN_BITS_PER_SYMBOL 16
#define FIFO_7_TO_3_IN_CHANNEL_WIDTH 8
#define FIFO_7_TO_3_IN_ERROR_WIDTH 8
#define FIFO_7_TO_3_IN_FIFO_DEPTH 16
#define FIFO_7_TO_3_IN_IRQ -1
#define FIFO_7_TO_3_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_3_IN_NAME "/dev/fifo_7_to_3_in"
#define FIFO_7_TO_3_IN_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_3_IN_SPAN 4
#define FIFO_7_TO_3_IN_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_3_IN_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_3_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_3_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_3_IN_USE_AVALONST_SINK 0
#define FIFO_7_TO_3_IN_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_3_IN_USE_BACKPRESSURE 1
#define FIFO_7_TO_3_IN_USE_IRQ 0
#define FIFO_7_TO_3_IN_USE_PACKET 1
#define FIFO_7_TO_3_IN_USE_READ_CONTROL 1
#define FIFO_7_TO_3_IN_USE_REGISTER 0
#define FIFO_7_TO_3_IN_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_3_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_3_in_csr altera_avalon_fifo
#define FIFO_7_TO_3_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_3_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_3_IN_CSR_BASE 0x1120
#define FIFO_7_TO_3_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_3_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_3_IN_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_3_IN_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_3_IN_CSR_IRQ -1
#define FIFO_7_TO_3_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_3_IN_CSR_NAME "/dev/fifo_7_to_3_in_csr"
#define FIFO_7_TO_3_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_3_IN_CSR_SPAN 32
#define FIFO_7_TO_3_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_3_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_3_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_3_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_3_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_3_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_3_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_3_IN_CSR_USE_IRQ 0
#define FIFO_7_TO_3_IN_CSR_USE_PACKET 1
#define FIFO_7_TO_3_IN_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_3_IN_CSR_USE_REGISTER 0
#define FIFO_7_TO_3_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_4_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_4_in altera_avalon_fifo
#define FIFO_7_TO_4_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_4_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_4_IN_BASE 0x1334
#define FIFO_7_TO_4_IN_BITS_PER_SYMBOL 16
#define FIFO_7_TO_4_IN_CHANNEL_WIDTH 8
#define FIFO_7_TO_4_IN_ERROR_WIDTH 8
#define FIFO_7_TO_4_IN_FIFO_DEPTH 16
#define FIFO_7_TO_4_IN_IRQ -1
#define FIFO_7_TO_4_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_4_IN_NAME "/dev/fifo_7_to_4_in"
#define FIFO_7_TO_4_IN_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_4_IN_SPAN 4
#define FIFO_7_TO_4_IN_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_4_IN_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_4_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_4_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_4_IN_USE_AVALONST_SINK 0
#define FIFO_7_TO_4_IN_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_4_IN_USE_BACKPRESSURE 1
#define FIFO_7_TO_4_IN_USE_IRQ 0
#define FIFO_7_TO_4_IN_USE_PACKET 1
#define FIFO_7_TO_4_IN_USE_READ_CONTROL 1
#define FIFO_7_TO_4_IN_USE_REGISTER 0
#define FIFO_7_TO_4_IN_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_4_in_csr altera_avalon_fifo
#define FIFO_7_TO_4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_4_IN_CSR_BASE 0x1100
#define FIFO_7_TO_4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_4_IN_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_4_IN_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_4_IN_CSR_IRQ -1
#define FIFO_7_TO_4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_4_IN_CSR_NAME "/dev/fifo_7_to_4_in_csr"
#define FIFO_7_TO_4_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_4_IN_CSR_SPAN 32
#define FIFO_7_TO_4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_4_IN_CSR_USE_IRQ 0
#define FIFO_7_TO_4_IN_CSR_USE_PACKET 1
#define FIFO_7_TO_4_IN_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_4_IN_CSR_USE_REGISTER 0
#define FIFO_7_TO_4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_5_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_5_in altera_avalon_fifo
#define FIFO_7_TO_5_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_5_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_5_IN_BASE 0x1330
#define FIFO_7_TO_5_IN_BITS_PER_SYMBOL 16
#define FIFO_7_TO_5_IN_CHANNEL_WIDTH 8
#define FIFO_7_TO_5_IN_ERROR_WIDTH 8
#define FIFO_7_TO_5_IN_FIFO_DEPTH 16
#define FIFO_7_TO_5_IN_IRQ -1
#define FIFO_7_TO_5_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_5_IN_NAME "/dev/fifo_7_to_5_in"
#define FIFO_7_TO_5_IN_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_5_IN_SPAN 4
#define FIFO_7_TO_5_IN_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_5_IN_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_5_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_5_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_5_IN_USE_AVALONST_SINK 0
#define FIFO_7_TO_5_IN_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_5_IN_USE_BACKPRESSURE 1
#define FIFO_7_TO_5_IN_USE_IRQ 0
#define FIFO_7_TO_5_IN_USE_PACKET 1
#define FIFO_7_TO_5_IN_USE_READ_CONTROL 1
#define FIFO_7_TO_5_IN_USE_REGISTER 0
#define FIFO_7_TO_5_IN_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_5_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_5_in_csr altera_avalon_fifo
#define FIFO_7_TO_5_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_5_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_5_IN_CSR_BASE 0x10e0
#define FIFO_7_TO_5_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_5_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_5_IN_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_5_IN_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_5_IN_CSR_IRQ -1
#define FIFO_7_TO_5_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_5_IN_CSR_NAME "/dev/fifo_7_to_5_in_csr"
#define FIFO_7_TO_5_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_5_IN_CSR_SPAN 32
#define FIFO_7_TO_5_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_5_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_5_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_5_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_5_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_5_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_5_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_5_IN_CSR_USE_IRQ 0
#define FIFO_7_TO_5_IN_CSR_USE_PACKET 1
#define FIFO_7_TO_5_IN_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_5_IN_CSR_USE_REGISTER 0
#define FIFO_7_TO_5_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_6_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_6_in altera_avalon_fifo
#define FIFO_7_TO_6_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_6_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_6_IN_BASE 0x132c
#define FIFO_7_TO_6_IN_BITS_PER_SYMBOL 16
#define FIFO_7_TO_6_IN_CHANNEL_WIDTH 8
#define FIFO_7_TO_6_IN_ERROR_WIDTH 8
#define FIFO_7_TO_6_IN_FIFO_DEPTH 16
#define FIFO_7_TO_6_IN_IRQ -1
#define FIFO_7_TO_6_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_6_IN_NAME "/dev/fifo_7_to_6_in"
#define FIFO_7_TO_6_IN_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_6_IN_SPAN 4
#define FIFO_7_TO_6_IN_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_6_IN_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_6_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_6_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_6_IN_USE_AVALONST_SINK 0
#define FIFO_7_TO_6_IN_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_6_IN_USE_BACKPRESSURE 1
#define FIFO_7_TO_6_IN_USE_IRQ 0
#define FIFO_7_TO_6_IN_USE_PACKET 1
#define FIFO_7_TO_6_IN_USE_READ_CONTROL 1
#define FIFO_7_TO_6_IN_USE_REGISTER 0
#define FIFO_7_TO_6_IN_USE_WRITE_CONTROL 1


/*
 * fifo_7_to_6_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_7_to_6_in_csr altera_avalon_fifo
#define FIFO_7_TO_6_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_7_TO_6_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_7_TO_6_IN_CSR_BASE 0x10c0
#define FIFO_7_TO_6_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_7_TO_6_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_7_TO_6_IN_CSR_ERROR_WIDTH 8
#define FIFO_7_TO_6_IN_CSR_FIFO_DEPTH 16
#define FIFO_7_TO_6_IN_CSR_IRQ -1
#define FIFO_7_TO_6_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_7_TO_6_IN_CSR_NAME "/dev/fifo_7_to_6_in_csr"
#define FIFO_7_TO_6_IN_CSR_SINGLE_CLOCK_MODE 0
#define FIFO_7_TO_6_IN_CSR_SPAN 32
#define FIFO_7_TO_6_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_7_TO_6_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_7_TO_6_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_7_TO_6_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_7_TO_6_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_7_TO_6_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_7_TO_6_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_7_TO_6_IN_CSR_USE_IRQ 0
#define FIFO_7_TO_6_IN_CSR_USE_PACKET 1
#define FIFO_7_TO_6_IN_CSR_USE_READ_CONTROL 1
#define FIFO_7_TO_6_IN_CSR_USE_REGISTER 0
#define FIFO_7_TO_6_IN_CSR_USE_WRITE_CONTROL 1




#endif /* __INFO_H__ */
