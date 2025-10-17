
#include "TimerKernel.h"
#include <Arduino.h>
#include <math.h>


TimerKernel::TimerKernel() : 
    toggleStatePhase(WAIT_MILLIS),
    hasExpiredPhase(WAIT_MILLIS),
    previousMillis_1(0),
    previousMicros_1(0),
    currentMillis_1(0),
    currentMicros_1(0),
    previousMillis_2(0),
    previousMicros_2(0),
    currentMillis_2(0),
    currentMicros_2(0),
    elapsedTime(0),
    state(false) {}


void TimerKernel::resetTimer() {
    this->previousMillis_1 = this->currentMillis_1 = this->previousMillis_2 = this->currentMillis_2 = millis();
    this->previousMicros_1 = this->currentMicros_1 = this->previousMicros_2 = this->currentMicros_2 = micros();
    this->elapsedTime = 0;
    this->state = false;
    this->toggleStatePhase = WAIT_MILLIS;
    this->hasExpiredPhase = WAIT_MILLIS;
}


void TimerKernel::resetToggleState() {
    this->previousMillis_2 = this->currentMillis_2 = millis();
    this->previousMicros_2 = this->currentMicros_2 = micros();
    this->toggleStatePhase = WAIT_MILLIS;
    this->state = false;
}


void TimerKernel::resetHasExpired() {
    this->previousMillis_1 = this->currentMillis_1 = millis();
    this->previousMicros_1 = this->currentMicros_1 = micros();
    this->hasExpiredPhase = WAIT_MILLIS;
}


void TimerKernel::updateCurrentTime() {
    this->currentMillis_1 = this->currentMillis_2 = millis();
    this->currentMicros_1 = this->currentMicros_2 = micros();
}


bool TimerKernel::toggleState(double duration, TimeUnit unit) {

    unsigned long durationInMicros = convertToMicrosecond(duration, unit);
    unsigned long durationInMillis = durationInMicros / 1000UL;
    unsigned long remainingMicros = durationInMicros % 1000UL;

    updateCurrentTime();

    if (durationInMicros == 0) return this->state;

    switch (toggleStatePhase) {
        case WAIT_MILLIS:
            if (this->currentMillis_2 - this->previousMillis_2 >= durationInMillis || durationInMillis == 0) {
                this->previousMillis_2 = millis();
                this->toggleStatePhase = WAIT_MICROS;
            }
            break;
        
        case WAIT_MICROS:
            if (this->currentMicros_2 - this->previousMicros_2 >= remainingMicros || (remainingMicros == 0 && durationInMillis != 0)) {
                this->previousMicros_2 = micros();
                this->state = !this->state;
                this->toggleStatePhase = WAIT_MILLIS;
            }
            break;
    }
    
    return this->state;
}


bool TimerKernel::hasExpired(double duration, TimeUnit unit) {

    unsigned long durationInMicros = convertToMicrosecond(duration, unit);
    unsigned long durationInMillis = durationInMicros / 1000UL;
    unsigned long remainingMicros = durationInMicros % 1000UL;

    updateCurrentTime();

    if (durationInMicros == 0) return false;

    switch (hasExpiredPhase) {
        case WAIT_MILLIS:
            if (this->currentMillis_1 - this->previousMillis_1 >= durationInMillis || durationInMillis == 0) {
                this->previousMillis_1 = millis();
                this->hasExpiredPhase = WAIT_MICROS;
            }
            break;
        
        case WAIT_MICROS:
            if (this->currentMicros_1 - this->previousMicros_1 >= remainingMicros || (remainingMicros == 0 && durationInMillis != 0)) {
                this->previousMicros_1 = micros();
                this->hasExpiredPhase = WAIT_MILLIS;
                return true;
            }
            break;
    }

    return false;
}


unsigned long TimerKernel::convertToMicrosecond(double duration, TimeUnit unit) {
    unsigned long durationInMicros = 0;

    switch (unit) {
    case MINUTE:
        durationInMicros = static_cast<unsigned long>(round(duration * 60000000UL));
        break;

    case SECOND:
        durationInMicros = static_cast<unsigned long>(round(duration * 1000000UL));
        break;

    case MILLISECOND:
        durationInMicros = static_cast<unsigned long>(round(duration * 1000UL));
        break;

    case MICROSECOND:
        durationInMicros = static_cast<unsigned long>(round(duration));
        break;
    };

    return durationInMicros;
}

