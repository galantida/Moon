#include "clsMoon.h"

// properties


// internal values
int lastModeButtonState;
int lastSubModeButtonState;

// objects
clsButton modeButton;
clsButton subModeButton;
clsMoon moon; 

void setup() {
  modeButton.init(2);    
  lastModeButtonState = HIGH;
  
  subModeButton.init(4);
  lastModeButtonState = HIGH;    
}

void loop() {
  // put your main code here, to run repeatedly:

  //process Mode Button
  modeButton.update();
  if (modeButton.wasPressed()) moon.nextMode();

  //process Sub Mode Button
  subModeButton.update();
  if (subModeButton.wasPressed()) moon.nextSubMode();

  moon.update();
}
