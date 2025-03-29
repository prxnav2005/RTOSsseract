# RTOS Architecture

## Key Components of an RTOS
An RTOS consists of several fundamental components that ensure deterministic and efficient task execution.

### 1. **Kernel**
The **core** of the RTOS, responsible for:
- **Task Scheduling**: Determines which task runs and when.
- **Interrupt Handling**: Manages hardware/software interrupts.
- **Resource Management**: Allocates CPU time, memory, and peripherals.

### 2. **Task Management**
- **Tasks (Threads/Processes)**: Independent units of execution.
- **Task States**:
  - **Running**: Actively executing.
  - **Ready**: Waiting for CPU time.
  - **Blocked**: Waiting for an event (e.g., I/O, semaphore).
  - **Suspended**: Paused by the system.

### 3. **Scheduler**
Decides which task runs based on:
- **Preemptive Scheduling**: Higher-priority tasks can interrupt lower-priority ones.
- **Round-Robin Scheduling**: Tasks run in a time-sliced manner.
- **Rate-Monotonic Scheduling (RMS)**: Prioritizes tasks with shorter execution periods.

### 4. **Inter-Task Communication (IPC)**
Mechanisms for tasks to exchange data:
- **Queues**: FIFO-based communication between tasks.
- **Semaphores**: Prevents race conditions in shared resources.
- **Mutexes**: Ensures exclusive resource access.
- **Event Flags**: Signals events between tasks.

### 5. **Memory Management**
RTOS provides efficient memory handling through:
- **Stack and Heap Management**: Each task gets its stack space.
- **Dynamic Memory Allocation**: Some RTOSes (e.g., FreeRTOS) support malloc-like functions.
- **Memory Protection**: Prevents unauthorized memory access (if MMU is available).

### 6. **Interrupt Service Routine (ISR)**
Handles external events (e.g., timers, I/O):
- Must be **fast and minimal**.
- Can signal tasks via **semaphores or event flags**.

### 7. **Timers**
Used for:
- **Task Delays**: Suspend a task for a fixed time.
- **Periodic Tasks**: Scheduling recurring operations.
- **Timeouts**: Ensuring operations do not hang indefinitely.

### 8. **Device Drivers**
- Provide interfaces to peripherals (UART, SPI, I2C, Ethernet).
- Abstract hardware complexity from tasks.

---

## RTOS on FPGA (MicroBlaze)
An RTOS running on MicroBlaze must efficiently utilize FPGA resources:
✅ **Hardware-accelerated interrupts** for real-time responses.  
✅ **Efficient task scheduling** to handle multiple I/O operations.  
✅ **Custom peripheral drivers** for FPGA-based communication.  

