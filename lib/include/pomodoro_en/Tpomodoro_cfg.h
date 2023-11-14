#ifndef TPOMODORO_CFG_H
#define TPOMODORO_CFG_H

namespace namespace_plapacz6 {

class Tpomodoro_cfg {
    public:
        int sessions_number;
        int session_time;
        int short_break_time;
        int long_break_time;

        void set_default_parameters();
        Tpomodoro_cfg();
        ~Tpomodoro_cfg();
    private:
};

}


#endif // TPOMODORO_CFG_H