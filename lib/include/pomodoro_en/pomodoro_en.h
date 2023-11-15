#ifndef POMODORO_EN_POMODORO_EN_H
#define POMODORO_EN_POMODORO_EN_H

namespace namespace_plapacz6 {

/**
 * @brief class implementing pomodoro process
*/
class Tpomodoro;

/**
 * @brief Construct a new Tpomodoro:: Tpomodoro object
 * creates internally path to configuration store file .pomodoro.config 
 * based on user home directory path
 * 
 * @param home_user_dir path to user home directory ($HOME)
 */
Tpomodoro::Tpomodoro(const char *home_user_dir);

/**
 * @brief Destroy the Tpomodoro:: Tpomodoro object
 * automatically try to save current configuration in $HOME/.pomodoro.config file
 */
Tpomodoro::~Tpomodoro();

/**
 * @brief run process 'pomodoro'
 * 
 */
void Tpomodoro::run();

/**
 * @brief pause (don't reset state of process 'pomodoro')
 * 
 */
void Tpomodoro::pause();

/**
 * @brief reset process 'pomodoro' to before start
 * 
 */
void Tpomodoro::reset();

/**
 * @brief registers functions called periodically
 * 
 * @param monitoring_callback_ 
 */
void Tpomodoro::register_monitoring_callback(void (*monitoring_callback_)(int));

/**
 * @brief set new configuration according to parameters
 * 
 */
void Tpomodoro::set_cfg(int, int, int, int);

/**
 * @brief save current configuration to $HOME/.pomodoro.config file
 * 
 */
void Tpomodoro::save_cfg();

} //namespace namespace_plapacz6 {

#endif // POMODORO_EN_POMODORO_EN_H