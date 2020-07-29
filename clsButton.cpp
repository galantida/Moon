#include "clsButton.h"

clsButton::clsButton() {
}

clsButton::clsButton(byte pin) {
  init(pin);
}

void clsButton::init(byte pin) {
  debounceDelay = 50;
  this->pin = pin;
  pinMode(pin, INPUT);
  lastReading = LOW;
  update();
}
void clsButton::update() {
    // You can handle the debounce of the button directly
    // in the class, so you don't have to think about it
    // elsewhere in your code
    byte newReading = digitalRead(pin);

    // look for a change
    if (newReading != lastReading) {
      lastDebounceTime = millis();
    }
    
    if (millis() - lastDebounceTime > debounceDelay) {
      // Update the 'state' attribute only if debounce is checked
      state = newReading;
    }
    lastReading = newReading;
}
bool clsButton::isPressed() {
  return (state == HIGH);
}

bool clsButton::wasPressed() {
  // button changed?
  if (lastState != state) {
    lastState = state;
    if (state == HIGH) return true;
    else return false;
  }
  else return false;
}
