/*
 * alt_sys_init.c - HAL initialization source
 *
 * Machine generated for CPU 'cpu_3' in SOPC Builder design 'Core8'
 * SOPC Builder design path: ../../hardware/Core7.sopcinfo
 *
 * Generated: Wed Jun 23 17:07:35 UTC 2021
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#include "system.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"

#include <stddef.h>

/*
 * Device headers
 */

#include "altera_nios2_qsys_irq.h"
#include "altera_avalon_fifo.h"
#include "altera_avalon_jtag_uart.h"
#include "altera_avalon_mutex.h"
#include "altera_avalon_performance_counter.h"
#include "altera_avalon_timer.h"

/*
 * Allocate the device storage
 */

ALTERA_NIOS2_QSYS_IRQ_INSTANCE ( CPU_3, cpu_3);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_0_TO_3, fifo_0_to_3);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_1_TO_3, fifo_1_to_3);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_2_TO_3, fifo_2_to_3);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_3_TO_0, fifo_3_to_0);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_3_TO_1, fifo_3_to_1);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_3_TO_2, fifo_3_to_2);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_3_TO_4, fifo_3_to_4);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_3_TO_5, fifo_3_to_5);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_3_TO_6, fifo_3_to_6);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_4_TO_3, fifo_4_to_3);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_5_TO_3, fifo_5_to_3);
ALTERA_AVALON_FIFO_INSTANCE ( FIFO_6_TO_3, fifo_6_to_3);
ALTERA_AVALON_JTAG_UART_INSTANCE ( JTAG_UART_3, jtag_uart_3);
ALTERA_AVALON_MUTEX_INSTANCE ( MUTEX_0, mutex_0);
ALTERA_AVALON_MUTEX_INSTANCE ( MUTEX_1, mutex_1);
ALTERA_AVALON_MUTEX_INSTANCE ( MUTEX_2, mutex_2);
ALTERA_AVALON_MUTEX_INSTANCE ( MUTEX_3, mutex_3);
ALTERA_AVALON_MUTEX_INSTANCE ( MUTEX_4, mutex_4);
ALTERA_AVALON_MUTEX_INSTANCE ( MUTEX_5, mutex_5);
ALTERA_AVALON_PERFORMANCE_COUNTER_INSTANCE ( PERFORMANCE_COUNTER_3, performance_counter_3);
ALTERA_AVALON_TIMER_INSTANCE ( TIMER_3_0, timer_3_0);
ALTERA_AVALON_TIMER_INSTANCE ( TIMER_3_1, timer_3_1);
ALTERA_AVALON_TIMER_INSTANCE ( TIMER_SHARED_0, timer_shared_0);
ALTERA_AVALON_TIMER_INSTANCE ( TIMER_SHARED_1, timer_shared_1);

/*
 * Initialize the interrupt controller devices
 * and then enable interrupts in the CPU.
 * Called before alt_sys_init().
 * The "base" parameter is ignored and only
 * present for backwards-compatibility.
 */

void alt_irq_init ( const void* base )
{
    ALTERA_NIOS2_QSYS_IRQ_INIT ( CPU_3, cpu_3);
    alt_irq_cpu_enable_interrupts();
}

/*
 * Initialize the non-interrupt controller devices.
 * Called after alt_irq_init().
 */

void alt_sys_init( void )
{
    ALTERA_AVALON_TIMER_INIT ( TIMER_3_0, timer_3_0);
    ALTERA_AVALON_TIMER_INIT ( TIMER_3_1, timer_3_1);
    ALTERA_AVALON_TIMER_INIT ( TIMER_SHARED_0, timer_shared_0);
    ALTERA_AVALON_TIMER_INIT ( TIMER_SHARED_1, timer_shared_1);
    ALTERA_AVALON_FIFO_INIT ( FIFO_0_TO_3, fifo_0_to_3);
    ALTERA_AVALON_FIFO_INIT ( FIFO_1_TO_3, fifo_1_to_3);
    ALTERA_AVALON_FIFO_INIT ( FIFO_2_TO_3, fifo_2_to_3);
    ALTERA_AVALON_FIFO_INIT ( FIFO_3_TO_0, fifo_3_to_0);
    ALTERA_AVALON_FIFO_INIT ( FIFO_3_TO_1, fifo_3_to_1);
    ALTERA_AVALON_FIFO_INIT ( FIFO_3_TO_2, fifo_3_to_2);
    ALTERA_AVALON_FIFO_INIT ( FIFO_3_TO_4, fifo_3_to_4);
    ALTERA_AVALON_FIFO_INIT ( FIFO_3_TO_5, fifo_3_to_5);
    ALTERA_AVALON_FIFO_INIT ( FIFO_3_TO_6, fifo_3_to_6);
    ALTERA_AVALON_FIFO_INIT ( FIFO_4_TO_3, fifo_4_to_3);
    ALTERA_AVALON_FIFO_INIT ( FIFO_5_TO_3, fifo_5_to_3);
    ALTERA_AVALON_FIFO_INIT ( FIFO_6_TO_3, fifo_6_to_3);
    ALTERA_AVALON_JTAG_UART_INIT ( JTAG_UART_3, jtag_uart_3);
    ALTERA_AVALON_MUTEX_INIT ( MUTEX_0, mutex_0);
    ALTERA_AVALON_MUTEX_INIT ( MUTEX_1, mutex_1);
    ALTERA_AVALON_MUTEX_INIT ( MUTEX_2, mutex_2);
    ALTERA_AVALON_MUTEX_INIT ( MUTEX_3, mutex_3);
    ALTERA_AVALON_MUTEX_INIT ( MUTEX_4, mutex_4);
    ALTERA_AVALON_MUTEX_INIT ( MUTEX_5, mutex_5);
    ALTERA_AVALON_PERFORMANCE_COUNTER_INIT ( PERFORMANCE_COUNTER_3, performance_counter_3);
}
