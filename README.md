# RTOSsseract - RTOS on MicroBlaze (Arty A7-35T)

**RTOSsseract** is an embedded RTOS project running on the MicroBlaze soft processor inside the Arty A7-35T FPGA. It features UART-based shell interaction, modular peripheral drivers, and simple multitasking — all designed to be minimal, fast, and expandable.

---

## Features

- **MicroBlaze Processor**: Configured with UART, Timer, and GPIO peripherals.
- **RTOS-Style Task Manager**: Implements manual context switching for multitasking.
- **UART Shell Interface**: Includes a login system and shell commands like `help`, `status`, and `uptime`.
- **Modular Codebase**: Organized into separate modules for peripherals (`timer.c`, `shell.c`, etc.).

---

## Project Structure

```bash
RTOSsseract/
├── c_src/                # C source files
├── header-files/         # Header files for peripherals and drivers
├── hdl_src/              # HDL source files(future implementation)
├── docs/                 # Documentation and design notes
├── .gitignore            # Git exclusions
├── README.md             # Project documentation
└── LICENSE               # License information
```

---

## Software Used

- **Xilinx Vivado & Vitis** (2024.2 or later)
- **Minicom**: For UART communication with the shell interface
- **Linux Environment**: Development and testing

---

## Future Enhancements

- [ ] Add real-time tasks:
- [ ] Enable interrupt-driven task execution.
- [ ] Optimize resource utilization to use ~60% of the FPGA's capacity.
- [ ] Add external memory support for storing user logs and data.
- [ ] Improve the shell interface with more commands and features.

---

## References & Credits

- [Xilinx MicroBlaze Documentation](https://docs.xilinx.com/)
- [FreeRTOS Documentation](https://freertos.org/)
- Tools: Minicom, Vivado, Vitis

---