#include "secrets.h"

#include "connection.h"
#include "http-server.h"
#include "sensors.h"
#include "lights.h"

const char *name = "esp32-sensai";

Lighting leds(0, 1, 2);
HttpServer httpServer;
Connection net(WIFI_SSID, WIFI_PASSWORD, name, &leds);
Sensors sensors(3);

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
}

void loop()
{
    leds.loop();
    net.loop();
    httpServer.loop();
}
