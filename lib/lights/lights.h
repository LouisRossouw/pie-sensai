#ifndef LIGHTS_H
#define LIGHTS_H

#include "Arduino.h"

class Lighting
{

public:
    Lighting(int pin0, int pin1, int pin2, int pin3);

    void begin();
    void lightupPull(int delayMs);
    void lightupPush(int delayMs);

    void blink(int times, int delayMs);
    void builtInblink(int times, int delayMs);
    void disconnected(int times, int delayMs);
    // void pulse(int delayMs);

    void loop();

private:
    int _pin0;
    int _pin1;
    int _pin2;
    int _pin3;
};

#endif