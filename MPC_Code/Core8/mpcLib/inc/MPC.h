/* DESCRIPTION: 
 * A library of all MPC functions that are visible to all Niso II cores.
 */

#ifndef MPC_H
#define MPC_H

#include "alt_types.h"
#include "system.h"
#include "altera_avalon_mutex.h"
#include "INFO.h"




//FIFOS
extern void MPC_initialize_fifos(alt_u8 CPU, alt_u8 ALMOST_FULL, alt_u8 ALMOST_EMPTY);

extern void MPC_send_to_CPU(alt_u8 CPU_SENDER, alt_u8 CPU_RECEIVER , int DATA);

extern int MPC_receive_from_CPU(alt_u8 CPU_SENDER, alt_u8 CPU_RECEIVER);

extern int MPC_FIFO_level(alt_u8 CPU_SENDER, alt_u8 CPU_RECEIVER);

extern int MPC_FIFO_status(alt_u8 CPU_SENDER, alt_u8 CPU_RECEIVER, alt_u8 mask);

//RED LEDs
extern void MPC_write_single_red_LED(alt_u8 LEDNUMBER);

extern void MPC_write_mask_red_LED(alt_u32 MASK);

extern void MPC_reset_red_leds();

//GREEN LEDs
extern void MPC_write_single_green_LED(alt_u8 LEDNUMBER);

extern void MPC_write_mask_green_LED(alt_u8 MASK);

extern void MPC_reset_green_leds();

//SWITCHES
extern int MPC_read_single_switch(alt_u8 SWITCHNUMBER);

extern int MPC_read_mask_switches();

//MUTEX
extern int alt_trylock(alt_mutex_dev* dev, alt_u32 value );

extern int MPC_mutex_is_mine(alt_mutex_dev* MUTEX);

extern int MPC_mutex_owner(alt_mutex_dev* MUTEX);

extern int MPC_mutex_first_lock(alt_mutex_dev* MUTEX);

extern void MPC_mutex_lock(alt_mutex_dev* MUTEX);

extern void MPC_mutex_unlock(alt_mutex_dev* MUTEX);

extern alt_mutex_dev* MPC_mutex_open(const char* MUTEX);

extern MPC_MUTEXLIST MPC_mutex_open_all();

//SHARED MEMORY
extern void MPC_shared_memory_write(alt_u32 DATA, alt_u32 ADDRESS);

extern alt_u32 MPC_shared_memory_read(alt_u32 ADDRESS);

//TIMERS
extern void MPC_sys_timer_reset(alt_u32 CPU_ID);

extern alt_u32 MPC_sys_timestamp(alt_u32 CPU_ID);

extern void MPC_sys_timer_period(alt_u32 CPU_ID, alt_u32 NEW_PERIOD);

extern void MPC_local_timestamp_reset(alt_u32 CPU_ID);

extern alt_u32 MPC_local_timestamp(alt_u32 CPU_ID);

extern void MPC_shared_timestamp_0_reset();

extern alt_u32 MPC_shared_timestamp_0();

extern void MPC_shared_timestamp_1_reset();

extern alt_u32 MPC_shared_timestamp_1();

#endif /* __MPC_H__ */
