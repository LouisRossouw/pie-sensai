#include "secrets.h"

#include "connection.h"
#include "http-server.h"
#include "sensors.h"
#include "lights.h"
#include "display.h"

const char *name = "esp32-sensai-test";

Lighting leds(21, 20, 10, 9);
HttpServer httpServer;
Connection net(WIFI_SSID, WIFI_PASSWORD, name, &leds);
Display display(2, 3, 1); // SDA, SCL
Sensors sensors(0);

void setup()
{
    Serial.begin(115200);
    Serial.println("ESP32 starting");

    // Wifi
    net.begin();
    net.printMac();

    // Http server
    httpServer.begin();

    // Lights
    leds.begin();

    // Sensors
    sensors.begin();

    // Display
    display.begin();
}

void loop()
{
    leds.loop();
    net.loop();
    httpServer.loop();
    display.loop();
}
