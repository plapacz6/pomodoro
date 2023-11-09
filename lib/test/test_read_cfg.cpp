#include <catch2/catch_all.hpp>
#include "lib_pomodoro.h" 

TEST_CASE("read_cfg_00") {
    int x;
    REQUIRE(read_cfg(&x) == 29);
    REQUIRE(x == 19);
};