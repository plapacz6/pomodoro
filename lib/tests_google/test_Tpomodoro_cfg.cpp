#include <gtest/gtest.h>
#include "Tpomodoro_cfg.h"
#include <filesystem>

using namespace std;
using namespace namespace_plapacz6;

class TestFixture_Test_cfg : public testing::Test {
    public:
    // void SetUp() override {
    //     ptr_pomodoro_cfg = new Tpomodoro_cfg;
    // }
    // void TearDown() override {
    //     if(ptr_pomodoro_cfg) {
    //        delete ptr_pomodoro_cfg;   
    //     }       
    // }   

    protected: 
    //Tpomodoro_cfg *ptr_pomodoro_cfg;
};

TEST_F(TestFixture_Test_cfg, Test_Tpomodoro_cfg_create_obj_and_set_def_param) {
    
    //"create object, set default parameters")
    Tpomodoro_cfg *ptr_pomodoro_cfg = new Tpomodoro_cfg;

    ASSERT_TRUE(ptr_pomodoro_cfg != nullptr);
    ptr_pomodoro_cfg->set_default_parameters();
    ASSERT_TRUE(ptr_pomodoro_cfg->sessions_number == (int)4);
    ASSERT_TRUE(ptr_pomodoro_cfg->session_time == (int)25);
    ASSERT_TRUE(ptr_pomodoro_cfg->short_break_time == (int)5);
    ASSERT_TRUE(ptr_pomodoro_cfg->long_break_time == (int)15);
    if(ptr_pomodoro_cfg) {
        delete ptr_pomodoro_cfg;
    }        
}

TEST_F(TestFixture_Test_cfg, Test_Tpomodoro_cfg_write_and_read_param) {
    //"write and read parameters") 

    filesystem::path cfg_fname = getenv("HOME");
    cfg_fname /= ".pomodoro.config";

    Tpomodoro_cfg *ptr_pomodoro_cfg = new Tpomodoro_cfg;

    ASSERT_TRUE(ptr_pomodoro_cfg != nullptr);
    ptr_pomodoro_cfg->set_default_parameters();

    ptr_pomodoro_cfg->write_cfg(cfg_fname);

    ptr_pomodoro_cfg->sessions_number = 0;
    ptr_pomodoro_cfg->session_time = 0;
    ptr_pomodoro_cfg->short_break_time = 0;
    ptr_pomodoro_cfg->long_break_time = 0;

    ptr_pomodoro_cfg->read_cfg(cfg_fname);

    ASSERT_TRUE(ptr_pomodoro_cfg->sessions_number == (int)4);
    ASSERT_TRUE(ptr_pomodoro_cfg->session_time == (int)25);
    ASSERT_TRUE(ptr_pomodoro_cfg->short_break_time == (int)5);
    ASSERT_TRUE(ptr_pomodoro_cfg->long_break_time == (int)15);

    if(ptr_pomodoro_cfg) {
        delete ptr_pomodoro_cfg;
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
