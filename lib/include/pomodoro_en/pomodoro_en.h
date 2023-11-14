#ifndef POMODORO_EN_POMODORO_EN_H
#define POMODORO_EN_POMODORO_EN_H

#include <string>
#include "Tpomodoro.h"
#include "Tpomodoro_cfg.h"

namespace namespace_plapacz6 {

    class Tpomodoro {        
        public:
        std::string cfg_fname;
        Tpomodoro_cfg pomodoro_cfg;

        //const std::string& get_user_home_dir();

        Tpomodoro(const char* user_home_dir_sz);
        ~Tpomodoro();

        private:
        //std::string user_home_dir; //< directory where to store cfg file
    };

    // extern int x_pomodoro;
    
    // int read_cfg(int* cfg);

}

#endif // POMODORO_EN_POMODORO_EN_H