#include "pomodoro_en/Tpomodoro.h"
#include <iostream>

using namespace std;
using namespace namespace_plapacz6;

Tpomodoro::Tpomodoro(const char* user_home_dir_sz) {
    user_home_dir = user_home_dir_sz;
    cout << "konstuktor" << __func__ << endl;
}

Tpomodoro::~Tpomodoro(){
    cout << "destruktor" << __func__ << endl;
}

const std::string& Tpomodoro::get_user_home_dir(){
    return user_home_dir;
}