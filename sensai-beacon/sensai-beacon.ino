#include "lights.h"
#include "connection.h"
#include "http-server.h"

#include "secrets.h"

const char *name = "esp32-sensai";

Lighting leds(0, 1, 2);
Connection net(WIFI_SSID, WIFI_PASSWORD, name, &leds);
HttpServer httpServer;

void setup()
{
    delay(4000);
    Serial.begin(115200);
    Serial.println("ESP32 starting");

    // Lights
    leds.begin();

    // Wifi
    net.begin();
    net.printMac();

    // Http server
    httpServer.begin();
}

void loop()
{
    leds.loop();
    net.loop();
    httpServer.loop();
}
