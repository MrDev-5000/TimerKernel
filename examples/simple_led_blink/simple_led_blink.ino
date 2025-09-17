/**
 * @brief Toggles state every given duration
 * @param Duration in milliseconds, microseconds or seconds
 */

#include <TimerKernel.h>

TimerKernel MyTimer;  

// 1 sec duration in different formats
const double durationInMins = 1.0/60.0;
const long durationInSec = 1;
const long durationInMillisec = 1000;   
const long durationInMicrosec = 1000000;

void setup() {
  // Set LED_BUILTIN as an output pin
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  /// change the state of LED_BUILTIN every second
  // You can use any of the following formats
  // Uncomment only one of them

  //digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInMins, MINUTE));

  ///or

  //digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInSec, SECOND));

  ///or

  digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInMillisec));  //  is same as digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInMillisec, MILLISECOND));

  ///or

  //digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInMicrosec, MICROSECOND));

  
}
