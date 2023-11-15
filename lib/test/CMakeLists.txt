cmake_minimum_required(VERSION 3.17)

find_package(Catch2 3 REQUIRED)

LIST(APPEND test_lib_pomodoro_objects
    test_Tpomodoro_cfg
    test_Tpomodoro_state
    test_Tpomodoro

)

add_executable(test_Tpomodoro_cfg test_Tpomodoro_cfg.cpp)
target_link_libraries(test_Tpomodoro_cfg PRIVATE Tpomodoro_cfg)
target_link_libraries(test_Tpomodoro_cfg PRIVATE tests_helper_functions)
target_link_libraries(test_Tpomodoro_cfg PRIVATE Catch2::Catch2WithMain)

add_executable(test_Tpomodoro_state test_Tpomodoro_state.cpp)
target_link_libraries(test_Tpomodoro_state PRIVATE Tpomodoro_state)
target_link_libraries(test_Tpomodoro_state PRIVATE tests_helper_functions)
target_link_libraries(test_Tpomodoro_state PRIVATE Catch2::Catch2WithMain)

add_executable(test_Tpomodoro test_Tpomodoro.cpp)
target_link_libraries(test_Tpomodoro PRIVATE Tpomodoro)
target_link_libraries(test_Tpomodoro PRIVATE Tpomodoro_cfg)
#target_link_libraries(test_Tpomodoro PRIVATE pomodoro_en)
target_link_libraries(test_Tpomodoro PRIVATE tests_helper_functions)
target_link_libraries(test_Tpomodoro PRIVATE Catch2::Catch2WithMain)

foreach(my_test_obj IN LISTS test_lib_pomodoro_objects)
    #target_include_directories(${my_test_obj} PRIVATE "../include")
    target_compile_options(${my_test_obj} PRIVATE -Wall)
    target_compile_definitions(${my_test_obj} PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
endforeach()

add_test(NAME test__Tpomodoro_cfg COMMAND test_Tpomodoro_cfg)
add_test(NAME test__Tpomodoro_state COMMAND test_Tpomodoro_state)
add_test(NAME test__Tpomodoro COMMAND test_Tpomodoro)






