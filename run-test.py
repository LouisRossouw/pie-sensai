import requests
from time import sleep

beacon_addr = "http://10.0.0.154"
beacon_monitor_addr = "http://10.0.0.153"

beacon_res = requests.get(f"{beacon_addr}/temperature")
beacon_monitor_res = requests.get(f"{beacon_monitor_addr}/temperature")

print('beacon_res', beacon_res.text)
print('beacon_monitor_res', beacon_monitor_res.text)

sleep(2)

requests.get(f"{beacon_addr}/error?text=&textSize=3")
requests.get(f"{beacon_monitor_addr}/error?text=&textSize=3")
