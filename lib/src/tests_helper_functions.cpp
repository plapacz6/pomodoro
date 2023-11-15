#include "pomodoro_en/tests_helper_functions.h"
#include "pomodoro_en/Tpomodoro.h"

using namespace std;
using namespace namespace_plapacz6;

//const std::string get_Tpomodoro_cfg_fname(const Tpomodoro* ptr_pom) {
const std::string namespace_plapacz6::get_Tpomodoro_cfg_fname(const Tpomodoro *ptr_pom) {
    return ptr_pom->cfg_fname;
}