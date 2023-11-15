#include "pomodoro_en/Tpomodoro.h"

#include <iostream>
#include <filesystem>

using namespace std;
using namespace namespace_plapacz6;

Tpomodoro::Tpomodoro(const char* user_home_dir_sz) {

    if(user_home_dir_sz && user_home_dir_sz[0]) {
        filesystem::path path_cfg_fname = user_home_dir_sz;
        path_cfg_fname /= ".pomodoro.config";
        cfg_fname = path_cfg_fname.string();
    }
    else {
        cfg_fname = "";
        cerr << "I can't create cfg file. Using default parameters.\n";
        pomodoro_cfg.set_default_parameters();
    }
}

Tpomodoro::~Tpomodoro() {
}
