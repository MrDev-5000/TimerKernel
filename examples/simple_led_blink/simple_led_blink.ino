/**
 * @brief Example sketch for blinking the built-in LED using toggleState() 
 * @param duration in desired unit
 *
 * This example sketch demonstrates how to use the TimerKernel library to toggle the 
 * state of the built in led at regular time intervals.
 *
 * The duration can be specified in minutes, seconds, milliseconds or microseconds.
 * Uncomment the desired line in the loop() function to use a particular time unit.
 */

#include <TimerKernel.h>

TimerKernel MyTimer;  

// 1 sec duration in different formats
const double durationInMins = 1.0/60.0;
const long durationInSec = 1;
const long durationInMillisec = 1000;   
const long durationInMicrosec = 1000000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);   ///< Set built-in LED as output
}

void loop() {
  /**
  * @brief change the state of built-in LED every second
  * You can use any of the following formats
  * Only one of the following formats should be used at a time, Uncomment the desired line
  */ 

  //digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInMins, MINUTE));     ///< Toggle built-in LED state every 1/60 minute (1 second)

  //digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInSec, SECOND));     ///< Toggle built-in LED state every 1 second

  digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInMillisec));     ///<  Toggle built-in LED state every 1000 ms (1 second)

  //digitalWrite(LED_BUILTIN, MyTimer.toggleState(durationInMicrosec, MICROSECOND));     ///< Toggle built-in LED state every 1,000,000 us (1 second)

}

