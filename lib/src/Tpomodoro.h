#ifndef TPOMODORO_H
#define TPOMODORO_H

#include <string>

#include "tests_helper_functions.h"

#include "Tmonitoring_callback.h"
#include "Tpomodoro_cfg.h"
#include "Tpomodoro_state.h"

namespace namespace_plapacz6 {



class Tpomodoro {

public:
    void run();
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

    friend class Tpomodoro_test_helper;
    // friend const std::string get_cfg_fname(const Tpomodoro* ptr_pom);
    // friend Tmonitoring_callback_fn get_monitoring_callback(Tpomodoro *ptr_pom);
    // friend Tpomodoro_state get_state(const Tpomodoro* ptr_pom);
    // friend Tpomodoro_cfg get_cfg(const Tpomodoro* ptr_pom);
};

} //namespace namespace_plapacz6 {

#endif // TPOMODORO_H
