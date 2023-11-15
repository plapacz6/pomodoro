#include <catch2/catch_all.hpp>
#include "pomodoro_en/Tpomodoro.h" 
#include <cstdlib>
#include <filesystem>

using namespace std;

TEST_CASE("Tpomodoro") {


    namespace_plapacz6::Tpomodoro *pom_obj = new namespace_plapacz6::Tpomodoro(getenv("HOME"));
    REQUIRE(pom_obj != nullptr);

    SECTION("pomodoro obj creation") {    

        filesystem::path cfg_fname = getenv("HOME");
        cfg_fname /= ".pomodoro.config";

        REQUIRE(get_Tpomodoro_cfg_fname(pom_obj) == cfg_fname);


    }

    SECTION("register monitoring callback") {

    }

    SECTION("run, pause, reset") {

    }

    if(pom_obj){
        delete pom_obj;
    }        
};

  //REQUIRE(ptr_pomodoro_state->monitor_callback == ???)
