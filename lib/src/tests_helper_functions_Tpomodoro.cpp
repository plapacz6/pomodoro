#include "pomodoro_en/tests_helper_functions.h"
#include "pomodoro_en/Tpomodoro_stage.h"
#include "pomodoro_en/Tmonitoring_callback.h"
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

Tmonitoring_callback_fn get_Tpomodoro_monitoring_callback(Tpomodoro *ptr_pom)
{

    /*
    conversion from
    void (* (*)(namespace_plapacz6::Tpomodoro*))
        (int, int, namespace_plapacz6::Tpomodoro_stage)
    ’ to ‘namespace_plapacz6::Tmonitoring_callback_fn’ {aka ‘
    void (*)
        (int, int, namespace_plapacz6::Tpomodoro_stage)
    ’
    */
    // Tmonitoring_callback_fn mon_callb = 
    //     reinterpret_cast<
    //         //Tmonitoring_callback_fn
    //         void (*)(int, int, namespace_plapacz6::Tpomodoro_stage)
    //     >
    //     (ptr_pom->monitoring_callback);

    // return mon_callb;
    return ptr_pom->monitoring_callback;
}

} //namespace namespace_plapacz6 {