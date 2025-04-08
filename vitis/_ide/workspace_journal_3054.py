# 2025-04-07T21:54:05.936849
import vitis

client = vitis.create_client()
client.set_workspace(path="RTOS_Final_Vitis")

platform = client.get_component(name="platform")
status = platform.build()

status = platform.build()

comp = client.get_component(name="app_component")
comp.build()

vitis.dispose()

