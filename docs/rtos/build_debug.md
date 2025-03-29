# Building and Debugging the RTOS on MicroBlaze

## 1. Setting Up the Environment

### Required Tools:
- **Vivado**: For FPGA design and MicroBlaze soft core setup.
- **Vitis**: For software development, RTOS integration, and debugging.
- **FreeRTOS/Xilinx Standalone BSP**: The RTOS itself.

### Project Configuration:
1. **Create a MicroBlaze Processor in Vivado**  
   - Define memory, peripherals, and clock settings.
   - Enable necessary AXI interconnects.

2. **Export Hardware to Vitis**  
   - Generate the `.xsa` hardware description.
   - Open Vitis and create an application project.

3. **Include the RTOS**  
   - Add FreeRTOS as a dependency in the BSP settings.
   - Configure kernel options (stack size, heap, scheduler type).

---

## 2. Building the RTOS Application

### Compilation Steps:
- Set up **compiler flags** (`-O2` for optimization, `-g` for debugging).
- Define **heap/stack sizes** in the linker script.
- Compile with **task-aware debugging enabled**.

### Common Build Issues:
| Issue | Cause | Solution |
|-------|-------|----------|
| `heap memory allocation failed` | Insufficient heap | Increase heap size in FreeRTOSConfig.h |
| `undefined reference to vTaskStartScheduler()` | Missing RTOS files | Ensure FreeRTOS sources are included |
| `task crashes randomly` | Stack overflow | Enable stack overflow checking |

---

## 3. Debugging the RTOS

### Enabling Debugging Features:
- **GDB Debugging**: Run in Vitis with breakpoints.
- **UART Logs**: Print debug messages via UART.
- **Task Aware Debugging**: Use the FreeRTOS task list to inspect running tasks.

### Debugging Techniques:
- **Check Task Stack Usage**: Monitor stack overflow.
- **Use Event Flags**: Identify synchronization issues.
- **Profile CPU Load**: Optimize task execution times.

---

## 4. Testing the RTOS
- Run a **basic task scheduler test** (blinking an LED).
- Check **context switching** behavior using UART debug logs.
- Validate **peripheral interactions** (GPIO, UART, timers).

---

## Conclusion
Building and debugging an RTOS on MicroBlaze requires **proper environment setup, memory management, and debugging strategies**. Using Vitis debugging tools and RTOS-specific logs will help ensure a smooth implementation.

