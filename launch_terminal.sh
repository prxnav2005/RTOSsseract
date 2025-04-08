#!/bin/bash

echo "[INFO] Programming FPGA and running your RTOS..."

# Vitis command to flash the board and run the app
xsct << EOF
connect
targets -set -filter {name =~ "MicroBlaze*"}
loadhw /home/prawns/RTOS_Final/PLS_GOD_SAVE_ME.xsa
dow /home/prawns/RTOS_Final_Vitis/app_component/build/app_component.elf
run
exit
EOF

# Wait a moment to avoid cutting off boot messages
sleep 1

echo "[INFO] Launching RTOSsseract Terminal..."
python3 /home/prawns/RTOSsseract/terminal.py