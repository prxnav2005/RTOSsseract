# RTOSsseract - RTOS on MicroBlaze (Arty A7-35T)

This project aims to build and run an **RTOS on the MicroBlaze soft processor** inside the **Arty A7-35T FPGA**. The RTOS will support **preemptive multitasking, interrupt-driven peripherals, and task management**.

## Project Structure  

```
RTOSsseract/
├── src/                  # HDL (Verilog/VHDL), testbenches, and maybe system design notes
│   ├── top_module.v
│   ├── timer_tb.v
│   └── ...
├── vitis/                # Vitis workspace
│   └── RTOS_Final_App/
│       └── src/          # All your RTOS C code + headers
├── vivado/               # Vivado block design + constraint files
│   └── <vivado project files>
├── docs/                 # Any diagrams or high-level notes
├── README.md
└── .gitignore

```

## Features  

- **Preemptive multitasking** with efficient task switching  
- **Interrupt-driven UART shell** for real-time debugging  
- **Peripheral interfacing** with GPIO, UART, and timer support  
- **Custom AXI peripherals** for optimized performance  
- **Memory management & inter-task communication**  
- **Modular design** for future enhancements  

## Task Breakdown  

### **Phase 1: Setup & Understanding**  
- [x] Study **MicroBlaze architecture**  
- [x] Learn **RTOS fundamentals**  
- [x] Set up **Vivado & Vitis** development environment  

### **Phase 2: RTOS Implementation**  
- [ ] Configure **MicroBlaze soft processor** in Vivado  
- [ ] Generate **Bitstream & Export to Vitis**  
- [ ] Port **FreeRTOS (or similar) to MicroBlaze**  
- [ ] Implement **preemptive multitasking & task scheduling**  
- [ ] Set up **heap management & memory allocation**  
- [ ] Test with a **basic LED task switcher**  

### **Phase 3: Peripheral Interfacing**  
- [ ] Implement **interrupt-driven UART** for CLI interaction  
- [ ] Add **GPIO and Timer** integration  
- [ ] Implement **real-time task execution & interrupt handling**  

### **Phase 4: Optimization & FPGA Resource Utilization**  
- [ ] Monitor FPGA resource usage (**target: ≥60% utilization**)  
- [ ] Optimize **task scheduling & memory management**  
- [ ] Explore **custom AXI-based hardware accelerators**  
- [ ] Final testing & documentation  

## Prerequisites  

### **Software & Tools**  
- **Xilinx Vivado & Vitis**   
- **Python 3.8+** 
- **Serial terminal (PuTTY, minicom, or similar)**  

### **Python Dependencies**  
Install required Python packages:  
```bash
pip install -r requirements.txt
```

## Resources Used  

- **MicroBlaze Processor Reference Guide** ([Xilinx Docs](https://docs.amd.com/r/en-US/ug984-vivado-microblaze-ref/MicroBlaze-Architecture))  
- **FreeRTOS Documentation** ([Official Site](https://www.freertos.org/Documentation/01-FreeRTOS-quick-start/01-Beginners-guide/01-RTOS-fundamentals))  

## Future Enhancements  

- Implement **custom drivers**  
- Add **real-time performance profiling**  
- Secure bootloader for **verified firmware execution**  
