#include <catch2/catch_all.hpp>
#include <cstdlib>
#include <filesystem>
#include "pomodoro_en/Tpomodoro_stage.h"
#include "pomodoro_en/Tmonitoring_callback.h"
#include "pomodoro_en/Tpomodoro.h"

using namespace std;
using namespace namespace_plapacz6;

struct monitor_state {
    int pass_sec;
    int fin_ses;
    Tpomodoro_stage monit_stage;

    void reset() {
        pass_sec = 0;
        fin_ses = 0;
        monit_stage = Tpomodoro_stage::BEFORE_START;
    }
    void set(int s, int sn, Tpomodoro_stage ms) {
        pass_sec = s;
        fin_ses = sn;
        monit_stage = ms;
    }
} mon_st;

void pomodoro_monitor(int sec, int fin_ses_nr, Tpomodoro_stage stage){
    mon_st.pass_sec = sec;
    mon_st.fin_ses = fin_ses_nr;
    mon_st.monit_stage = stage;
}
Tmonitoring_callback_fn ptr_pomodoro_monitor;
Tmonitoring_callback_fn ptr_pomodoro_monitor2;

TEST_CASE("Tpomodoro") {

    Tpomodoro *pom_obj = new Tpomodoro(getenv("HOME"));
    REQUIRE(pom_obj != nullptr);

    SECTION("pomodoro obj 1 time creation") {

        filesystem::path cfg_fname = getenv("HOME");
        cfg_fname /= ".pomodoro.config";

        //removing existing .pomodoro.config file
        if(filesystem::exists(cfg_fname)) {
            REQUIRE(filesystem::remove(cfg_fname));
        }

        REQUIRE(get_Tpomodoro_cfg_fname(pom_obj) == cfg_fname);

        Tpomodoro_cfg pom_cfg = 
            get_Tpomodoro_cfg(pom_obj);
        REQUIRE(pom_cfg.sessions_number == (int)4);
        REQUIRE(pom_cfg.session_time == (int)25);
        REQUIRE(pom_cfg.short_break_time == (int)5);
        REQUIRE(pom_cfg.long_break_time == (int)15);

        Tpomodoro_state pom_state = 
            get_Tpomodoro_state(pom_obj);
        REQUIRE(pom_state.number_finished_sessions == 0);
        REQUIRE(pom_state.stage == Tpomodoro_stage::BEFORE_START);
        REQUIRE(pom_state.stage_time == 0);

        pom_obj->set_cfg(6, 30, 4, 20);
        pom_obj->save_cfg();

    }

    SECTION("pomodoro obj not first time creation") {
        
        Tpomodoro_cfg pom_cfg = 
            get_Tpomodoro_cfg(pom_obj);
        REQUIRE(pom_cfg.sessions_number == (int)6);
        REQUIRE(pom_cfg.session_time == (int)30);
        REQUIRE(pom_cfg.short_break_time == (int)4);
        REQUIRE(pom_cfg.long_break_time == (int)20);

        Tpomodoro_state pom_state = 
            get_Tpomodoro_state(pom_obj);
        REQUIRE(pom_state.number_finished_sessions == 0);
        REQUIRE(pom_state.stage == Tpomodoro_stage::BEFORE_START);
        REQUIRE(pom_state.stage_time == 0);
    }

    SECTION("register monitoring callback") {
        pom_obj->register_monitoring_callback(&pomodoro_monitor);
        ptr_pomodoro_monitor = &pomodoro_monitor;
        REQUIRE(ptr_pomodoro_monitor == &pomodoro_monitor);        
        ptr_pomodoro_monitor2 = get_Tpomodoro_monitoring_callback(pom_obj);        

        REQUIRE(
            ptr_pomodoro_monitor2 == ptr_pomodoro_monitor        
        );
    }

    SECTION("run, pause, reset") {

    }

    if(pom_obj) {
        delete pom_obj;
    }
};

