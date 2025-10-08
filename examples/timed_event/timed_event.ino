/**
 * @brief Example sketch for doing a task using hasExpired() 
 * @param duration in desired unit
 *
 * This example sketch demonstrates how to use the TimerKernel library to do a 
 * periodically without using delay()
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
  Serial.begin(9600);   ///< Start serial communication at 9600 baud
}

void loop() {
  /**
  * @brief perform a task every second
  * You can use any of the following formats
  * Only one of the following formats should be used at a time, Uncomment the desired line
  */ 

  // if (MyTimer.hasExpired(durationInMins, MINUTE)) {             ///< do something every 1/60 minute (1 second)
  //   Serial.println("1 second has passed");
  // }

  // if (MyTimer.hasExpired(durationInSec, SECOND)) {              ///< do something state every 1 second
  //   Serial.println("1 second has passed");
  // }

  if (MyTimer.hasExpired(durationInMillisec)) {                    ///<  do something every 1000 ms (1 second)
    Serial.println("1 second has passed");
  }

  // if (MyTimer.hasExpired(durationInMicrosec, MICROSECOND)) {    ///< do something every 1,000,000 us (1 second)
  //   Serial.println("1 second has passed");
  // }

}
