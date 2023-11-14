#include "pomodoro_en/Tpomodoro_cfg.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace namespace_plapacz6;

Tpomodoro_cfg::Tpomodoro_cfg(){

}
Tpomodoro_cfg::~Tpomodoro_cfg(){

}
void Tpomodoro_cfg::set_default_parameters(){
    sessions_number = 4;
    session_time = 25;
    short_break_time = 5;
    long_break_time = 15;
}

void Tpomodoro_cfg::write_cfg(const std::string& cfg_fname_) {
    if(cfg_fname_ != "") {
        ofstream fout;
        fout.open(cfg_fname_, ios_base::out);
        string description;
        if(fout.is_open()) {
            fout << sessions_number << " sessions_number\n";
            fout << session_time << " session_time\n";
            fout << short_break_time << " short_break_time\n";
            fout << long_break_time << " long_break_time\n";
            fout.close();
        }
        else {
            cerr << "I can't write paramters to .pomodoro.config file\n";
        }
    }        
}
void Tpomodoro_cfg::read_cfg(const std::string& cfg_fname_) {
    if(cfg_fname_ != "") {
        ifstream fin;
        fin.open(cfg_fname_, ios_base::in);
        string description;
        if(fin.is_open()) {
            fin >> sessions_number >> description;            
            fin >> session_time >> description;
            fin >> short_break_time >> description;
            fin >> long_break_time >> description;
            fin.close();
        }
        else {
            cerr << "File .pomodoro.config not found. Setting default parameters.\n";
            set_default_parameters();
        }
    }
}