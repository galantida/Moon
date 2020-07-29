#ifndef clsLED_H
#define clsLED_H

#include <Arduino.h>

class clsLED {

  public:
    // properties
    byte brightness;
    byte desiredBrightness; 

    // functions
    clsLED();
    clsLED(byte pin, bool analog, bool inverted);
    void init(byte pin, bool analog, bool inverted);
    void update();
    void set(byte brightness, long rateOfChange);
    void randomSet(long rateOfChange);
    bool changing();
  
  private:
    // properties
    byte _pin;
    byte _inverted; // LED use either a HIGH or LOW signal
    byte _analog; // auto detected

    byte _rateOfChange; // miliseconds between each step increase or descrease
    long _nextUpdate;

    // functions
    void commit();
};
#endif
