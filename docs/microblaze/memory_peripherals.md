# MicroBlaze Memory and Peripherals

## Introduction
MicroBlaze interacts with different types of memory and peripherals through AXI and other interfaces. Proper memory configuration ensures efficient execution, while peripherals enable communication and data handling.

## 1. Memory Options

### **1.1 Local Memory (LMB)**
- Provides **low-latency** memory for instructions and data.
- Ideal for small, high-speed applications.
- Connected through the **Local Memory Bus (LMB)**.

### **1.2 Block RAM (BRAM)**
- Uses FPGA’s internal **Block RAM** for fast storage.
- Can be accessed via **AXI BRAM Controller**.
- Often used for **boot code** and critical data storage.

### **1.3 External DDR Memory**
- Required for larger applications like RTOS and networking.
- Accessed via **AXI Interconnect** and DDR Memory Controller.
- Supports caching for improved performance.

## 2. Peripheral Interfaces

### **2.1 AXI Interconnect**
- Primary communication interface for MicroBlaze.
- Connects the processor to **memory, UART, GPIO, and other peripherals**.

### **2.2 General Purpose I/O (GPIO)**
- Used for **LEDs, buttons, switches**, and custom external connections.
- Configurable as **input or output**.

### **2.3 UART (Universal Asynchronous Receiver-Transmitter)**
- Provides **serial communication** for debugging and external device communication.
- Typically used for **console output and user interaction**.

### **2.4 SPI (Serial Peripheral Interface) & I2C**
- SPI: Used for high-speed communication with flash memory, sensors, etc.
- I2C: Used for low-speed peripheral communication.

### **2.5 Timer & Interrupts**
- **Timer modules** enable time-based operations.
- **Interrupt Controller (XIntc)** handles interrupts from peripherals.

### **2.6 Ethernet MAC**
- Enables **network connectivity** for advanced applications.
- Can be used for remote debugging, communication, or real-time monitoring.

## Conclusion
Memory and peripheral selection depend on application needs. 
