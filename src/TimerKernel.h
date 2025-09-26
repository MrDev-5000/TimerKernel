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
    unsigned long previousMillis;
    unsigned long previousMicros;
    unsigned long currentMillis;
    unsigned long currentMicros;
    unsigned long elapsedTime;
    bool state;

public:
    TimerKernel();
    void resetTimer();
    bool toggleState(double duration, TimeUnit unit = MILLISECOND);
    bool hasExpired(double duration, TimeUnit unit = MILLISECOND);

private:
    void updateCurrentTime();
    unsigned long convertToMicrosecond(double duration, TimeUnit unit);

};


#endif 




