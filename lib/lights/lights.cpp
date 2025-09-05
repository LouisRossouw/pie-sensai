#include "lights.h"

Lighting::Lighting(int pin0, int pin1, int pin2)
{
    _pin0 = pin0;
    _pin1 = pin1;
    _pin2 = pin2;
}

void Lighting::begin()
{
    pinMode(_pin0, OUTPUT);
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);

    digitalWrite(_pin0, LOW);
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
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
