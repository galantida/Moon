#include "clsMoon.h"

// objects
clsButton modeButton;
clsButton phaseButton;
clsMoon moon; 

void setup() {
  modeButton.init(2);    
  phaseButton.init(4);
}

void loop() {
  // put your main code here, to run repeatedly:

  //process Mode Button
  modeButton.update();
  if (modeButton.wasPressed()) moon.nextMode();

  //process Sub Mode Button
  phaseButton.update();
  if (phaseButton.wasPressed()) moon.nextPhase();

  moon.update();
}
