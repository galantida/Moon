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
    int lastMode;
    long modeRateOfChange; // default chnage between modes and sub modes

    // cycle variables for modes/sub modes that use them
    int cycle;
    int lastCycle;
    long cycleTime;
    long nextCycleChange; // some modes have times changes
    long cycleRateOfChange;

    byte phase; // full and half moon

    // functions
    clsMoon();
    void init();
    void update();

    // led function
    void set(byte red, byte green, byte blue, byte phase, long rateOfChange);
    void randomSet(byte phase, long rateOfChange);
    bool changing();

    // mode settings
    void updateDisplay();
    void nextMode();
    void nextPhase();
  
   private:
    // properties
    int nextModeTime;
    
    // functions
  
};
#endif
