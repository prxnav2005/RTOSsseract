#include "xuartlite_l.h"
#include "xil_printf.h"
#include "xparameters.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shell.h"
#include "timer.h"
#include "gpio.h"

#define UART_BASEADDR      XPAR_XUARTLITE_0_BASEADDR
#define SHELL_CMD_BUF_LEN  32

extern u32 uptime_seconds;
extern int Scheduler_AddTask(void (*taskFunc)(void), u32 delay, u32 period);

// Task declarations (from main.c)
extern void task1();
extern void task2();
extern void uptime_task();

// === Shell Command Buffer ===
static char shell_cmd_buf[SHELL_CMD_BUF_LEN];
static int shell_cmd_index = 0;

// === Command Helpers ===
static void shell_help() {
    xil_printf("Available commands:\r\n");
    xil_printf("  help           - Show this help\r\n");
    xil_printf("  uptime         - Show system uptime\r\n");
    xil_printf("  status         - Show RTOS status\r\n");
    xil_printf("  led on <n>     - Turn ON LED n (0 or 1)\r\n");
    xil_printf("  led off <n>    - Turn OFF LED n (0 or 1)\r\n");
    xil_printf("  reboot         - Soft reset (mock)\r\n");
    xil_printf("  task add <n>   - Add task n (1–3)\r\n");
}

static void shell_status() {
    xil_printf("RTOS running. Tasks scheduled.\r\n");
    xil_printf("Timer tick interval: %d\r\n", 10000000);
}

static void shell_led_cmd(char* arg1, char* arg2) {
    if (!arg1 || !arg2) {
        xil_printf("Usage: led <on|off> <0|1>\r\n");
        return;
    }

    int led_id = atoi(arg2);
    u32 mask = (led_id == 0) ? 0x1 : 0x2;

    if (strcmp(arg1, "on") == 0) {
        write_leds(mask);
        xil_printf("LED %d turned ON\r\n", led_id);
    } else if (strcmp(arg1, "off") == 0) {
        clear_leds(mask);
        xil_printf("LED %d turned OFF\r\n", led_id);
    } else {
        xil_printf("Unknown LED command\r\n");
    }
}

static void shell_uptime(u32 seconds) {
    xil_printf("Uptime: %u seconds\r\n", seconds);
}

static void shell_task_cmd(char* action, char* arg) {
    if (!action || !arg || strcmp(action, "add") != 0) {
        xil_printf("Usage: task add <1-3>\r\n");
        return;
    }

    int id = atoi(arg);
    void (*task_fn)(void) = NULL;

    switch (id) {
        case 1: task_fn = task1; break;
        case 2: task_fn = task2; break;
        case 3: task_fn = uptime_task; break;
        default:
            xil_printf("Invalid task ID: %d\r\n", id);
            return;
    }

    u32 delay = 0;
    u32 period = (id == 1 || id == 2) ? 50 : (id == 3 ? 1000 : 100);
    Scheduler_AddTask(task_fn, delay, period);
    xil_printf("Task %d added\r\n", id);
}

// === Command Processor ===
void shell_process_command(char *cmd_buf) {
    char *cmd = strtok(cmd_buf, " ");
    char *arg1 = strtok(NULL, " ");
    char *arg2 = strtok(NULL, " ");

    if (!cmd) return;

    if (strcmp(cmd, "help") == 0) {
        shell_help();
    } else if (strcmp(cmd, "uptime") == 0) {
        shell_uptime(uptime_seconds);
    } else if (strcmp(cmd, "status") == 0) {
        shell_status();
    } else if (strcmp(cmd, "led") == 0) {
        shell_led_cmd(arg1, arg2);
    } else if (strcmp(cmd, "task") == 0) {
        shell_task_cmd(arg1, arg2);
    } else if (strcmp(cmd, "reboot") == 0) {
        xil_printf("Rebooting...\r\n");
        // Optional soft reset logic
    } else {
        xil_printf("Unknown command: %s\r\n", cmd);
    }
}

// === Non-blocking Shell Task ===
void shell_task() {
    if (!XUartLite_IsReceiveEmpty(UART_BASEADDR)) {
        char c = XUartLite_RecvByte(UART_BASEADDR);
        XUartLite_SendByte(UART_BASEADDR, c); // Echo

        if (c == '\r' || c == '\n') {
            shell_cmd_buf[shell_cmd_index] = '\0';
            xil_printf("\r\n");
            shell_process_command(shell_cmd_buf);
            shell_cmd_index = 0;  // Reset for next command
            xil_printf(">>> ");
        } else if (shell_cmd_index < SHELL_CMD_BUF_LEN - 1) {
            shell_cmd_buf[shell_cmd_index++] = c;
        }
    }
}
