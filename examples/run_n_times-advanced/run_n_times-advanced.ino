/**
 * @file run_n_times-advanced.ino
 * @brief Demonstrates how to restart a timer using TimerKernel
 * 
 * @details
 * This sketch shows:
 *  - Using hasExpired() to check if a certain duration has passed.
 *  - Using toggledState() to blink an LED 3 times
 *  - Using resetToggleState() to restart the blinking when a button is pressed.
 */

#include "TimerKernel.h"

TimerKernel MyTimer;

const unsigned long durationInSec = 1;     ///< Time interval (1 second)
const int runAmount = 3;                   ///< Number of times the The Led blinks (3)
const int button = 10;                     ///< Button Pin
const int debounceDelay = 200;             ///< Duration the button must stay pressed to register (250 ms) 


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);            ///< Configure LED pin as output
  pinMode(button, INPUT_PULLUP);           ///< Configure button pin with internal pull-up resistor
}


/**
 * @brief Checks if the button has been pressed for a specific duration.
 * @return true if the button remains pressed for the given duration, false otherwise.
 */
bool buttonPressed() {
  int buttonState = digitalRead(button);

  if(MyTimer.hasExpired(debounceDelay) && buttonState == LOW) {
    return true;
  } else {
    return false;
  }
}


void loop() {
  /**
   * @brief Toggles the built-in LED every second, for 3 times.
   */
  digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInSec, SECOND, runAmount));

  /**
   * @brief When the button is pressed, reset the toggle state to restart blinking.
   */
  if (buttonPressed()) {
    MyTimer.resetToggleState();
  }
}
