#ifndef LED_GPIO_H
#define LED_GPIO_H

#include "xil_types.h"
#include "xparameters.h"
#include "xgpio.h"

#define GPIO_DEVICE_ID 0
#define  SWITCH_CHANNEL   1
#define LED_CHANNEL 2

void gpio_init();
void gpio_blink_test();
void toggle_led(u8 led_mask);
u32 read_switches();
void write_leds(u32 value);
void clear_leds();

#endif
