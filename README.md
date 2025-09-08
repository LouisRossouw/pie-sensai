(Work in progress)

# 🥧 Pie Sensai
### Currently Pie Sensai is a collection of .. *beacons .. for a lack of a better word.

- These little beacons sit in different parts of the house, connect to the local network via wifi and expose an API for other devices/apps to retrieve the environments temperature and humidity. OR other devices send messages to the beacons oled display.
- Unintentionally ~ intended to integrate into [Home-Pie](https://github.com/LouisRossouw/home-pie-desktop) and [API](https://github.com/LouisRossouw/home-pie-server), ie; i wasn't planning on building this, but here it is 😆, It will display data in a graph and occasionally send data to the beacon with the oled monitor.
- [Mr-ping-ping](https://github.com/LouisRossouw/mr-ping-ping) is being used to fetch and record data from these beacons.

# Setup

## 🍦 Parts
- Esp32 c3 super mini
- 3 to resistors
- 3D printed frame
- Oled display - BDD 12C 1.3in, 128X64
- DHT11 temperature/humidity sensor
- 3 to 4 LEDs for cool incominig / outgoing light effects.

## 📍 Pins
- DHT11 sensor: pin `0`
- Error red Leds: pin `9`
- Notification Leds: pins `21, 20, 10`
- Display: pins `2, 3, 1` // SDA, SCL and ground


## 🐌 Other
- Create a `secrets.h` header where the .ino files live. `./sensai-beacon/secrets.h`
- Add WIFI_SSID and WIFI_PASSWORD variables in `secrets.h`, to connect to your wifi.

## 🤖 Compile & upload
- Uses `arduinio_cli` to compile and upload
- If on windows, use git bash in project directory to run `./Makefile`
- Use the commands in the Makefile to compile / upload / monitor to esp32-c3 board. ie; run `make sensai-beacon` in the terminal of the project and it will build for `sensai-beacon.ino`, or `make monitor` etc

## Use
- open browser
- To send a message and display it on the oled: `localUrl/message?text=hello%how%are%you&textSize=3`
- return and display temperature: `localUrl/temperature`
- return and display humidity: `localUrl/humidity`

## Reminder for self
- all of my esp32 c3 boards automatically reset after upload except for one board, 
this specific board requires me to first flash it (hold down reset + boot for a few seconds, and let go of reset first before boot), then compile and upload, and finally push reset for it to run the new firmware.

![pies](https://github.com/user-attachments/assets/d39e6d7b-e0d5-4c31-91fe-12335591b47c)














