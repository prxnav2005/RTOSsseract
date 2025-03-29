# RTOS Task Scheduling

## What is Task Scheduling?
Task scheduling is the process of managing multiple tasks in an RTOS to ensure they execute efficiently and meet timing constraints.

## Types of Task Scheduling

### 1. **Preemptive Scheduling**
- The highest-priority **ready** task always gets CPU time.
- Lower-priority tasks get interrupted if a higher-priority task becomes ready.
- Ensures **real-time responsiveness**.
- Example: FreeRTOS uses **priority-based preemptive scheduling**.

### 2. **Cooperative Scheduling**
- Tasks voluntarily **yield** control of the CPU.
- No forced preemption.
- Easier to implement but **less responsive** to real-time constraints.

### 3. **Round-Robin Scheduling**
- Each task gets **equal CPU time** in a cyclic order.
- Useful when tasks have **similar priority**.
- Typically combined with **time slicing** (e.g., each task runs for 10ms before switching).

### 4. **Rate-Monotonic Scheduling (RMS)**
- A **static priority algorithm** for periodic tasks.
- Shorter period tasks get **higher priority**.
- **Guaranteed to be optimal** for fixed-priority scheduling.

### 5. **Earliest Deadline First (EDF)**
- Dynamic scheduling where tasks with **earliest deadlines** run first.
- More CPU-efficient than RMS but harder to implement.

---

## Task States in an RTOS
Tasks transition between different states:

| **State**    | **Description** |
|-------------|----------------|
| **Running**  | Task is actively executing. |
| **Ready**    | Task is ready to execute but waiting for CPU. |
| **Blocked**  | Task is waiting for an event (e.g., semaphore, I/O). |
| **Suspended** | Task is paused by the system or user. |

---

## Context Switching
When switching tasks, the RTOS:
1. Saves the **current task's context** (registers, stack, program counter).
2. Loads the **next task's context**.
3. Resumes execution.

Context switching adds **overhead**, so an RTOS minimizes its frequency.

---

## RTOS on FPGA (MicroBlaze)
- **Hardware Timer Interrupts** trigger task switching.
- **Efficient context switching** ensures real-time performance.
- **Custom peripheral drivers** can be scheduled like tasks.


