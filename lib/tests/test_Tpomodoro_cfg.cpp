#include <catch2/catch_all.hpp>

#include "Tpomodoro_cfg.h"
#include <filesystem>
using namespace std;
using namespace namespace_plapacz6;

TEST_CASE("Tpomodoro_cfg") {
    Tpomodoro_cfg *ptr_pomodoro_cfg = new Tpomodoro_cfg;

    SECTION("create object, set default parameters") {
        REQUIRE(ptr_pomodoro_cfg != nullptr);
        ptr_pomodoro_cfg->set_default_parameters();
        REQUIRE(ptr_pomodoro_cfg->sessions_number == (int)4);
        REQUIRE(ptr_pomodoro_cfg->session_time == (int)25);
        REQUIRE(ptr_pomodoro_cfg->short_break_time == (int)5);
        REQUIRE(ptr_pomodoro_cfg->long_break_time == (int)15);
    }

    SECTION("write and read parameters") {

        filesystem::path cfg_fname = getenv("HOME");
        cfg_fname /= ".pomodoro.config";

        Tpomodoro_cfg *ptr_pomodoro_cfg = new Tpomodoro_cfg;

        REQUIRE(ptr_pomodoro_cfg != nullptr);
        ptr_pomodoro_cfg->set_default_parameters();

        ptr_pomodoro_cfg->write_cfg(cfg_fname);

        ptr_pomodoro_cfg->sessions_number = 0;
        ptr_pomodoro_cfg->session_time = 0;
        ptr_pomodoro_cfg->short_break_time = 0;
        ptr_pomodoro_cfg->long_break_time = 0;

        ptr_pomodoro_cfg->read_cfg(cfg_fname);

        REQUIRE(ptr_pomodoro_cfg->sessions_number == (int)4);
        REQUIRE(ptr_pomodoro_cfg->session_time == (int)25);
        REQUIRE(ptr_pomodoro_cfg->short_break_time == (int)5);
        REQUIRE(ptr_pomodoro_cfg->long_break_time == (int)15);

        if(ptr_pomodoro_cfg) {
            delete ptr_pomodoro_cfg;
        }
    }

    if(ptr_pomodoro_cfg) {
        delete ptr_pomodoro_cfg;
    }
};
