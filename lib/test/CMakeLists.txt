cmake_minimum_required(VERSION 3.17)

find_package(Catch2 3 REQUIRED)

LIST(APPEND test_lib_pomodoro_objects
    test_Tpomodoro
    # test_cfg_obj
    # test_read_cfg    
)

add_executable(test_Tpomodoro test_Tpomodoro.cpp)
target_link_libraries(test_Tpomodoro PRIVATE Tpomodoro)
#target_link_libraries(test_Tpomodoro PRIVATE pomodoro_en)
target_link_libraries(test_Tpomodoro PRIVATE Catch2::Catch2WithMain)

# add_executable(test_cfg_obj test_cfg_obj.cpp)
# target_link_libraries(test_cfg_obj PRIVATE cfg_obj)
# target_link_libraries(test_cfg_obj PRIVATE Tpomodoro)
# target_link_libraries(test_cfg_obj PRIVATE Catch2::Catch2WithMain)

# add_executable(test_read_cfg test_read_cfg.cpp)
# target_link_libraries(test_read_cfg PRIVATE cfg_obj)
# target_link_libraries(test_read_cfg PRIVATE read_cfg)
# target_link_libraries(test_read_cfg PRIVATE Catch2::Catch2WithMain)

foreach(my_test_obj IN LISTS test_lib_pomodoro_objects)
    #target_include_directories(${my_test_obj} PRIVATE "../include")
    target_compile_options(${my_test_obj} PRIVATE -Wall)
    target_compile_definitions(${my_test_obj} PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
endforeach()

add_test(NAME test__Tpomodoro COMMAND test_Tpomodoro)
# add_test(NAME test__cfg_obj COMMAND test_cfg_obj)
# add_test(NAME test__read_cfg COMMAND test_read_cfg)





