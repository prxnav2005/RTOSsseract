#include "xil_printf.h"
#include "xparameters.h"
#include "xuartlite_l.h"
#include "login.h"
#include "led_gpio.h"
#include "timer.h"
#include "scheduler.h"
#include "shell.h"

// Global variables
u32 last_timer_val = 0;
volatile u32 uptime_seconds = 0;

// === Task 1: LED0 Blinker ===
void task1() {
    toggle_led(0x4);  // Toggle LED0
}

// === Task 2: LED1 Blinker ===
void task2() {
    toggle_led(0x8);  // Toggle LED1
}

// === Task 3: Uptime Tracker ===
void uptime_task() {
    uptime_seconds++;  // Increment uptime every second
}

// === Task 5: Shell Interface ===
extern void shell_task();

int main() {
    xil_printf("RTOSsseract: System Booting...\r\n\r\n");

    // Prompt for login
    if (!login_prompt()) {
        xil_printf("Access Denied. Locking system...\r\n");
        while (1);  // Halt system if login fails
    }

    xil_printf("RTOSsseract: Login Success! Initializing System...\r\n");

    // Message after login success
    xil_printf("type help to view all commands\r\n");

    // Initialize GPIO (LEDs)
    gpio_init();

    // Initialize Timer
    if (timer_init() != XST_SUCCESS) {
        xil_printf("Timer Init Failed. System Halted.\r\n");
        return -1;
    }

    timer_start();

    // Initialize the Scheduler
    Scheduler_Init();

    // Add tasks to the scheduler
    Scheduler_AddTask(task1,       0,   50);   // LED0 blink (every 50ms)
    Scheduler_AddTask(task2,      25,   50);   // LED1 blink (offset by 25ms)
    Scheduler_AddTask(uptime_task, 0, 1000);   // Uptime display every second
    Scheduler_AddTask(shell_task,  0,   10);   // Shell interface polling every 10ms

    last_timer_val = timer_get_value();

    // Display active tasks
    xil_printf("\r\n== Active Tasks ==\r\n");
    xil_printf("Task 1: Blinking LED0 (task1)\r\n");
    xil_printf("Task 2: Blinking LED1 (task2)\r\n");
    xil_printf("Task 3: Uptime Tracker (uptime_task)\r\n");
    xil_printf("Task 4: UART Shell Interface (shell_task)\r\n");
    xil_printf("==============================\r\n\r\n");

    xil_printf("RTOSsseract: Scheduler Running...\r\n");
    xil_printf(">>> ");

    // Main loop: Scheduler and Shell Task
    while (1) {
        Scheduler_Tick();  // Execute one scheduler time slice
        shell_task();      // Handle UART shell input/output
    }

    return 0;
}
