#include <WiFi.h>
#include "connection.h"

unsigned long lastReconnectAttempt = 0;
const unsigned long reconnectInterval = 10000; // 10 seconds

bool startUpConnected = false;
bool hasPlayedConnected = false;

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
        startUpConnected = false;
        Serial.print(".");
    }
    startUpConnected = true;
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
        // blink only when disconnected
        _lights->disconnected(1, 100);
        _lights->builtInLedOff();

        hasPlayedConnected = false;

        unsigned long now = millis();

        // check if enough time has passed since last attempt
        if (now - lastReconnectAttempt >= reconnectInterval)
        {
            _lights->reconnectAttempt(2, 100);

            lastReconnectAttempt = now;
            Serial.println("WiFi disconnected, retrying...");
            WiFi.begin(_ssid, _password);
        }
    }
    else
    {
        _lights->off();
        _lights->builtInblink(1, 1000, 100);

        if (!hasPlayedConnected)
        {
            _lights->connected(50);
            hasPlayedConnected = true;
        }
    }
}