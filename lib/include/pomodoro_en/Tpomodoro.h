#ifndef TPOMODORO_H
#define TPOMODORO_H

#include <string>

#include "pomodoro_en/tests_helper_functions.h"

#include "pomodoro_en/Tpomodoro_cfg.h"
#include "pomodoro_en/Tpomodoro_state.h"

namespace namespace_plapacz6 {
    
    class Tpomodoro {                 
        public:    
        
        // void run()
        // void pause()
        // void reset()
        // void register_monitoring_callback(void monitoring_callback)

        Tpomodoro(const char* user_home_dir_sz);
        ~Tpomodoro();

        private:        
        std::string cfg_fname;
        Tpomodoro_cfg pomodoro_cfg;

        friend const std::string get_Tpomodoro_cfg_fname(const Tpomodoro* ptr_pom);
    };

}
#endif // TPOMODORO_H

