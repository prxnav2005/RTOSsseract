#include "xil_printf.h"
#include "xuartlite.h"
#include "xparameters.h"
#include <string.h>
#include "xuartlite_l.h"

#define MAX_INPUT_LEN  20
#define MAX_ATTEMPTS   3
#define UART_BASEADDR  XPAR_XUARTLITE_0_BASEADDR

static const char* correct_username = "admin";
static const char* correct_password = "1234";

void uart_get_string(char *buffer, int max_len) {
    int i = 0;
    char c;

    while (i < max_len - 1) {
        // Wait for character
        if (!XUartLite_IsReceiveEmpty(UART_BASEADDR)) {
            c = XUartLite_RecvByte(UART_BASEADDR);

            // Echo back
            XUartLite_SendByte(UART_BASEADDR, c);

            if (c == '\r' || c == '\n') break;

            buffer[i++] = c;
        }
    }

    buffer[i] = '\0';
    xil_printf("\r\n");  // Move to next line
}

int login_prompt() {
    char username[MAX_INPUT_LEN];
    char password[MAX_INPUT_LEN];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        xil_printf("\r\n=== RTOSsseract Login ===\r\n");
        xil_printf("Username: ");
        uart_get_string(username, MAX_INPUT_LEN);

        xil_printf("Password: ");
        uart_get_string(password, MAX_INPUT_LEN);

        if (strcmp(username, correct_username) == 0 &&
            strcmp(password, correct_password) == 0) {
            xil_printf("\r\n Login successful!\r\n");
            return 1;
        } else {
            xil_printf("Invalid credentials. Try again.\r\n");
            attempts++;
        }
    }

    xil_printf("\r\nToo many failed attempts. System lock.\r\n");
    return 0;
}
