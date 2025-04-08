# 2025-04-04T20:45:57.970113
import vitis

client = vitis.create_client()
client.set_workspace(path="RTOS_Final_Vitis")

platform = client.create_platform_component(name = "RTOS_Platform",hw_design = "$COMPONENT_LOCATION/../../RTOS_Final/RTOS_Block_wrapper.xsa",os = "standalone",cpu = "microblaze_0",domain_name = "standalone_microblaze_0")

comp = client.create_app_component(name="RTOS_App",platform = "$COMPONENT_LOCATION/../RTOS_Platform/export/RTOS_Platform/RTOS_Platform.xpfm",domain = "standalone_microblaze_0")

platform = client.get_component(name="RTOS_Platform")
status = platform.build()

status = platform.build()

status = platform.build()

comp = client.get_component(name="RTOS_App")
comp.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.build()

status = platform.build()

comp.build()

vitis.dispose()

