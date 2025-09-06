#include <ArduinoJson.h>

#include "api.h"

void handleRoot(WebServer &server)
{
    leds.lightupPull(50);
    StaticJsonDocument<200> doc;
    doc["message"] = "Hello from ESP32!";

    display.showMessage("Pew pew !!");

    String json;
    serializeJson(doc, json);
    server.send(200, "application/json", json);
    leds.lightupPush(50);
}

void handleHumidity(WebServer &server)
{
    leds.lightupPull(50);
    float humidity = sensors.getHumidity();

    StaticJsonDocument<200> doc;
    if (isnan(humidity))
    {
        doc["error"] = "Failed to read from DHT sensor!";
        String json;
        serializeJson(doc, json);
        server.send(500, "application/json", json);
        return;
    }

    doc["humidity"] = humidity;

    String json;
    serializeJson(doc, json);
    server.send(200, "application/json", json);
    leds.lightupPush(50);
}

void handleTemperature(WebServer &server)
{
    leds.lightupPull(50);
    float temperature = sensors.getTemperature();

    StaticJsonDocument<200> doc;
    if (isnan(temperature))
    {
        doc["error"] = "Failed to read from DHT sensor!";
        String json;
        serializeJson(doc, json);
        server.send(500, "application/json", json);
        return;
    }

    doc["temperature"] = temperature;

    String json;
    serializeJson(doc, json);
    server.send(200, "application/json", json);
    leds.lightupPush(50);
}
