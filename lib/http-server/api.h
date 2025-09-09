#ifndef API_H
#define API_H

#include "../lights/lights.h"
#include "../sensors/sensors.h"
#include "../display/display.h"

#include <WebServer.h>

extern Lighting leds;
extern Sensors sensors;
extern Display display;

void handleRoot(WebServer &server);
void handleHumidity(WebServer &server);
void handleTemperature(WebServer &server);
void handleMessage(WebServer &server);
void handleError(WebServer &server);

#endif
