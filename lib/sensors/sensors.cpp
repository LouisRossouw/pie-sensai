#include "sensors.h"

Sensors::Sensors(int dhtPin, uint8_t sensorType)
    : _dhtPin(dhtPin), _dht(dhtPin, sensorType)
{
}

void Sensors::begin()
{
    // Temperature & Humidity sensor
    _dht.begin();
}

float Sensors::getHumidity()
{
    return _dht.readHumidity();
}

float Sensors::getTemperature()
{
    Serial.println("--02");
    return _dht.readTemperature();
}
