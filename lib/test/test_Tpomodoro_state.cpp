#include <catch2/catch_all.hpp>
#include "pomodoro_en/Tpomodoro_stage.h"
#include "pomodoro_en/Tpomodoro_state.h"

using namespace std;
using namespace namespace_plapacz6;

TEST_CASE("Tpomodoro_state") {

    Tpomodoro_state *ptr_pomodoro_state =
        new Tpomodoro_state();
    REQUIRE(ptr_pomodoro_state != nullptr);

    SECTION("create, reset()") {

        ptr_pomodoro_state->number_finished_sessions = 4;
        ptr_pomodoro_state->stage = Tpomodoro_stage::AFTER_END;
        ptr_pomodoro_state->stage_time = 15;

        ptr_pomodoro_state->reset();

        REQUIRE(ptr_pomodoro_state->number_finished_sessions == 0);
        REQUIRE(ptr_pomodoro_state->stage == Tpomodoro_stage::BEFORE_START);
        REQUIRE(ptr_pomodoro_state->stage_time == 0);
    }

    if(ptr_pomodoro_state) {
        delete ptr_pomodoro_state;
    }
};