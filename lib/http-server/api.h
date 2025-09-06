#ifndef API_H
#define API_H

#include "../lights/lights.h"
#include "../sensors/sensors.h"

#include <WebServer.h>

extern Lighting leds;
extern Sensors sensors;

void handleRoot(WebServer &server);
void handleHumidity(WebServer &server);
void handleTemperature(WebServer &server);

#endif
