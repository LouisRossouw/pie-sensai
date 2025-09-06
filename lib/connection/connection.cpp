#include <WiFi.h>
#include "connection.h"

Connection::Connection(const char *ssid, const char *password, const char *hostname, Lighting *lights)
    : _ssid(ssid), _password(password), _hostname(hostname), _lights(lights) {}

void Connection::begin()
{
    WiFi.mode(WIFI_STA);
    WiFi.setHostname(_hostname);
    WiFi.begin(_ssid, _password);

    Serial.println("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        if (_lights)
        {
            _lights->blink(1, 50); // blink LED while waiting
        }
        else
        {
            delay(500); // fallback
        }
        Serial.print(".");
    }
    Serial.println(" connected!");
}

void Connection::printMac()
{
    Serial.print("ESP32 MAC Address: ");
    Serial.println(WiFi.macAddress());
}

void Connection::loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("WiFi disconnected, retrying...");
        WiFi.begin(_ssid, _password);
        delay(10000); // wait 10s before retry
    }
}