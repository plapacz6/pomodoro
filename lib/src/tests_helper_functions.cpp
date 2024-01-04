#include "tests_helper_functions.h"
#include "Tpomodoro_stage.h"
#include "Tmonitoring_callback.h"
#include "Tpomodoro.h"

using namespace std;
namespace namespace_plapacz6 {

const std::string Tpomodoro_test_helper::get_cfg_fname(const Tpomodoro* ptr_pom)
{
    return ptr_pom->cfg_fname;
}

Tpomodoro_state Tpomodoro_test_helper::get_state(const Tpomodoro* ptr_pom)
{
    return ptr_pom->pomodoro_state;
}

Tpomodoro_cfg Tpomodoro_test_helper::get_cfg(const Tpomodoro* ptr_pom)
{
    return ptr_pom->pomodoro_cfg;
}

Tmonitoring_callback_fn Tpomodoro_test_helper::get_monitoring_callback(Tpomodoro *ptr_pom)
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