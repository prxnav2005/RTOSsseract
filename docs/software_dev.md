# MicroBlaze Software Development

## 1. Development Environment

### **1.1 Xilinx Vitis**
- Vitis is the primary IDE for writing, compiling, and debugging MicroBlaze software.
- Provides built-in drivers and BSP (Board Support Package) for peripherals.

### **1.2 Vivado**
- Used for hardware design and generating the MicroBlaze bitstream.
- Exports hardware design to Vitis for software development.

## 2. Programming Languages

- **C/C++**: Primary language for MicroBlaze applications.
- **Assembly**: Used for low-level optimizations but rarely needed.

## 3. Software Components

### **3.1 Board Support Package (BSP)**
- Includes **drivers, libraries, and startup code** for MicroBlaze.
- Auto-generated when creating a new Vitis project.

### **3.2 Linker Script**
- Defines memory regions and allocation for the program.
- Ensures correct placement of **code, stack, and heap**.

### **3.3 Standalone vs. RTOS**
- **Standalone (Bare-metal)**: Direct control over hardware, no OS overhead.
- **RTOS (e.g., FreeRTOS)**: Provides task scheduling, synchronization, and other OS features.

## 4. Debugging and Testing

### **4.1 UART Debugging**
- Print debug messages via serial terminal (e.g., PuTTY, Tera Term).

### **4.2 JTAG Debugging**
- Set breakpoints, step through code, and inspect memory.

### **4.3 Profiling and Optimization**
- Use **Vitis Analyzer** to profile execution and optimize performance.


