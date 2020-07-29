#include "clsLED.h"

clsLED::clsLED() {
 
}

clsLED::clsLED(byte pin, bool analog, bool inverted) {
   init(pin, analog, inverted);
}

void clsLED::init(byte pin, bool analog, bool inverted) {
   _pin = pin;
  _analog = analog;
  _inverted = inverted;
  _nextUpdate = millis();
  
  pinMode(_pin, OUTPUT); // set the pin mode
  set(0, 0); // clear led
}

void clsLED::update() {

// are changing from one color to antoher?
  if (desiredBrightness != brightness) {
    
    long currentTime = millis();

    // is it time to change a little
    if (currentTime > _nextUpdate) {
    
      // change up or down
      if (desiredBrightness < brightness) brightness--;
      else if (desiredBrightness > brightness) brightness++;

      // commit this change imeadiatly
      commit();

      // set time for next update
      _nextUpdate = currentTime + _rateOfChange;
    }

  }
}

void clsLED::commit() {

  byte newBrightness = brightness;

  if (_analog) {
    // analog mode
    if (_inverted) newBrightness = 255-newBrightness;  

    analogWrite(_pin, newBrightness);
  }
  else {
    // digital mode
    byte pinValue = LOW;
    if (newBrightness>0) {
      if (_inverted) pinValue = LOW;
      else pinValue = HIGH;
    }
    else {
      if (_inverted) pinValue = HIGH;
      else pinValue = LOW;
    }
    digitalWrite(_pin, pinValue);
  }
}

void clsLED::set(byte newBrightness, long rateOfChange) {
  desiredBrightness = newBrightness; // set object desiredBrightness property
  
  if (rateOfChange == 0) {
    brightness = desiredBrightness; // set object brightness property
    _rateOfChange = 1000; // not sure wh I did this?
    commit();
  }
  else {
    _rateOfChange = rateOfChange;
  }
}

void clsLED::randomSet(long rateOfChange) {
  desiredBrightness = random(0,255);

  if (rateOfChange == 0) {
    brightness = desiredBrightness;
    commit();
  }
  else {
    _rateOfChange = rateOfChange;
  }
}

bool clsLED::changing() {
  if (brightness == desiredBrightness) return false;
  else return true;
}
