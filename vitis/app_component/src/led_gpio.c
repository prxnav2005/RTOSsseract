#include "led_gpio.h"
#include "xgpio.h"
#include "xil_printf.h"

static XGpio gpio;
static u32 led_state = 0x0;


void gpio_init() {
    int status = XGpio_Initialize(&gpio, GPIO_DEVICE_ID);
    xil_printf("GPIO Init Status: %d\r\n", status);

    // Set LED channel as output (0), switch channel as input (1)
    XGpio_SetDataDirection(&gpio, LED_CHANNEL, 0x0);        // Output
    XGpio_SetDataDirection(&gpio, SWITCH_CHANNEL, 0xF);     // Input (4 bits)

    XGpio_DiscreteWrite(&gpio, LED_CHANNEL, led_state);
}

void toggle_led(u8 led_mask) {
    led_state ^= led_mask;
    XGpio_DiscreteWrite(&gpio, LED_CHANNEL, led_state);
}

u32 read_switches() {
    return XGpio_DiscreteRead(&gpio, SWITCH_CHANNEL);
}

void gpio_blink_test() {
    while (1) {
        toggle_led(0xF);  // Toggle all 4 LEDs
        for (volatile int i = 0; i < 1000000; i++);  // Crude delay
    }
}

void write_leds(u32 value) {
    led_state = value;
    XGpio_DiscreteWrite(&gpio, LED_CHANNEL, led_state);
}

void clear_leds() {
    XGpio_DiscreteWrite(&gpio, LED_CHANNEL, 0x0);
}
