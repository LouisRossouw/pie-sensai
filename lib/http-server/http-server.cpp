#include <WebServer.h>
#include <ArduinoJson.h>

#include "api.h"
#include "http-server.h"

WebServer server(80);

HttpServer::HttpServer() {}

void HttpServer::begin()
{
    // Define routes
    this->routes();

    // Start server
    server.begin();
    Serial.println("HTTP server started");
}

void HttpServer::loop()
{
    // Handle incoming clients
    server.handleClient();
}

void HttpServer::routes()
{
    server.on("/", [this]()
              { handleRoot(server); });

    server.on("/humidity", [this]()
              { handleHumidity(server); });
    server.on("/temperature", [this]()
              { handleTemperature(server); });
    server.on("/message", [this]()
              { handleMessage(server); });
}