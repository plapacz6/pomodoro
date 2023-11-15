#include <catch2/catch_all.hpp>
#include "pomodoro_en/Tpomodoro_state.h"

using namespace std;

TEST_CASE("Tpomodoro_state") {

    namespace_plapacz6::Tpomodoro_state *ptr_pomodoro_state = 
        new namespace_plapacz6::Tpomodoro_state();
    REQUIRE(ptr_pomodoro_state != nullptr);

    SECTION("create, reset()") {


        ptr_pomodoro_state->number_finished_sessions = 4;
        ptr_pomodoro_state->stage = namespace_plapacz6::Tpomodoro_state::AFTER_END;
        ptr_pomodoro_state->stage_time = 15;

        ptr_pomodoro_state->reset();

        REQUIRE(ptr_pomodoro_state->number_finished_sessions == 0);
        REQUIRE(ptr_pomodoro_state->stage == namespace_plapacz6::Tpomodoro_state::BEFORE_START);
        REQUIRE(ptr_pomodoro_state->stage_time == 0);
    }
  
    if(ptr_pomodoro_state) {
        delete ptr_pomodoro_state;
    }
};