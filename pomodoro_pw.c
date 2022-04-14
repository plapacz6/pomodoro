/*
author: plapacz6@gmail.com 
data: 2022-04-14 
license: GNU General Public License v3.0

description: elementary cli pomodoro timer
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef enum type_of_period_tt {
    TP_WORK,
    TP_SHORT_PAUSE,
    TP_LONG_PAUSE,
    TP_END_OF_CYCLE,
} type_of_period_t;

typedef struct my_time_period_table_my_tt {
  type_of_period_t curr_period_type;
  unsigned curr_period_time;
  unsigned work_nr;
} time_period_table_my_t;

typedef struct time_period_table_cfg_tt {
  unsigned work_time;
  unsigned work_nr;
  unsigned short_pause_time;
  unsigned long_pause_time;
} time_period_table_cfg_t;


int main(int argc, char **argv){
  time_period_table_my_t period_table_my;
  time_period_table_cfg_t period_table_cfg;
  bool end_of_pomodoro = false;
  char odp = 't';
  time_t time_stamp1;
  period_table_cfg.work_time = 20; //min
  period_table_cfg.short_pause_time = 5;  //min
  period_table_cfg.long_pause_time = 25; //min
  period_table_cfg.work_nr = 4;

  do { //main loop
  
    period_table_my.work_nr = 0;
    period_table_my.curr_period_type = TP_SHORT_PAUSE;

    while(period_table_my.curr_period_type != TP_END_OF_CYCLE){

      if(        
        period_table_my.curr_period_time < 
        (unsigned)( difftime(time(NULL), time_stamp1) / 60 )
      ){

        switch(period_table_my.curr_period_type){
          case TP_WORK:
            if(period_table_my.work_nr >= period_table_cfg.work_nr){
              period_table_my.curr_period_time = 
                period_table_cfg.long_pause_time;
              period_table_my.curr_period_type = TP_LONG_PAUSE;
              printf("%s\n"," ***** Take a LONG BREAK *** \a\a\a");
            }
            else{
              period_table_my.curr_period_time = 
                period_table_cfg.short_pause_time;
              period_table_my.curr_period_type = TP_SHORT_PAUSE;
              printf("%s\n"," ***** Take a short break ***\a");
            }
            break;
            
          case TP_SHORT_PAUSE:
            period_table_my.curr_period_time = 
              period_table_cfg.work_time;
            period_table_my.curr_period_type = TP_WORK;
            period_table_my.work_nr++;
            printf("%s%d\n",
              " ***** TIME TO WORK ****** ", 
              period_table_my.work_nr);
            break;

          case TP_LONG_PAUSE:
            period_table_my.curr_period_type = TP_END_OF_CYCLE;;
            break;
          case TP_END_OF_CYCLE:
            printf("%s\n", "program logic error");
            break;
        }
        time_stamp1 = time(NULL);
      }
    }  
    printf("%s\n","Do you want to continue ? (t/n) [ENTER]");
    
    do{      
      odp = getc(stdin);
    } while( odp != 't' && odp != 'T' && odp != 'n' && odp != 'N');
    
    if(odp == 'n' || odp == 'N'){ 
      end_of_pomodoro = true;
    }

  } while(!end_of_pomodoro); //main loop

  return 0;
}
