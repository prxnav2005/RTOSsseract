#ifndef TIMER_H
#define TIMER_H

#include "xtmrctr.h"

#define TIMER_DEVICE_ID 0     // Set to 0 unless you have multiple timers
#define TIMER_COUNTER_0 0     // Timer Counter 0

int timer_init();
void timer_start();
void timer_stop();
u32 timer_get_value();

#endif
