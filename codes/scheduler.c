#include "scheduler.h"
#include "xil_printf.h"

static Task taskList[MAX_TASKS];
static int taskCount = 0;

void Scheduler_Init() {
    for(int i = 0; i < MAX_TASKS; i++) {
        taskList[i].function = 0;
        taskList[i].delay = 0;
        taskList[i].period = 0;
        taskList[i].active = 0;
    }
    taskCount = 0;
}

int Scheduler_AddTask(TaskFunction func, int delay, int period) {
    if(taskCount < MAX_TASKS) {
        taskList[taskCount].function = func;
        taskList[taskCount].delay = delay;
        taskList[taskCount].period = period;
        taskList[taskCount].active = 1;
        return taskCount++;
    }
    return -1;
}

void Scheduler_Tick() {
    for(int i = 0; i < taskCount; i++) {
        if(!taskList[i].active) continue;

        if(taskList[i].delay == 0) {
            taskList[i].function();
            taskList[i].delay = taskList[i].period;
        } else {
            taskList[i].delay--;
        }
    }
}

