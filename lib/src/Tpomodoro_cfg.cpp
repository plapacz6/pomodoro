#include "pomodoro_en/Tpomodoro_cfg.h"

using namespace namespace_plapacz6;

Tpomodoro_cfg::Tpomodoro_cfg(){

}
Tpomodoro_cfg::~Tpomodoro_cfg(){

}
void Tpomodoro_cfg::set_default_parameters(){
    sessions_number = 4;
    session_time = 25;
    short_break_time = 5;
    long_break_time = 15;
}