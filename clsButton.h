#ifndef clsButton_H
#define clsButton_H

#include <Arduino.h>

class clsButton {

  public:
    // properties

    // functions
    clsButton();
    clsButton(byte pin);
    void init(byte pin);
    void update();
    bool isPressed();
    bool wasPressed();
  
  private:
    // properties
    byte pin;
    byte lastReading;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
    byte state;
    byte lastState;

    // functions
    
  
};
#endif
