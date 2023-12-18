#include <Adafruit_NeoPixel.h>

#define PIN         2 // Das ist GPIO2 auf den meisten ESP8266-Boards
#define NUMPIXELS   144 // Anzahl der angeschlossenen LEDs
#define WAIT        25
#define MAX_COLOR   255
#define HALF_COLOR  128

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void colorWipe(uint32_t, int);
void slidingPixels(uint32_t, int);


void setup() {
  strip.begin();
  strip.show(); // Initialisiere alle Pixel mit ausgeschalteter Farbe (schwarz)
}

void loop() {

  slidingPixels(strip.Color(HALF_COLOR, 0, HALF_COLOR), 35);
  delay(1000);

}

// Funktion für das Füllen der LEDs mit einer bestimmten Farbe
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

void slidingPixels(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    if(i>0) {
      strip.setPixelColor(i-1, strip.Color(0,0,0));
    }
    if(i==0) {
      strip.setPixelColor(strip.numPixels()-1, strip.Color(0,0,0));
    }
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}


