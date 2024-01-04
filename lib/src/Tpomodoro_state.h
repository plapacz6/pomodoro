#ifndef TPOMODORO_STATE_H
#define TPOMODORO_STATE_H

#include "Tpomodoro_stage.h"
#include "tests_helper_functions.h"

namespace namespace_plapacz6 {

struct Tpomodoro_state {
    
    int number_finished_sessions;
    Tpomodoro_stage stage;
    int stage_time;

    void reset();
};

} //namespace namespace_plapacz6 {

#endif // TPOMODORO_STATE_H