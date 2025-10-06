#pragma once
#ifndef TIMERKERNEL_H
#define TIMERKERNEL_H

#include <Arduino.h>


enum TimeUnit {
    MINUTE,
    SECOND,
    MILLISECOND,
    MICROSECOND
};

class TimerKernel {
private:
    enum TimerPhase {
        WAIT_MILLIS,
        WAIT_MICROS
    };

    TimerPhase toggleStatePhase;
    TimerPhase hasExpiredPhase;
    unsigned long previousMillis_1;
    unsigned long previousMicros_1;
    unsigned long currentMillis_1;
    unsigned long currentMicros_1;
    unsigned long previousMillis_2;
    unsigned long previousMicros_2;
    unsigned long currentMillis_2;
    unsigned long currentMicros_2;
    unsigned long elapsedTime;
    bool state;

public:
    TimerKernel();
    void resetTimer();
    void resetToggleState();
    void resetHasExpired();
    bool toggleState(double duration, TimeUnit unit = MILLISECOND);
    bool hasExpired(double duration, TimeUnit unit = MILLISECOND);

private:
    void updateCurrentTime();
    unsigned long convertToMicrosecond(double duration, TimeUnit unit);

};


#endif 



