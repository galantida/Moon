#ifndef clsMoon_H
#define clsMoon_H

#include <Arduino.h>
#include "clsRGBLED.h"
#include "clsButton.h"

class clsMoon {

  public:
    // properties
    clsRGBLED rgbled1;
    clsRGBLED rgbled2;
    
    int mode;
    int subMode; // full and half moon
    long modeRateOfChange; // default chnage between modes and sub modes

    // cycle variables for modes/sub modes that use them
    int cycle;
    long cycleTime;
    long nextCycleChange; // some modes have times changes
    long cycleRateOfChange;

    // functions
    clsMoon();
    void init();
    void update();

    // led function
    void set(byte red, byte green, byte blue, bool fullMoon, long rateOfChange);
    void randomSet(bool fullMoon, long rateOfChange);
    bool changing();

    // mode settings
    void updateMode();
    void nextMode();
    void nextSubMode();
    void nextCycle();
  
   private:
    // properties
    int nextModeTime;
    
    // functions
  
};
#endif
