#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUMPIXELS 9

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const uint32_t colours[] = {pixels.Color(0, 255, 0), pixels.Color(255, 0, 0), pixels.Color(0, 0, 255), pixels.Color(255, 255, 0)};


void setup() {
  Serial.begin(115200);
  Serial.println("Hello World");
  pixels.begin();
  pixels.setBrightness(10);
  for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, colours[random(0, sizeof(colours) / sizeof(colours[0]))]);
    pixels.show(); 
  }
}

void loop() {
  for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, colours[random(0, sizeof(colours) / sizeof(colours[0]))]);
    pixels.show();
  }
  delay(1000);
}