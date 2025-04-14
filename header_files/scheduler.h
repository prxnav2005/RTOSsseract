#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef void(*TaskFunction)();
typedef struct {
    TaskFunction function;
    int delay;
    int period;
    int active;
} Task;


#define MAX_TASKS 4

void Scheduler_Init();
int Scheduler_AddTask(TaskFunction func, int delay, int period);
void Scheduler_Tick();
int Scheduler_GetTaskDelay(int index);

#endif