#ifndef TIMER_H
#define TIMER_H

#include "xtmrctr.h"
#include "xparameters.h"
#include "xil_types.h"

// Timer config
#define TIMER_DEVICE_ID         0
#define TIMER_COUNTER_0         0
#define TICK_INTERVAL           100000000  // Adjust based on desired tick (1Hz if 100MHz clk)

// Interrupt config
#define INTC_DEVICE_ID          XPAR_MICROBLAZE_0_AXI_INTC_DEVICE_ID
#define TIMER_INT_ID            0  // Adjust this based on how it's wired in Vivado

int timer_init();
void timer_start();
void timer_stop();
u32 timer_get_value();

#endif
