#include <catch2/catch_all.hpp>
#include "pomodoro_en/Tpomodoro_cfg.h"

TEST_CASE("create object, set default parameters") {
    namespace_plapacz6::Tpomodoro_cfg *ptr_pomodoro_cfg = new namespace_plapacz6::Tpomodoro_cfg;

    REQUIRE(ptr_pomodoro_cfg != nullptr);
    ptr_pomodoro_cfg->set_default_parameters();
    REQUIRE(ptr_pomodoro_cfg->sessions_number == (int)4);
    REQUIRE(ptr_pomodoro_cfg->session_time == (int)25);
    REQUIRE(ptr_pomodoro_cfg->short_break_time == (int)5);
    REQUIRE(ptr_pomodoro_cfg->long_break_time == (int)15);

    if(ptr_pomodoro_cfg) {
        delete ptr_pomodoro_cfg;
    }
};
