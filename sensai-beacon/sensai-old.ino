
****
****
****
****
****
****
****

// TODO; Port over


****
****
****
****
****
****
****

// #include <WiFi.h>
// #include <WebServer.h>
// #include <ArduinoJson.h>

// #include "DHT.h"

// #include "../../secrets.h"

// #define DHTPIN 3      // Pin connected to DHT11 data
// #define DHTTYPE DHT11 // DHT11 or DHT22

// #define LED_BUILTIN 8 // The ESP32-C3 Super Mini uses GPIO 8 for the built-in LED
// #define LED_API 1

// unsigned long previousMillis = 0;
// const long interval = 750; // 1 second
// bool ledState = false;

// DHT dht(DHTPIN, DHTTYPE);
// WebServer server(80);

// const char *myHostname = "esp32-temp-sensor";

// void handleRoot()
// {
//     StaticJsonDocument<200> doc;
//     doc["message"] = "Hello from ESP32!";

//     String json;
//     serializeJson(doc, json);
//     server.send(200, "application/json", json);
// }

// void handleLEDOn()
// {
//     digitalWrite(2, HIGH);

//     StaticJsonDocument<200> doc;
//     doc["led"] = true;
//     doc["message"] = "LED is ON";

//     String json;
//     serializeJson(doc, json);
//     server.send(200, "application/json", json);
// }

// void handleLEDOff()
// {
//     digitalWrite(2, LOW);

//     StaticJsonDocument<200> doc;
//     doc["led"] = false;
//     doc["message"] = "LED is OFF";

//     String json;
//     serializeJson(doc, json);
//     server.send(200, "application/json", json);
// }

// void handleHumidity()
// {
//     float humidity = dht.readHumidity();

//     StaticJsonDocument<200> doc;
//     if (isnan(humidity))
//     {
//         doc["error"] = "Failed to read from DHT sensor!";
//         String json;
//         serializeJson(doc, json);
//         server.send(500, "application/json", json);
//         return;
//     }

//     doc["humidity"] = humidity;

//     String json;
//     serializeJson(doc, json);
//     server.send(200, "application/json", json);
//     flashLED();
// }

// void handleTemperature()
// {
//     float temperature = dht.readTemperature();

//     StaticJsonDocument<200> doc;
//     if (isnan(temperature))
//     {
//         doc["error"] = "Failed to read from DHT sensor!";
//         String json;
//         serializeJson(doc, json);
//         server.send(500, "application/json", json);
//         return;
//     }

//     doc["temperature"] = temperature;

//     String json;
//     serializeJson(doc, json);
//     server.send(200, "application/json", json);
//     flashLED();
// }

// void setup()
// {
//     Serial.begin(115200);

//     pinMode(2, OUTPUT);
//     pinMode(LED_API, OUTPUT);
//     pinMode(LED_BUILTIN, OUTPUT);

//     Serial.print("ESP32 MAC Address: ");
//     Serial.println(WiFi.macAddress());

//     // Set the custom hostname
//     WiFi.setHostname(myHostname);

//     // Temp / Humidity module.
//     dht.begin();

//     // Connect to Wi-Fi
//     WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

//     Serial.print("Connecting to WiFi...");
//     while (WiFi.status() != WL_CONNECTED)
//     {
//         delay(500);
//         Serial.print(".");
//         digitalWrite(LED_BUILTIN, LOW);
//     }

//     Serial.println("");
//     Serial.println("WiFi connected.");
//     Serial.println("IP address: ");
//     Serial.println(WiFi.localIP());

//     // Define routes
//     server.on("/", handleRoot);
//     server.on("/led/on", handleLEDOn);
//     server.on("/led/off", handleLEDOff);

//     server.on("/humidity", handleHumidity);
//     server.on("/temperature", handleTemperature);

//     // Start server
//     server.begin();
//     Serial.println("HTTP server started");
// }

// void loop()
// {
//     if (WiFi.status() != WL_CONNECTED)
//     {
//         Serial.println("WiFi disconnected, retrying...");
//         WiFi.begin(ssid, password);
//         digitalWrite(LED_BUILTIN, LOW);
//         delay(10000); // wait 10s before retry
//     }
//     server.handleClient(); // Handle incoming clients

//     // Non-blocking LED blink
//     unsigned long currentMillis = millis();
//     if (currentMillis - previousMillis >= interval)
//     {
//         previousMillis = currentMillis;
//         ledState = !ledState; // toggle LED
//         digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);
//     }
// }

// void flashLED()
// {
//     digitalWrite(LED_API, HIGH);
//     delay(50);
//     digitalWrite(LED_API, LOW);
//     digitalWrite(2, HIGH);
//     delay(50);
//     digitalWrite(2, LOW);
//     digitalWrite(LED_API, HIGH);
//     delay(50);
//     digitalWrite(LED_API, LOW);
// }