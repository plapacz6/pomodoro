#include <catch2/catch_all.hpp>
#include "pomodoro_en/Tpomodoro.h"
#include <cstdlib>
#include <filesystem>

using namespace std;

TEST_CASE("Tpomodoro") {

    namespace_plapacz6::Tpomodoro *pom_obj = new namespace_plapacz6::Tpomodoro(getenv("HOME"));
    REQUIRE(pom_obj != nullptr);

    SECTION("pomodoro obj 1 time creation") {

        filesystem::path cfg_fname = getenv("HOME");
        cfg_fname /= ".pomodoro.config";

        //removing existing .pomodoro.config file
        if(filesystem::exists(cfg_fname)) {
            REQUIRE(filesystem::remove(cfg_fname));
        }

        REQUIRE(get_Tpomodoro_cfg_fname(pom_obj) == cfg_fname);

        namespace_plapacz6::Tpomodoro_cfg pom_cfg = get_Tpomodoro_cfg(pom_obj);
        REQUIRE(pom_cfg.sessions_number == (int)4);
        REQUIRE(pom_cfg.session_time == (int)25);
        REQUIRE(pom_cfg.short_break_time == (int)5);
        REQUIRE(pom_cfg.long_break_time == (int)15);

        namespace_plapacz6::Tpomodoro_state pom_state = get_Tpomodoro_state(pom_obj);
        REQUIRE(pom_state.number_finished_sessions == 0);
        REQUIRE(pom_state.stage == namespace_plapacz6::Tpomodoro_state::BEFORE_START);
        REQUIRE(pom_state.stage_time == 0);

    }

    SECTION("pomodoro obj not first time creation") {

    }

    SECTION("register monitoring callback") {

    }

    SECTION("run, pause, reset") {

    }

    if(pom_obj) {
        delete pom_obj;
    }
};

//REQUIRE(ptr_pomodoro_state->monitor_callback == ???)
