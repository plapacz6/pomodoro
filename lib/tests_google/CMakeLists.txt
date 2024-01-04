cmake_minimum_required(VERSION 3.17)

find_package(GTest REQUIRED)
message("GTEST_LIBRARIES : ${GTEST_LIBRARIES}")

LIST(APPEND test_lib_pomodoro_objects
    testg_Tpomodoro_cfg
    testg_Tpomodoro_state
    testg_Tpomodoro
)

add_executable(testg_Tpomodoro_cfg test_Tpomodoro_cfg.cpp)
target_link_libraries(testg_Tpomodoro_cfg PRIVATE 
    Tpomodoro_cfg
    tests_helper_functions
    ${GTEST_LIBRARIES}
    pthread
)

add_executable(testg_Tpomodoro_state test_Tpomodoro_state.cpp)
target_link_libraries(testg_Tpomodoro_state PRIVATE 
    Tpomodoro_state
    tests_helper_functions
    ${GTEST_LIBRARIES}
    pthread
)

add_executable(testg_Tpomodoro test_Tpomodoro.cpp)
target_link_libraries(testg_Tpomodoro PRIVATE 
    Tpomodoro
    Tpomodoro_cfg
    Tpomodoro_state
    tests_helper_functions
    ${GTEST_LIBRARIES}
    pthread    
)

foreach(my_test_obj IN LISTS test_lib_pomodoro_objects)
    target_include_directories(${my_test_obj} PRIVATE 
            #$<INSTALL_INTERFACE:include>
            # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
            # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/pomodoro_en>
            ../include
            ../include/pomodoro_en
            ../src                
    )
    target_compile_options(${my_test_obj} PRIVATE -Wall -g3)
    target_compile_definitions(${my_test_obj} PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
endforeach()

add_test(NAME testg__Tpomodoro_cfg COMMAND testg_Tpomodoro_cfg)
add_test(NAME testg__Tpomodoro_state COMMAND testg_Tpomodoro_state)
add_test(NAME testg__Tpomodoro COMMAND testg_Tpomodoro)






