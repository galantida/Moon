#ifndef clsRGBLED_H
#define clsRGBLED_H

#include <Arduino.h>
#include "clsLED.h"

class clsRGBLED {
  
  public:
    // properties
    // get the clsLED object at this address
    clsLED red;
    clsLED green;
    clsLED blue; 
    

    // functions
    clsRGBLED();
    clsRGBLED(byte redPin, byte greenPin, byte bluePin, bool inverted);
    void init(byte redPin, byte greenPin, byte bluePin, bool inverted);
    void update();
    void set(byte red, byte green, byte blue, long rateOfChange);
    void randomSet(long rateOfChange);
    bool changing();
  
  private:
    // properties
    
    // functions
    
 
};
#endif
