#include <Adafruit_NeoPixel.h>
#include "LED_Rings_Config.h"
#include <Control_Surface.h> // Include the Control Surface library

// Instantiate a MIDI over USB interface.
USBMIDI_Interface midi;

// Instantiate CCPotentiometers
CCPotentiometer potentiometers[] {
  {A0, 0x11},
  {A1, 0x10},
  {A2, 0x14},
  {A3, 0x15},
  {A6, 0x12},
  {A7, 0x13},
  {A8, 0x17},
  {A9, 0x16},
};

void setup() {
  LED_Rings_Setup();
  Control_Surface.begin(); // Initialize Control Surface
}

void loop() {
  LED_Rings_Loop();
  Control_Surface.loop(); // Update the Control Surface
}
