cmake_minimum_required(VERSION 3.17)
project(lib_pomodoro_eng_cpp VERSION 0.1 LANGUAGES CXX)

# LIBRARY_OUTPUT_DIRECTORY ("..")

# include_directories("../include")

list(APPEND lib_pomodoro_objects
    cfg_obj
    read_cfg
)

add_library(cfg_obj OBJECT cfg_obj.cpp)
add_library(read_cfg OBJECT read_cfg.cpp)

foreach(my_obj IN LISTS lib_pomodoro_objects)
    message(${my_obj})
    target_compile_options(${my_obj} PRIVATE -Wall)
    target_compile_definitions(${my_obj} PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
endforeach()

