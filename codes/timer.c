#include "timer.h"
#include "xparameters.h"
#include "xil_printf.h"

static XTmrCtr TimerInstance;

int timer_init() {
    int status = XTmrCtr_Initialize(&TimerInstance, TIMER_DEVICE_ID);
    if (status != XST_SUCCESS) {
        xil_printf("Timer init failed: %d\r\n", status);
        return XST_FAILURE;
    }

    // Set reset value (start counting down from here)
    XTmrCtr_SetResetValue(&TimerInstance, TIMER_COUNTER_0, 0xFFFFFFFF);  // Max 32-bit

    XTmrCtr_SetOptions(&TimerInstance, TIMER_COUNTER_0,
                       XTC_AUTO_RELOAD_OPTION | XTC_DOWN_COUNT_OPTION);

    xil_printf("Timer initialized successfully\r\n");
    return XST_SUCCESS;
}



void timer_start() {
    XTmrCtr_Start(&TimerInstance, TIMER_COUNTER_0);
}

void timer_stop() {
    XTmrCtr_Stop(&TimerInstance, TIMER_COUNTER_0);
}

u32 timer_get_value() {
    return XTmrCtr_GetValue(&TimerInstance, TIMER_COUNTER_0);
}
