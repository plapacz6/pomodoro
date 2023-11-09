cmake_minimum_required(VERSION 3.17)
project(lib_pomodoro_eng_cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include_directories("include")

enable_testing()
add_subdirectory(src)
add_subdirectory(test)

add_library(pomodoro_eng_cpp SHARED $<TARGET_OBJECTS:cfg_obj> $<TARGET_OBJECTS:read_cfg>)
