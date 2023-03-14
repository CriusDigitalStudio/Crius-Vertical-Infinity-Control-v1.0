const int numPots = 8;  // Set number of Potentiometers
const int numLeds = 8;  // Set number of Leds per Ring or Strip
const int pots[numPots] = {A0, A1, A2, A3, A6, A7, A8, A9}; // Set pins for potentiometers
const int ledPins[numPots] = {10, 16, 15, 14, 7, 5, 2, 3}; // Set Data pins for Led Rings or Strips

Adafruit_NeoPixel ledRings[numPots];  //

void LED_Rings_Setup() {
  for (int i = 0; i < numPots; i++) {
    ledRings[i] = Adafruit_NeoPixel(numLeds, ledPins[i], NEO_GRB + NEO_KHZ800);
    ledRings[i].begin();
  }
}

void LED_Rings_Loop() {
  for (int i = 0; i <= numPots; i++) {
    int potValue = analogRead(pots[i]);
    int ledIndex = map(potValue, 0, 1023, 1, numLeds + 1);
    int brightnessRed = map(potValue, 0, 255, 0, 0);
    int brightnessBlue = map(potValue, 0, 1023, 0, 5);

    for (int j = 1; j <= ledIndex; j++) {
      int blue = map(j, 0, numLeds, 12, 0);
      int red = map(j, 0, numLeds, 12, 0);
      ledRings[i].setPixelColor(j,  brightnessBlue, brightnessRed, blue, red);
      ledRings[i].setPixelColor(0, 1, 1, 1, 1);
    }

    for (int j = ledIndex; j <= numLeds; j++) {
      ledRings[i].setPixelColor(j, 0, 0, 0);
    }

    for (int j = ledIndex; j <= numLeds; j++) {
      ledRings[i].setPixelColor(j, 0, 0, 0);
      ledRings[i].show();
    }
  }
}
