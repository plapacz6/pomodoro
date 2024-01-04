#ifndef POMODORO_EN_TMONITORING_CALLBACK_H
#define POMODORO_EN_TMONITORING_CALLBACK_H


namespace namespace_plapacz6 {
class Tpomodoro_stage;
enum class Tstage;

/// @brief 
typedef     
    void (*Tmonitoring_callback_fn)(
        int pass_seconds, int finished_session_nr, Tstage stage);

} // namespace namespace_plapacz6 {

#endif // POMODORO_EN_TMONITORING_CALLBACK_H    
