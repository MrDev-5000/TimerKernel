/**
 * @file run_n_times.ino
 * @brief Example sketch for performing a task a specific number of times using TimerKernel
 * 
 * @details
 * This sketch shows:
 *  - Using hasExpired() to execute a task once after a set duration.
 *  - Using toggledState() to blink an LED infinitely at a given interval.
 */

#include <TimerKernel.h>

TimerKernel MyTimer;

const unsigned long durationInSec = 1;     ///< time interval (1 second)
const int runAmount = 1;          ///< Number of times the timer runs (1)

void setup() {
  Serial.begin(9600);             ///< Start serial communication at 9600 baud
  pinMode(LED_BUILTIN, OUTPUT);   ///< Configure LED pin as output
}

void loop() {
  /**
   * @brief Print "Hello world" once after 1 second has passed.
   */
  if (MyTimer.hasExpired(durationInSec, SECOND, runAmount)) {
    Serial.println("Hello world");
  }

  /**
   * @brief Blink the built-in LED infinitely (with 1 sec durations)
   */
  digitalWrite(LED_BUILTIN, MyTimer.toggledState(durationInSec, SECOND, TimerKernel::INFINITE));
}

