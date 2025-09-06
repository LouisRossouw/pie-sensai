#include "lights.h"

#define LED_BUILTIN 8

Lighting::Lighting(int pin0, int pin1, int pin2, int pin3)
{
    _pin0 = pin0;
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
}

void Lighting::begin()
{
    pinMode(_pin0, OUTPUT);
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);

    pinMode(_pin3, OUTPUT);

    pinMode(LED_BUILTIN, OUTPUT);

    digitalWrite(_pin0, LOW);
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);

    digitalWrite(_pin3, LOW);

    digitalWrite(LED_BUILTIN, LOW);
}

void Lighting::lightupPull(int delayMs)
{
    digitalWrite(_pin0, HIGH);
    delay(delayMs);
    digitalWrite(_pin0, LOW);
    delay(delayMs);
    digitalWrite(_pin1, HIGH);
    delay(delayMs);
    digitalWrite(_pin1, LOW);
    delay(delayMs);
    digitalWrite(_pin2, HIGH);
    delay(delayMs);
    digitalWrite(_pin2, LOW);
    delay(delayMs);
}

void Lighting::lightupPush(int delayMs)
{
    digitalWrite(_pin2, HIGH);
    delay(delayMs);
    digitalWrite(_pin2, LOW);
    delay(delayMs);
    digitalWrite(_pin1, HIGH);
    delay(delayMs);
    digitalWrite(_pin1, LOW);
    delay(delayMs);
    digitalWrite(_pin0, HIGH);
    delay(delayMs);
    digitalWrite(_pin0, LOW);
    delay(delayMs);
}

void Lighting::blink(int times, int delayMs)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(_pin0, HIGH);
        delay(delayMs);
        digitalWrite(_pin0, LOW);
        delay(delayMs);
    }
}

void Lighting::builtInblink(int times, int delayMs)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(delayMs);
        digitalWrite(LED_BUILTIN, LOW);
        delay(delayMs);
    }
}

void Lighting::disconnected(int times, int delayMs)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(_pin3, HIGH);
        delay(delayMs);
        digitalWrite(_pin3, LOW);
        delay(delayMs);
    }
}

// void Lighting::pulse(int delayMs)
// {
//     for (int i = 0; i < 255; i++)
//     {
//         analogWrite(_pin, i);
//         delay(delayMs);
//     }
//     for (int i = 255; i > 0; i--)
//     {
//         analogWrite(_pin, i);
//         delay(delayMs);
//     }
// }

void Lighting::loop()
{
    // Empty for now.
    // this->blink(1, 200);
}
