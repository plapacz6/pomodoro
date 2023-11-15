#ifndef POMODORO_STATE_H
#define POMODORO_STATE_H

namespace namespace_plapacz6 {
    struct Tpomodoro_state {
        enum Tpomodoro_stage {BEFORE_START, SESSION, SHORT_BREAK, LONG_BREAK, AFTER_END};

        int number_finished_sessions;
        Tpomodoro_stage stage;
        int stage_time;

        void reset();
    }; 
}

#endif // POMODORO_STATE_H