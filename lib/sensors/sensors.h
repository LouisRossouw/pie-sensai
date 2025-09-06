
#ifndef SENSORS_H
#define SENSORS_H

#include "Arduino.h"
#include "DHT.h"

class Sensors
{
public:
    Sensors(int dhtPin, uint8_t sensorType = DHT11);

    void begin();
    float getHumidity();
    float getTemperature();

private:
    // DHT11; temperature & humidity sensor.
    int _dhtPin;
    DHT _dht;
};

#endif