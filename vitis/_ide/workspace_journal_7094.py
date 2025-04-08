# 2025-04-05T16:43:12.294669
import vitis

client = vitis.create_client()
client.set_workspace(path="RTOS_Final_Vitis")

platform = client.get_component(name="platform")
status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../RTOS_Final/Real_WrapperXSA.xsa")

status = platform.build()

status = platform.build()

comp = client.get_component(name="app_component")
comp.build()

vitis.dispose()

