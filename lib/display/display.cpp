#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "display.h"

// OLED width & height
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C address (0x3C for most 1.3" OLED displays)
#define OLED_ADDR 0x3C

unsigned long lastUpdate = 0;
const unsigned long screenTimeout = 15000; // 15 sec

Display::Display(int pinSDA, int pinSCL, int textSize)
    : _pinSDA(pinSDA),
      _pinSCL(pinSCL),
      _textSize(textSize),
      _display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire) // construct here
{
}

void Display::begin()
{
    // Initialize I2C with explicit pins
    Wire.begin(_pinSDA, _pinSCL); // SDA=2, SCL=3  (adjust to your wiring!)

    // Initialize OLED
    if (!_display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don’t proceed, loop forever
    }

    _display.clearDisplay();

    // Set text size, color, position
    _display.setTextSize(_textSize);
    _display.setTextColor(SSD1306_WHITE);
    _display.setCursor(0, 0);

    // Print something
    showMessage("Hello, ESP32!");
    _display.display(); // Push to screen
}

void Display::showMessage(const String &msg)
{
    Serial.println("OLED update: " + msg);

    _display.clearDisplay();
    _display.setTextSize(_textSize);
    _display.setTextColor(SSD1306_WHITE);

    int16_t x1, y1;
    uint16_t w, h;
    _display.getTextBounds(msg, 0, 0, &x1, &y1, &w, &h);

    int x = (SCREEN_WIDTH - w) / 2;
    int y = (SCREEN_HEIGHT - h) / 2;
    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;

    _display.setCursor(x, y);
    _display.println(msg);
    _display.display();

    lastUpdate = millis();
}

void Display::loop()
{
    if (millis() - lastUpdate > screenTimeout)
    {
        _display.clearDisplay();
        _display.display();
    }
}