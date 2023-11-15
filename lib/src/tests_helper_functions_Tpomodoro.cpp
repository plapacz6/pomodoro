#include "pomodoro_en/tests_helper_functions.h"
#include "pomodoro_en/Tpomodoro.h"

using namespace std;
namespace namespace_plapacz6 {

const std::string get_Tpomodoro_cfg_fname(const Tpomodoro* ptr_pom)
{
    return ptr_pom->cfg_fname;
}

Tpomodoro_state get_Tpomodoro_state(const Tpomodoro* ptr_pom)
{
    return ptr_pom->pomodoro_state;
}

Tpomodoro_cfg get_Tpomodoro_cfg(const Tpomodoro* ptr_pom)
{
    return ptr_pom->pomodoro_cfg;
}

} //namespace namespace_plapacz6 {