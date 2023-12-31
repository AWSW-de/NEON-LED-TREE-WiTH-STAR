// ###########################################################################################################################################
// #
// # Code for the printables "XMAS neon LED tree with star" project:
// # https://www.printables.com/de/model/699250-xmas-neon-led-tree-with-star
// #
// # Code by https://github.com/AWSW-de
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/NEON-LED-TREE-WiTH-STAR#GPL-3.0-1-ov-file
// #
// ###########################################################################################################################################


// ###########################################################################################################################################
// # Code version:
// ###########################################################################################################################################
String Code_Version = "V1.0.0";


// ###########################################################################################################################################
// # Includes:
// #
// # FastLED                // by Daniel Garcia               // https://github.com/FastLED/FastLED
// #
// ###########################################################################################################################################
#include "FastLED.h"


// ###########################################################################################################################################
// # Hardware settings:
// ###########################################################################################################################################
// How many LEDs are in your neon LED strip?:
#define NUM_LEDS 54
// Data pin - here D5 with GPIO 14 on the Wemos D1 mini ESP8266:
#define DATA_PIN 14


// ###########################################################################################################################################
// # Animation settings:
// ###########################################################################################################################################
int UseAnimation = 1;        // Use animation (1) in the loop function or not (0)
int AnimationSpeed = 15000;  // Animation speed in milliseconds, 15000 = 15 seconds


// ###########################################################################################################################################
// # Definitions:
// ###########################################################################################################################################
// Define the array of leds:
CRGB leds[NUM_LEDS];


// ###########################################################################################################################################
// # Startup function:
// ###########################################################################################################################################
void setup() {
  Serial.begin(115200);

  // Initialize the LED strip:
  FastLED.addLeds<WS2811, DATA_PIN, BRG>(leds, NUM_LEDS);

  // Switch all LEDs off first:
  LEDS.showColor(CRGB(0, 0, 0));

  // Set LED brightness (0-255);
  LEDS.setBrightness(128);

  // Some animation and LED RGB color output testing first:

  // Set all LEDs to red:
  for (int i = 0; i < NUM_LEDS - 1; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(25);
  }
  delay(1000);

  // Set all LEDs to green:
  for (int i = 0; i < NUM_LEDS - 1; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(25);
  }
  delay(1000);

  // Set all LEDs to blue:
  for (int i = 0; i < NUM_LEDS - 1; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(25);
  }
  delay(1000);

    // Set all LEDs to white:
  for (int i = 0; i < NUM_LEDS - 1; i++) {
    leds[i] = CRGB::White;
    FastLED.show();
    delay(25);
  }
  delay(1000);

  // Set all LEDs in the tree to green:
  for (int i = 0; i < NUM_LEDS - 11; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(25);
  }

  // Set all LEDs in the star to yellow:
  for (int i = 43; i < NUM_LEDS - 1; i++) {
    leds[i] = CRGB::Yellow;
    FastLED.show();
    delay(25);
  }
}


// ###########################################################################################################################################
// # Runtime function:
// ###########################################################################################################################################
void loop() {
  if (UseAnimation == 1) {
    // Set all LEDs to green:
    for (int i = 0; i < NUM_LEDS - 11; i++) {
      leds[i] = CRGB::Green;
    }
    // 5 random "ornament" pixels:
    for (int i = 0; i < 6; i++) {
      int randNumber = random(0, NUM_LEDS - 11);
      leds[randNumber] = CRGB::White;
      FastLED.show();
      delay(AnimationSpeed / 5);
    }
  }
}