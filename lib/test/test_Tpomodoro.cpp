#include <catch2/catch_all.hpp>
#include "pomodoro_en/pomodoro_en.h" 
#include <cstdlib>
#include <filesystem>

using namespace std;

TEST_CASE("pomodoro obj creation") {    

    namespace_plapacz6::Tpomodoro *pom_obj = new namespace_plapacz6::Tpomodoro(getenv("HOME"));
    REQUIRE(pom_obj != nullptr);

    filesystem::path cfg_fname = getenv("HOME");
    cfg_fname /= ".pomodoro.config";

    REQUIRE(pom_obj->cfg_fname == cfg_fname);

    if(pom_obj){
        delete pom_obj;
    }    
};

  //REQUIRE(ptr_pomodoro_state->monitor_callback == ???)
