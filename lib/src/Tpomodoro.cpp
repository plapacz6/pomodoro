#include "Tpomodoro.h"

#include <cassert>
#include <iostream>
#include <filesystem>

using namespace std;
namespace namespace_plapacz6 {

Tpomodoro::Tpomodoro(const char* user_home_dir_sz) {

    if(user_home_dir_sz && user_home_dir_sz[0]) {
        filesystem::path path_cfg_fname = user_home_dir_sz;
        path_cfg_fname /= ".pomodoro.config";
        cfg_fname = path_cfg_fname.string();
        pomodoro_cfg.read_cfg(cfg_fname);
        pomodoro_state.reset();
    }
    else {
        cfg_fname = "";
        cerr << "I can't using cfg file. Using default parameters.\n";
        pomodoro_cfg.set_default_parameters();
    }
}

Tpomodoro::~Tpomodoro() {
    if(cfg_fname != "") {
        pomodoro_cfg.write_cfg(cfg_fname);
    }
}


void Tpomodoro::set_cfg(int sn, int st, int sbt, int lbt) {
    pomodoro_cfg.sessions_number = sn;
    pomodoro_cfg.session_time = st;
    pomodoro_cfg.short_break_time = sbt;
    pomodoro_cfg.long_break_time = lbt;
}


void Tpomodoro::save_cfg() {
    pomodoro_cfg.write_cfg(cfg_fname);
}

void Tpomodoro::register_monitoring_callback(Tmonitoring_callback_fn monitoring_callback_){
    monitoring_callback = monitoring_callback_;
    assert(monitoring_callback == monitoring_callback_);
}

} //namespace namespace_plapacz6 {
