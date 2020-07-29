#include "clsRGBLED.h"
#include "clsLED.h"

clsRGBLED::clsRGBLED() {
  
}

clsRGBLED::clsRGBLED(byte redPin, byte greenPin, byte bluePin, bool inverted) {
  init(redPin, greenPin, bluePin, inverted);
}

void clsRGBLED::init(byte redPin, byte greenPin, byte bluePin, bool inverted) {
  // create a clsLED object and put the address in this objects red variable
  red.init(redPin, true, inverted); 
  green.init(greenPin, true, inverted);
  blue.init(bluePin, true, inverted);
  set(0,0,0,0); // clear rgb;
}

void clsRGBLED::update() {
  red.update();
  green.update();
  blue.update();
}

void clsRGBLED::set(byte redLevel, byte greenLevel, byte blueLevel, long rateOfChange) {
  red.set(redLevel, rateOfChange);
  green.set(greenLevel, rateOfChange);
  blue.set(blueLevel, rateOfChange);
}

void clsRGBLED::randomSet(long rateOfChange) {
  red.randomSet(rateOfChange);
  green.randomSet(rateOfChange);
  blue.randomSet(rateOfChange);
}

bool clsRGBLED::changing() {
  if (red.changing() || green.changing() || blue.changing()) return true;
  else return false;
}
