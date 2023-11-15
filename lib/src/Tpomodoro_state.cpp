#include "pomodoro_en/Tpomodoro_state.h"

using namespace namespace_plapacz6;

void Tpomodoro_state::reset(){
        number_finished_sessions = 0;
        stage = BEFORE_START;
        stage_time = 0;
}
