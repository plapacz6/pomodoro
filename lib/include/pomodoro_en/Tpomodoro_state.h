#ifndef TPOMODORO_STATE_H
#define TPOMODORO_STATE_H

#include "pomodoro_en/tests_helper_functions.h"

namespace namespace_plapacz6 {

struct Tpomodoro_state {
    enum Tpomodoro_stage {BEFORE_START, SESSION, SHORT_BREAK, LONG_BREAK, AFTER_END};

    int number_finished_sessions;
    Tpomodoro_stage stage;
    int stage_time;

    void reset();
};

} //namespace namespace_plapacz6 {

#endif // TPOMODORO_STATE_H