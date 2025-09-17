
#include "TimerKernel.h"
#include <Arduino.h>
#include <math.h>

TimerKernel::TimerKernel() {
    this->toggleStatePhase = WAIT_MILLIS;
    this->hasExpiredPhase = WAIT_MILLIS;
    this->state = false;
    this->previousMillis = 0;
    this->previousMicros = 0;
    this->currentMicros = 0;
    this->currentMillis = 0;
    this->elapsedTime = 0;
}


void TimerKernel::resetTimer() {
    this->previousMillis = this->currentMillis = millis();
    this->previousMicros = this->currentMicros = micros();
    this->elapsedTime = 0;
    this->state = false;
    this->toggleStatePhase = WAIT_MILLIS;
    this->hasExpiredPhase = WAIT_MILLIS;
}


void TimerKernel::updateCurrentTime() {
    this->currentMillis = millis();
    this->currentMicros = micros();
}


bool TimerKernel::toggleState(long double duration, TimeUnit unit) {

    unsigned long durationInMicros = convertToMicrosecond(duration, unit);
    unsigned long durationInMillis = durationInMicros / 1000UL;
    unsigned long remainingMicros = durationInMicros % 1000UL;

    updateCurrentTime();

    if (remainingMicros == 0 && durationInMillis == 0) return this->state;

    switch (toggleStatePhase) {
        case WAIT_MILLIS:
            if (this->currentMillis - this->previousMillis >= durationInMillis || durationInMillis == 0) {
                this->previousMillis = millis();
                this->toggleStatePhase = WAIT_MICROS;
            }
            break;
        
        case WAIT_MICROS:
            if (this->currentMicros - this->previousMicros >= remainingMicros || (remainingMicros == 0 && durationInMillis != 0)) {
                this->previousMicros = micros();
                this->state = !this->state;
                this->toggleStatePhase = WAIT_MILLIS;
            }
            break;
    }
    
    return this->state;
}


bool TimerKernel::hasExpired(long double duration, TimeUnit unit) {

    unsigned long durationInMicros = convertToMicrosecond(duration, unit);
    unsigned long durationInMillis = durationInMicros / 1000UL;
    unsigned long remainingMicros = durationInMicros % 1000UL;

    updateCurrentTime();

    if (remainingMicros == 0 && durationInMillis == 0) return false;

    switch (hasExpiredPhase) {
        case WAIT_MILLIS:
            if (this->currentMillis - this->previousMillis >= durationInMillis || durationInMillis == 0) {
                this->previousMillis = millis();
                this->hasExpiredPhase = WAIT_MICROS;
            }
            break;
        
        case WAIT_MICROS:
            if (this->currentMicros - this->previousMicros >= remainingMicros || (remainingMicros == 0 && durationInMillis != 0)) {
                this->previousMicros = micros();
                this->hasExpiredPhase = WAIT_MILLIS;
                return true;
            }
            break;
    }

    return false;
}


unsigned long TimerKernel::convertToMicrosecond(long double duration, TimeUnit unit) {
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


