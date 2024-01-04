cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)

list(APPEND lib_pomodoro_en_objects
    Tpomodoro_cfg
    Tpomodoro_state
    Tpomodoro   
    tests_helper_functions         
)

add_library(Tpomodoro_cfg OBJECT Tpomodoro_cfg.cpp)
add_library(Tpomodoro_state OBJECT Tpomodoro_state.cpp)
add_library(Tpomodoro OBJECT Tpomodoro.cpp)

#helper functions objects for tests only (not part of library)
add_library(tests_helper_functions OBJECT tests_helper_functions.cpp)

foreach(my_obj IN LISTS lib_pomodoro_en_objects)
    message(${my_obj})
    target_include_directories(${my_obj} PUBLIC 
        #include
        #$<INSTALL_INTERFACE:include>
        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/pomodoro_en>
        ../include
        ../include/pomodoro_en
        ./
    )
    target_compile_options(${my_obj} PUBLIC -Wall -fPIC -g3)
    target_compile_definitions(${my_obj} PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
endforeach()

add_library(${PROJECT_NAME} SHARED 
    $<TARGET_OBJECTS:Tpomodoro_cfg> 
    $<TARGET_OBJECTS:Tpomodoro_state> 
    $<TARGET_OBJECTS:Tpomodoro> 
)

# install(
#     FILES 
#         include/${PROJECT_NAME}/${PROJECT_NAME}.h 
#         include/${PROJECT_NAME}/Tpomodoro_stage.h
#         include/${PROJECT_NAME}/Tmonitoring_callback.h    
#     DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}
# )
# install(
#     TARGETS ${PROJECT_NAME} 
#     EXPORT ${PROJECT_NAME}_export 
#     DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}
# )
# install(
#     EXPORT ${PROJECT_NAME}_export 
#     DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}
# )



