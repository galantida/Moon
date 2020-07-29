#include "clsMoon.h"

clsMoon::clsMoon() {
  init();
}

void clsMoon::init() {

  // create a clsLED object and put the address in this objects red variable
  rgbled1.init(3, 5, 6, true); 
  rgbled2.init(9, 10, 11, true); 

  // init settings
  mode = 0; 
  subMode = 0;
  cycle = 0; 
  modeRateOfChange = 8; // fade between modes time. (ms per color step to new color)
  set(0, 0, 0, true, 0); // moon off

  //startup cycle
  cycleTime = 4 * 1000; // startup mode time
  cycleRateOfChange = 10; // startup fade in time. (ms per color step to new color)
  nextCycleChange = millis() + cycleTime; // set timer to end startup mode
  set(0, 255, 0, true, modeRateOfChange); // green moon
}

void clsMoon::update() {

  // timed cycle
  long currentTime = millis();
  if (currentTime > nextCycleChange) {
    nextCycleChange = currentTime + cycleTime;
    if (mode == 0) nextCycle(); // list modes with cycles
    if ((mode == 5)||(mode == 6)) updateMode(); // list modes that run different each time they are run.
  }
  
  rgbled1.update();
  rgbled2.update();
}

void clsMoon::updateMode() {

  // determine default submode
  if (subMode > 1) subMode = 0;
  bool fullMoon = true;
  if (subMode == 1) fullMoon = false; 

  // determine mode
  switch (mode)
  {
    case 0:
      if (cycle > 3) cycle = 0;
      if (cycle==0) {
        // set up for demo cycles
        cycleTime = 10 * 1000;
        cycleRateOfChange = 10;
        set(255, 255, 255, fullMoon, cycleRateOfChange); // white moon
      }
      else if (cycle==1) set(128, 128, 255, fullMoon, cycleRateOfChange); // blue moon
      else if (cycle==2) set(255, 255, 0, fullMoon, cycleRateOfChange); // yellow moon
      else set(255, 128, 0, fullMoon, cycleRateOfChange); // red moon
      break;
    case 1:
      set(255, 255, 255, fullMoon, modeRateOfChange); // white moon
      break;
    case 2:
      set(128, 128, 255, fullMoon, modeRateOfChange); // blue moon
      break;
    case 3:
      set(255, 255, 0, fullMoon, modeRateOfChange); // yellow moon
      break;
    case 4:
      set(255, 128, 0, fullMoon, modeRateOfChange); // red moon
      break;
    case 5:
      // random mode
      cycleTime = 5 * 1000;
      cycleRateOfChange = 10;
      randomSet(fullMoon, cycleRateOfChange); // random moon
      break;
    case 6:
      // motion mode
      cycleTime = 1 * 1000;
      cycleRateOfChange = 5;
      rgbled2.set(rgbled1.red.brightness, rgbled1.green.brightness, rgbled1.blue.brightness, cycleRateOfChange); // copy this half from previous random half
      rgbled1.randomSet(cycleRateOfChange); // randomize this half.
      break;
    case 7:
       set(0,0,0,true, 0); // off
    default:
      mode = 0; // reset mode
      break;
  }
}

void clsMoon::set(byte red, byte green, byte blue, bool fullMoon, long rateOfChange) {
  rgbled1.set(red, green, blue, rateOfChange);
  if (fullMoon)rgbled2.set(red, green, blue, rateOfChange);
  else rgbled2.set(0, 0, 0, rateOfChange);
}


void clsMoon::randomSet(bool fullMoon, long rateOfChange) {

  if (fullMoon) {
    // keep the colors in sync
    byte randomRed = random(0,255);
    byte randomGreen = random(0,255);
    byte randomBlue = random(0,255);
    rgbled1.set(randomRed, randomGreen, randomBlue, rateOfChange);
    rgbled2.set(randomRed, randomGreen, randomBlue, rateOfChange);
  }
  else {
    // each half does it's own random
    rgbled1.randomSet(rateOfChange);
    //rgbled2.randomSet(rateOfChange);   // random
    rgbled2.set(255-rgbled1.red.brightness,255-rgbled1.green.brightness, 255-rgbled1.blue.brightness, rateOfChange);   // complimentary
  }
}

bool clsMoon::changing() {
  if (rgbled1.changing() || rgbled2.changing()) return true;
  else return false;
}

void clsMoon::nextMode() {
  mode++;
  subMode=0;
  cycle=0;
  updateMode();
}

void clsMoon::nextSubMode() {
  subMode++;
  cycle=0;
  updateMode();
}

void clsMoon::nextCycle() {
  cycle++;
  updateMode();
}
