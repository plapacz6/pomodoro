#ifndef TESTS_HELPER_FUNCTIONS_H
#define TESTS_HELPER_FUNCTIONS_H

#include <string>
#include "pomodoro_en/Tpomodoro_stage.h"
#include "Tmonitoring_callback.h"

namespace namespace_plapacz6 {
class Tpomodoro;
class Tpomodoro_cfg;
class Tpomodoro_state;

class Tpomodoro_test_helper {
    public:
    const std::string get_cfg_fname(const Tpomodoro* ptr_pom);
    Tpomodoro_state get_state(const Tpomodoro* ptr_pom);
    Tpomodoro_cfg get_cfg(const Tpomodoro* ptr_pom);
    Tmonitoring_callback_fn get_monitoring_callback(Tpomodoro *ptr_pom);

    friend class Tpomodoro;
    friend class Tpomodoro_cfg;
    friend class Tpomodoro_state;
};

}

#endif // TESTS_HELPER_FUNCTIONS_H