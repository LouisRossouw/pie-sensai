(Work in progress)

# 🥧 Pie Sensai
### Pie Sensai is a collection of .. *beacons .. for a lack of a better word.

- These little beacons sit in different parts of the house, connect to the local network via wifi and expose an API for other devices to retrieve the environments temperature and humidity.
- Unintentionally ~ intended to integrate into [Home-Pie](https://github.com/LouisRossouw/home-pie-desktop) and [API](https://github.com/LouisRossouw/home-pie-server), ie; i wasn't planning on building this, but here it is 😆, It will display data in a graph and occasionally send data to the beacon with the oled monitor.
- [Mr-ping-ping](https://github.com/LouisRossouw/mr-ping-ping) is being used to fetch and record data from these beacons.

## 🍦 Parts

- Esp32 c3 super mini
- 3 to 4 LEDs for cool incominig / outgoing light effects.
- 3 resistors
- 3D printed frame
- Oled display - BDD 12C 1.3in, 128X64
- DHT11 temperature/humidity sensor

## Other;

- Use arduinio_cli to compile and upload: `make sensai-beacon`

Reminder for self, all of my esp32 c3 boards automatically reset after upload except for one board, 
this specific board requires me to first flash it (hold down reset + boot for a few seconds, and let go of reset first before boot), then compile and upload, and finally push reset for it to run the new firmware.


![pies](https://github.com/user-attachments/assets/d39e6d7b-e0d5-4c31-91fe-12335591b47c)




