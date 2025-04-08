# 2025-04-06T21:55:35.573971
import vitis

client = vitis.create_client()
client.set_workspace(path="RTOS_Final_Vitis")

platform = client.get_component(name="platform")
status = platform.build()

comp = client.get_component(name="app_component")
comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../RTOS_Final/True_Wrapper.xsa")

status = platform.build()

status = platform.build()

comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../RTOS_Final/The_Real_Wrapper.xsa")

status = platform.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../RTOS_Final/PLS_GOD_SAVE_ME.xsa")

status = platform.build()

status = platform.build()

comp.build()

vitis.dispose()

