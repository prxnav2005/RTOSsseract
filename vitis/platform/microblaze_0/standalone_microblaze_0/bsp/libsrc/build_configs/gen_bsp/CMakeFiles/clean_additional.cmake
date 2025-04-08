# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/prawns/RTOS_Final_Vitis/platform/microblaze_0/standalone_microblaze_0/bsp/include/sleep.h"
  "/home/prawns/RTOS_Final_Vitis/platform/microblaze_0/standalone_microblaze_0/bsp/include/xiltimer.h"
  "/home/prawns/RTOS_Final_Vitis/platform/microblaze_0/standalone_microblaze_0/bsp/include/xtimer_config.h"
  "/home/prawns/RTOS_Final_Vitis/platform/microblaze_0/standalone_microblaze_0/bsp/lib/libxiltimer.a"
  )
endif()
