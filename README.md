# RTOSsseract - RTOS on MicroBlaze (Arty A7-35T)

**RTOSsseract** is an embedded RTOS project running on the MicroBlaze soft processor inside the Arty A7-35T FPGA. It features UART-based shell interaction, modular peripheral drivers, and simple multitasking — all designed to be minimal, fast, and expandable.


## Current Features 

- MicroBlaze processor with UART, Timer, and GPIO  
- RTOS-style task manager (manual context switching)  
- UART shell interface with login system  
- Shell commands: `help`, `status`, `uptime`, etc.  
- Modular C codebase (`timer.c`, `shell.c`, etc.)  
- Python-based UART terminal with logging & history  
- One-click script to load FPGA bitstream and launch terminal  

## Project Structure

```bash
RTOSsseract/
├── vitis/                # Vitis workspace (C source, .elf, etc.)
│   └── app_component/   # App source and headers
├── vivado/               # Vivado block design and constraints
├── terminal.py           # Python UART shell interface
├── launch_terminal.sh    # Script to program FPGA and launch shell
├── src/                  # HDL files and testbenches (future use)
├── docs/                 # Design notes & architecture diagrams
├── .gitignore            # Git exclusions
├── README.md             # Project documentation
└── LICENSE               # License info
```


## How to Run

### 1. Flash FPGA and Launch Terminal

From your project root:

```bash
./launch_terminal.sh
```
This will:

- Program the FPGA using `xsct`
- Load your `.elf` firmware
- Launch the UART shell interface automatically

**Note:** You must be inside the project folder, or modify paths in `launch_terminal.sh`.

---

## Prerequisites

### Software & Tools

- Xilinx Vivado & Vitis (2024.2)  
- Python 3.8+  
- USB UART driver for Arty board  

### Python Dependencies

Install them using:

```python
pip install pyserial
```

## 🚀 Future Optimizations

- [ ] Add some real tasks  
  - Offload basic hardware tasks like LED blinking or button monitoring using HDL  
  - Implement PWM control or edge detection in hardware  
  - Create custom AXI peripherals for offloaded computation (e.g., checksum, counters)  
- [ ] Interrupt feature  
- [ ] Real-time task execution  
- [ ] Utilize around 60% of FPGA’s resources  
- [ ] Add additional memory to store user logs and data  
 
 
##  References & Credits

- [Xilinx MicroBlaze Docs](https://docs.xilinx.com/)
- [FreeRTOS Documentation](https://freertos.org/)
- Python libraries: `pyserial`, `readline`

---
