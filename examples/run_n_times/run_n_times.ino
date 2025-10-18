/**
 * @file run_n_times.ino
 * @brief Example sketch for doing a task a specific number of times
 *
 * This sketch shows:
 *  - Using hasExpired() to execute a task once after a set duration.
 *  - Using toggledState() to blink an LED infinitely at a given interval.
 *
 */

#include <TimerKernel.h>

TimerKernel MyTimer;

// duration 1 second 
const long durationInSec = 1;

void setup() {
  Serial.begin(9600);             ///< Start serial communication at 9600 baud
  pinMode(LED_BUILTIN, OUTPUT);   ///< Configure LED pin as output

}

void loop() {
  /**
   * @brief Print "Hello world" once after 1 second
   */
  if (MyTimer.hasExpired(durationInSec, SECOND, 1)) {
    Serial.println("Hello world");
  }

  /**
   * @brief Blink the built-in LED infinitely at a 1-second interval
   */
  digitalWrite(LED_BUILTIN, MyTimer.toggledState(durationInSec, SECOND, TimerKernel::INFINITE));

}
