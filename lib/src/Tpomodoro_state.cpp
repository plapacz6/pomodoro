#include "pomodoro_en.h"
#include "Tpomodoro_state.h"


namespace namespace_plapacz6 {

void Tpomodoro_state::reset() {
    number_finished_sessions = 0;
    stage = Tstage::BEFORE_START;
    stage_time = 0;
}

} //namespace namespace_plapacz6 {