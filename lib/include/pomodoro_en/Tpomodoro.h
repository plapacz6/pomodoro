#ifndef TPOMODORO_H
#define TPOMODORO_H

#include <string>

#include "pomodoro_en/tests_helper_functions.h"
#include "pomodoro_en/Tpomodoro_stage.h"
#include "pomodoro_en/Tmonitoring_callback.h"
#include "pomodoro_en/Tpomodoro_cfg.h"
#include "pomodoro_en/Tpomodoro_state.h"

namespace namespace_plapacz6 {



class Tpomodoro {

public:
    // void run()
    // void pause()
    // void reset()
    void register_monitoring_callback(Tmonitoring_callback_fn monitoring_callback_);
    void set_cfg(int sn, int st, int sbt, int lbt);
    void save_cfg();

    Tpomodoro(const char* user_home_dir_sz);
    ~Tpomodoro();

private:
    std::string cfg_fname;
    Tpomodoro_cfg pomodoro_cfg;
    Tpomodoro_state pomodoro_state;    
    Tmonitoring_callback_fn monitoring_callback;

    friend const std::string get_Tpomodoro_cfg_fname(const Tpomodoro* ptr_pom);
    friend Tmonitoring_callback_fn get_Tpomodoro_monitoring_callback(Tpomodoro *ptr_pom);
    friend Tpomodoro_state get_Tpomodoro_state(const Tpomodoro* ptr_pom);
    friend Tpomodoro_cfg get_Tpomodoro_cfg(const Tpomodoro* ptr_pom);
};

} //namespace namespace_plapacz6 {

#endif // TPOMODORO_H
