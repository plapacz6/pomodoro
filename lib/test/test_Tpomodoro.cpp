#include <catch2/catch_all.hpp>
#include "pomodoro_en/pomodoro_en.h" 
#include <cstdlib>

using namespace std;

TEST_CASE("pomodoro obj creation") {    

    namespace_plapacz6::Tpomodoro *pom_obj = new namespace_plapacz6::Tpomodoro(getenv("HOME"));
    REQUIRE(pom_obj != nullptr);

    REQUIRE(pom_obj->get_user_home_dir() == string(getenv("HOME")));

    if(pom_obj){
        delete pom_obj;
    }    
};


