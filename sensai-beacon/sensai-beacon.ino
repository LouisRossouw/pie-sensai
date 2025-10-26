#include "secrets.h"
#include "esp_bt.h"

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

    // Disable Bluetooth
    if (esp_bt_controller_get_status() == ESP_BT_CONTROLLER_STATUS_ENABLED)
    {
        esp_bt_controller_disable();
        esp_bt_controller_deinit();
    }

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
