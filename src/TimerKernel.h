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

    unsigned long previousMillis;
    unsigned long previousMicros;
    unsigned long currentMillis;
    unsigned long currentMicros;
    unsigned long elapsedTime;
    bool state;
    TimerPhase toggleStatePhase;
    TimerPhase hasExpiredPhase;

public:
    TimerKernel();
    void resetTimer();
    bool toggleState(long double duration, TimeUnit unit = MILLISECOND);
    bool hasExpired(long double duration, TimeUnit unit = MILLISECOND);

private:
    void updateCurrentTime();
    unsigned long convertToMicrosecond(long double duration, TimeUnit unit);

};


#endif 




