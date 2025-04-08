#include "xil_printf.h"
#include "xparameters.h"
#include "xuartlite_l.h"
#include "login.h"
#include "led_gpio.h"
#include "timer.h"
#include "scheduler.h"
#include "shell.h"

#define TICK_INTERVAL 10000000  // Adjust based on timer frequency

u32 last_timer_val = 0;
u32 uptime_seconds = 0;

// === Task 1: LED0 Blinker ===
void task1() {
    toggle_led(0x1);
}

// === Task 2: LED1 Blinker ===
void task2() {
    toggle_led(0x2);
}

// === Task 3: Uptime Display ===
void uptime_task() {
    uptime_seconds++;
    xil_printf("Uptime: %d seconds\r\n", uptime_seconds);
}

// === Task 4: Monitor Switches ===
void button_task() {
    static u32 prev_state = 0;
    u32 state = read_switches();

    for (int i = 0; i < 4; i++) {
        u32 mask = 1 << i;
        if ((state & mask) && !(prev_state & mask)) {
            xil_printf("Switch %d toggled ON!\r\n", i);
            toggle_led(mask << 2);  // SW0→LED2, SW1→LED3, etc.
        }
    }

    prev_state = state;
}

// === Main ===
int main() {
    xil_printf("RTOSsseract: System Booting...\r\n\r\n");

    if (!login_prompt()) {
        xil_printf("Access Denied. Locking system...\r\n");
        while (1);  // No mercy.
    }

    xil_printf("RTOSsseract: Login Success! Initializing System...\r\n");

    gpio_init();

    if (timer_init() != XST_SUCCESS) {
        xil_printf("Timer Init Failed. System Halted.\r\n");
        return -1;
    }

    timer_start();
    Scheduler_Init();

    Scheduler_AddTask(task1, 0, 50);
    Scheduler_AddTask(task2, 25, 50);
    Scheduler_AddTask(uptime_task, 0, 1000);
    Scheduler_AddTask(button_task, 0, 100);

    last_timer_val = timer_get_value();

    xil_printf("\r\n== Active Tasks ==\r\n");
    xil_printf("Task 1: Blinking LED0 (led0)\r\n");
    xil_printf("Task 2: Blinking LED1 (led1)\r\n");
    xil_printf("Task 3: Uptime Tracker (uptime)\r\n");
    xil_printf("Task 4: Button Monitor (buttons)\r\n");
    xil_printf("====================\r\n\r\n");

    xil_printf("RTOSsseract: Scheduler Running...\r\n\r\n");

    // Start the custom shell
    shell_run();  

    return 0;
}
