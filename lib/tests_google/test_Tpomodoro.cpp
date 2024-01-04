#include <gtest/gtest.h>
#include <cstdlib>
#include <filesystem>

#include "Tmonitoring_callback.h"
#include "Tpomodoro.h"

using namespace std;
using namespace namespace_plapacz6;

struct monitor_state {
    int pass_sec;
    int fin_ses;
    Tstage monit_stage;

    void reset() {
        pass_sec = 0;
        fin_ses = 0;
        monit_stage = Tstage::BEFORE_START;
    }
    void set(int s, int sn, Tstage ms) {
        pass_sec = s;
        fin_ses = sn;
        monit_stage = ms;
    }
} mon_st;

void pomodoro_monitor(int sec, int fin_ses_nr, Tstage stage){
    mon_st.pass_sec = sec;
    mon_st.fin_ses = fin_ses_nr;
    mon_st.monit_stage = stage;
}
Tmonitoring_callback_fn ptr_pomodoro_monitor;
Tmonitoring_callback_fn ptr_pomodoro_monitor2;

Tpomodoro_test_helper ht;

class TestFixture_Test_Tpomodoro : public testing::Test {
    public:
    void SetUp() override {
        pom_obj = new Tpomodoro(getenv("HOME"));
        ASSERT_TRUE(pom_obj != nullptr);
    }
    void TearDown() override {
        if(pom_obj) {
            delete pom_obj;
        }
    }   

    protected: 
    Tpomodoro *pom_obj;
};


TEST_F(TestFixture_Test_Tpomodoro, pomodoro_obj_1_time_creation) {

    filesystem::path cfg_fname = getenv("HOME");
    cfg_fname /= ".pomodoro.config";

    //removing existing .pomodoro.config file
    if(filesystem::exists(cfg_fname)) {
        ASSERT_TRUE(filesystem::remove(cfg_fname));
    }

    ASSERT_TRUE(ht.get_cfg_fname(pom_obj) == cfg_fname);

    Tpomodoro_cfg pom_cfg = 
        ht.get_cfg(pom_obj);
    ASSERT_TRUE(pom_cfg.sessions_number == (int)4);
    ASSERT_TRUE(pom_cfg.session_time == (int)25);
    ASSERT_TRUE(pom_cfg.short_break_time == (int)5);
    ASSERT_TRUE(pom_cfg.long_break_time == (int)15);

    Tpomodoro_state pom_state = 
        ht.get_state(pom_obj);
    ASSERT_TRUE(pom_state.number_finished_sessions == 0);
    ASSERT_TRUE(pom_state.stage == Tstage::BEFORE_START);
    ASSERT_TRUE(pom_state.stage_time == 0);

    pom_obj->set_cfg(6, 30, 4, 20);
    pom_obj->save_cfg();

}

TEST_F(TestFixture_Test_Tpomodoro, pomodoro_obj_not_first_time_creation) {
    
    Tpomodoro_cfg pom_cfg = 
        ht.get_cfg(pom_obj);
    ASSERT_TRUE(pom_cfg.sessions_number == (int)6);
    ASSERT_TRUE(pom_cfg.session_time == (int)30);
    ASSERT_TRUE(pom_cfg.short_break_time == (int)4);
    ASSERT_TRUE(pom_cfg.long_break_time == (int)20);

    Tpomodoro_state pom_state = 
        ht.get_state(pom_obj);
    ASSERT_TRUE(pom_state.number_finished_sessions == 0);
    ASSERT_TRUE(pom_state.stage == Tstage::BEFORE_START);
    ASSERT_TRUE(pom_state.stage_time == 0);
}

TEST_F(TestFixture_Test_Tpomodoro, register_monitoring_callback) {
    pom_obj->register_monitoring_callback(&pomodoro_monitor);
    ptr_pomodoro_monitor = &pomodoro_monitor;
    ASSERT_TRUE(ptr_pomodoro_monitor == &pomodoro_monitor);        
    ptr_pomodoro_monitor2 = ht.get_monitoring_callback(pom_obj);        

    ASSERT_TRUE(
        ptr_pomodoro_monitor2 == ptr_pomodoro_monitor        
    );
}

TEST_F(TestFixture_Test_Tpomodoro, run_pause_reset) {

    //symulacja uplywu czasu (wewnatrz zykly licznik bez czekania na uplyw czasu)
    //wspolny zegar dla Tpomodoro i systemu testujacego

}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}