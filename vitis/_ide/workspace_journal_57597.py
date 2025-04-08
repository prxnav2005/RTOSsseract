# 2025-04-04T23:29:31.288898
import vitis

client = vitis.create_client()
client.set_workspace(path="RTOS_Final_Vitis")

client.delete_component(name="RTOS_App")

client.delete_component(name="RTOS_Platform")

platform = client.create_platform_component(name = "RTOS_Platform",hw_design = "$COMPONENT_LOCATION/../../RTOS_Final/RTOS_Block_wrapper1.xsa",os = "standalone",cpu = "microblaze_0",domain_name = "standalone_microblaze_0")

comp = client.create_app_component(name="app_component",platform = "$COMPONENT_LOCATION/../RTOS_Platform/export/RTOS_Platform/RTOS_Platform.xpfm",domain = "standalone_microblaze_0")

client.delete_component(name="RTOS_Platform")

client.delete_component(name="app_component")

platform = client.create_platform_component(name = "platform",hw_design = "$COMPONENT_LOCATION/../../RTOS_Final/RTOS_Block_wrapper2.xsa",os = "standalone",cpu = "microblaze_0",domain_name = "standalone_microblaze_0")

comp = client.create_app_component(name="app_component",platform = "$COMPONENT_LOCATION/../platform/export/platform/platform.xpfm",domain = "standalone_microblaze_0")

platform = client.get_component(name="platform")
status = platform.build()

status = platform.build()

comp = client.get_component(name="app_component")
comp.build()

vitis.dispose()

