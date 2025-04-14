#ifndef LED_GPIO_H
#define LED_GPIO_H

#include "xil_types.h"
#include "xparameters.h"
#include "xgpio.h"

// Add the device ID definition here
#define XPAR_XGPIO_0_DEVICE_ID 0  // Define the device ID here

#define GPIO_DEVICE_ID XPAR_XGPIO_0_DEVICE_ID
#define LED_CHANNEL 2

void gpio_init();
void toggle_led(u8 led_mask);
void write_leds(u32 value);
void clear_leds();

#endif
