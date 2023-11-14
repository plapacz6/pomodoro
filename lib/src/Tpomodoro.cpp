#include "pomodoro_en/pomodoro_en.h"
//#include "pomodoro_en/Tpomodoro.h"
#include <iostream>
#include <filesystem>

using namespace std;
using namespace namespace_plapacz6;

Tpomodoro::Tpomodoro(const char* user_home_dir_sz) {
    
    //user_home_dir = user_home_dir_sz;

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

    cout << "konstuktor" << __func__ << endl;
}

Tpomodoro::~Tpomodoro(){
    cout << "destruktor" << __func__ << endl;
}

// const std::string& Tpomodoro::get_user_home_dir(){
//     return user_home_dir;
// }