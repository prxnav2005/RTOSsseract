# 2025-04-08T20:47:51.612922
import vitis

client = vitis.create_client()
client.set_workspace(path="RTOS_Final_Vitis")

platform = client.get_component(name="platform")
status = platform.build()

comp = client.get_component(name="app_component")
comp.build()

