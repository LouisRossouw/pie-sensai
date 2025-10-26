#include <ArduinoJson.h>

#include "api.h"

void handleRoot(WebServer &server)
{
    leds.lightupPull(50);
    StaticJsonDocument<200> doc;
    doc["message"] = "Hello from ESP32!";

    display.showMessage("Hi =)", 3);

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
        leds.error(5, 50);
        return;
    }

    String message = "H:" + String(humidity, 1) + "%";
    display.showMessage(message, 3);

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
        leds.error(5, 50);
        return;
    }

    String message = "T:" + String(temperature, 1) + "%";
    display.showMessage(message, 3);

    doc["temperature"] = temperature;

    String json;
    serializeJson(doc, json);
    server.send(200, "application/json", json);
    leds.lightupPush(50);
}

void handleMessage(WebServer &server)
{
    if (server.hasArg("text"))
    {
        leds.lightupPull(50);
        String message = server.arg("text");
        String txtSizeStr = server.arg("textSize");

        // If txtSizeStr is empty; "", .toInt will result in 0,
        // and showMessage will fallback to default _textSize
        int txtSize = txtSizeStr.toInt();

        // Print to serial
        Serial.print("Received message: ");
        Serial.println(message);

        // Show on OLED
        display.showMessage(message, txtSize);

        server.send(200, "application/json", "{\"status\":\"ok\",\"message\":\"" + message + "\"}");
        leds.lightupPush(50);
    }
    else
    {
        server.send(400, "application/json", "{\"error\":\"Missing 'text' parameter\"}");
        leds.error(5, 50);
    }
}

// For external devices to display an error.
void handleError(WebServer &server)
{
    if (server.hasArg("text"))
    {

        String message = server.arg("text");
        String txtSizeStr = server.arg("textSize");

        // If txtSizeStr is empty; "", .toInt will result in 0,
        // and showMessage will fallback to default _textSize
        int txtSize = txtSizeStr.toInt();

        // Print to serial
        Serial.print("Received message: ");
        Serial.println(message);

        // Show on OLED
        display.showMessage(message, txtSize);
        server.send(200, "application/json", "{\"status\":\"ok\",\"message\":\"" + message + "\"}");

        leds.reconnectAttempt(2, 100);
        leds.error(10, 50);
    }
    else
    {
        server.send(400, "application/json", "{\"error\":\"Missing 'text' parameter\"}");
        leds.error(5, 50);
    }
}