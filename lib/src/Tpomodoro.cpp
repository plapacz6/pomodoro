#include "pomodoro_en/Tpomodoro.h"

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

} //namespace namespace_plapacz6 {
