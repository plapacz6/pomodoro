#include <gtest/gtest.h>

#include "Tpomodoro_state.h"

using namespace std;
using namespace namespace_plapacz6;

TEST(TestSuite_Tpomodoro_state, Test_Tpomodoro_state_create_reset) {

    Tpomodoro_state *ptr_pomodoro_state =
        new Tpomodoro_state();
    ASSERT_TRUE(ptr_pomodoro_state != nullptr);

    //("create, reset()") 

    ptr_pomodoro_state->number_finished_sessions = 4;
    ptr_pomodoro_state->stage = Tstage::AFTER_END;
    ptr_pomodoro_state->stage_time = 15;

    ptr_pomodoro_state->reset();

    ASSERT_TRUE(ptr_pomodoro_state->number_finished_sessions == 0);
    ASSERT_TRUE(ptr_pomodoro_state->stage == Tstage::BEFORE_START);
    ASSERT_TRUE(ptr_pomodoro_state->stage_time == 0);


    if(ptr_pomodoro_state) {
        delete ptr_pomodoro_state;
    }
};

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}