#include <Adafruit_NeoPixel.h>

#define PIN 2         // Das ist GPIO2 auf den meisten ESP8266-Boards
#define NUMPIXELS 144 // Anzahl der angeschlossenen LEDs
#define WAIT 25
#define MAX_COLOR 255
#define HALF_COLOR 128

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void colorWipe(uint32_t, int);
void slidingPixels(uint32_t, int);
void oddOrEven(uint32_t, int, int);

void setup()
{
  strip.begin();
  strip.show(); // Initialisiere alle Pixel mit ausgeschalteter Farbe (schwarz)
}

void loop()
{
  uint32_t COL_MAGENTA = strip.Color(HALF_COLOR, 0, HALF_COLOR);
  slidingPixels(COL_MAGENTA, 35);
  delay(500);

  oddOrEven(COL_MAGENTA, 100, 2);
  delay(500);

  oddOrEven(COL_MAGENTA, 100, 3);
  delay(500);

  oddOrEven(COL_MAGENTA, 100, 5);
  delay(500);

  oddOrEven(COL_MAGENTA, 100, 10);
  delay(500);
}

// Funktion für das Füllen der LEDs mit einer bestimmten Farbe
void colorWipe(uint32_t color, int wait)
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

void slidingPixels(uint32_t color, int wait)
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    if (i > 0)
    {
      strip.setPixelColor(i - 1, strip.Color(0, 0, 0));
    }
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);

    // clear all LED
    strip.clear();
    strip.show();
  }
}

void oddOrEven(uint32_t color, int wait, int distance = 2)
{
  uint32_t fg = color;
  uint32_t black = strip.Color(0, 0, 0);
  uint32_t effectiveColor;

  for (int c = 0; c < 10; c++)
  {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      effectiveColor = i % distance == 0 ? fg : black;
      strip.setPixelColor(i, effectiveColor);
    }
    strip.show();
    delay(125);

    for (int i = 0; i < strip.numPixels(); i++)
    {
      effectiveColor = i % distance == 1 ? fg : black;
      strip.setPixelColor(i, effectiveColor);
    }
    strip.show();
    delay(125);
  }

  // clear all LED
  strip.clear();
  strip.show();
}
