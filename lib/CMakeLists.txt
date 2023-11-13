cmake_minimum_required(VERSION 3.17)
project(lib_pomodoro_en_cpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

list(APPEND lib_pomodoro_en_objects
    cfg_obj
    read_cfg
)

add_library(cfg_obj OBJECT src/cfg_obj.cpp)
add_library(read_cfg OBJECT src/read_cfg.cpp)

foreach(my_obj IN LISTS lib_pomodoro_en_objects)
    message(${my_obj})
    target_include_directories(${my_obj} PUBLIC 
        #include
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )
    target_compile_options(${my_obj} PUBLIC -Wall)
    target_compile_definitions(${my_obj} PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
endforeach()

add_library(pomodoro_en_cpp SHARED $<TARGET_OBJECTS:cfg_obj> $<TARGET_OBJECTS:read_cfg>)

install(FILES include/pomodoro_en/pomodoro_en.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include/pomodoro_en)
install(TARGETS pomodoro_en_cpp EXPORT pomodoro_en_export DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(EXPORT pomodoro_en_export DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

add_subdirectory(test)

