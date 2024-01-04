#ifndef POMODORO_EN_TMONITORING_CALLBACK_H
#define POMODORO_EN_TMONITORING_CALLBACK_H

#include "Tpomodoro_stage.h"

namespace namespace_plapacz6 {

/// @brief 
typedef     
    void (*Tmonitoring_callback_fn)(
        int pass_seconds, int finished_session_nr, Tpomodoro_stage stage);

} // namespace namespace_plapacz6 {

#endif // POMODORO_EN_TMONITORING_CALLBACK_H    
