#include "led_gpio.h"
#include "xgpio.h"
#include "xil_printf.h"
#include "xparameters.h"

static XGpio gpio;
static u32 led_state = 0x0;

// Initialize GPIO
void gpio_init() {
    int status = XGpio_Initialize(&gpio, GPIO_DEVICE_ID);
    xil_printf("GPIO Init Status: %d\r\n", status);

    // Set LED channel as output (0)
    XGpio_SetDataDirection(&gpio, LED_CHANNEL, 0x0);  // Output

    XGpio_DiscreteWrite(&gpio, LED_CHANNEL, led_state);
}

// Toggle LED state based on the mask
void toggle_led(u8 led_mask) {
    led_state ^= led_mask;
    XGpio_DiscreteWrite(&gpio, LED_CHANNEL, led_state);
}

// Set LED state to a given value
void write_leds(u32 value) {
    led_state = value;
    XGpio_DiscreteWrite(&gpio, LED_CHANNEL, led_state);
}

// Clear all LEDs (set them to 0)
void clear_leds() {
    XGpio_DiscreteWrite(&gpio, LED_CHANNEL, 0x0);
}
