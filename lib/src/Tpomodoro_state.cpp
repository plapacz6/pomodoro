#include "pomodoro_en/Tpomodoro_state.h"
#include "pomodoro_en/Tpomodoro_stage.h"

namespace namespace_plapacz6 {

void Tpomodoro_state::reset() {
    number_finished_sessions = 0;
    stage = Tpomodoro_stage::BEFORE_START;
    stage_time = 0;
}

} //namespace namespace_plapacz6 {