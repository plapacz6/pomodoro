#include "Tclock.h"

void Tclock::step() {
    sec++;
    if(sec > 59) {
        sec = 0;
        min++;
        if(min > 59) {
            min = 0;
        }
    }
}

unsigned Tclock::getSec() {
    return sec;
}

unsigned Tclock::getMin() {
    return min;
}

void Tclock::reset() {
    sec = 0;
    min = 0;
}