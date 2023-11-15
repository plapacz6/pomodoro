#ifndef TESTS_HELPER_FUNCTIONS_H
#define TESTS_HELPER_FUNCTIONS_H

#include <string>

namespace namespace_plapacz6 {
class Tpomodoro;
class Tpomodoro_cfg;
class Tpomodoro_state;

const std::string get_Tpomodoro_cfg_fname(const Tpomodoro* ptr_pom);
Tpomodoro_state get_Tpomodoro_state(const Tpomodoro* ptr_pom);
Tpomodoro_cfg get_Tpomodoro_cfg(const Tpomodoro* ptr_pom);
}

#endif // TESTS_HELPER_FUNCTIONS_H