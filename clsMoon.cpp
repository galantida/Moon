#include "clsMoon.h"

clsMoon::clsMoon() {
  init();
}

void clsMoon::init() {

  // settings
  modeRateOfChange = 5; // fade between modes. (ms per color step to new color)
  cycleRateOfChange = 10; // fade between cycles. (ms per color step to new color)

  // create a clsLED object and put the address in this objects red variable
  rgbled1.init(3, 5, 6, true); 
  rgbled2.init(9, 10, 11, true); 

  // init settings
  mode = 0; // start off
  lastMode = -1;
  cycle = 0; // clear cycle
  lastCycle = -1;
  cycleTime = 4 * 1000; // time to spend on each cycle. (Modes may change this)

  phase = 0; // 0-fullmoon 1-halfmoon

  nextCycleChange = millis() + 2000; // set timer to end startup mode
  set(0, 255, 0, phase, modeRateOfChange); // green moon
}

void clsMoon::update() {

  // cycle updates
  long currentTime = millis();
  if (currentTime > nextCycleChange) {
    nextCycleChange = currentTime + cycleTime;
    cycle++;
    if (cycle>1000) cycle = 0; // cycle protection
    updateDisplay(); // update display each cycle change.
  }

  // allow leds to update every cycle as needed
  rgbled1.update();
  rgbled2.update();
}

void clsMoon::updateDisplay() {

  // determine mode
  switch (mode)
  {
    case 0:
    {
      // off
      if (mode != lastMode) set(0,0,0,phase, modeRateOfChange); // set off on power up
      else {
        // this section runs when we are off
        
      }
      break;
    }
    case 1:
      if (cycle > 3) cycle = 0;
      
      if (mode != lastMode) {
        // set up for demo cycles
        cycle = 0;
        cycleTime = 10 * 1000;
        cycleRateOfChange = 10;
      }
      
      if (cycle==0) set(255, 255, 255, phase, cycleRateOfChange); // white moon
      else if (cycle==1) set(128, 128, 255, phase, cycleRateOfChange); // blue moon
      else if (cycle==2) set(255, 255, 0, phase, cycleRateOfChange); // yellow moon
      else set(255, 128, 0, phase, cycleRateOfChange); // red moon
      break;
    case 2:
      if (mode != lastMode) set(255, 255, 255, phase, modeRateOfChange); // white moon
      break;
    case 3:
      if (mode != lastMode) set(128, 128, 255, phase, modeRateOfChange); // blue moon
      break;
    case 4:
      if (mode != lastMode) set(255, 255, 0, phase, modeRateOfChange); // yellow moon
      break;
    case 5:
      if (mode != lastMode) set(255, 128, 0, phase, modeRateOfChange); // red moon
      break;
    case 6:
      // random mode
      if (mode != lastMode) {
        // setup
        cycleTime = 5 * 1000;
        cycleRateOfChange = 10;
      }
      randomSet(phase, cycleRateOfChange); // random moon
      break;
    case 7:
      // motion mode
      if (mode != lastMode) {
        // setup
        cycle = 0;
        cycleTime = 1 * 1000;
        cycleRateOfChange = 5;
      }
      rgbled2.set(rgbled1.red.brightness, rgbled1.green.brightness, rgbled1.blue.brightness, cycleRateOfChange); // copy this half from previous random half
      rgbled1.randomSet(cycleRateOfChange); // randomize this half.
      break;
    default:
      mode = 0; // reset mode
      set(0,0,0,true, modeRateOfChange); // turn off moon
      break;
  }

  lastMode = mode;
  lastCycle = cycle;
}

void clsMoon::set(byte red, byte green, byte blue, byte phase, long rateOfChange) {
  rgbled1.set(red, green, blue, rateOfChange);
  if (phase == 0)rgbled2.set(red, green, blue, rateOfChange);
  else rgbled2.set(0, 0, 0, rateOfChange);
}


void clsMoon::randomSet(byte phase, long rateOfChange) {

  if (phase == 0) {
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
  cycle=0; // reset cycle
  updateDisplay();
}

void clsMoon::nextPhase() {
  if (phase == 0) phase = 1;
  else phase = 0;
  lastMode = -1; // force update
  updateDisplay();
}
