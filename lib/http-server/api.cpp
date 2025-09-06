#include <ArduinoJson.h>

#include "api.h"

void handleRoot(WebServer &server)
{
    StaticJsonDocument<200> doc;
    doc["message"] = "Hello from ESP32!";

    leds.lightupPull(50);

    String json;
    serializeJson(doc, json);
    server.send(200, "application/json", json);
}

// TODO

void handleHumidity(WebServer &server)
{
    // float humidity = dht.readHumidity();

    // StaticJsonDocument<200> doc;
    // if (isnan(humidity))
    // {
    //     doc["error"] = "Failed to read from DHT sensor!";
    //     String json;
    //     serializeJson(doc, json);
    //     server.send(500, "application/json", json);
    //     return;
    // }

    // doc["humidity"] = humidity;

    // String json;
    // serializeJson(doc, json);
    // server.send(200, "application/json", json);
}

void handleTemperature(WebServer &server)
{
    // float temperature = dht.readTemperature();

    // StaticJsonDocument<200> doc;
    // if (isnan(temperature))
    // {
    //     doc["error"] = "Failed to read from DHT sensor!";
    //     String json;
    //     serializeJson(doc, json);
    //     server.send(500, "application/json", json);
    //     return;
    // }

    // doc["temperature"] = temperature;

    // String json;
    // serializeJson(doc, json);
    // server.send(200, "application/json", json);
}
