#include "lights.h"
#include "connection.h"

#include "secrets.h"

#define LED_BUILTIN 8

const char *name = "esp32-sensai";

Lighting leds(0, 1, 2);
Connection net(WIFI_SSID, WIFI_PASSWORD, name);

void setup()
{
    delay(4000);
    Serial.begin(115200);
    Serial.print("ESP32 starting");

    Serial.print(WIFI_SSID);
    Serial.print(WIFI_PASSWORD);

    // Lights
    leds.begin();

    // // Wifi
    net.begin();
    net.printMac();
}

void loop()
{
    leds.lightupPull(50);
    leds.lightupPush(50);
    // leds.blink(3, 200);
}
