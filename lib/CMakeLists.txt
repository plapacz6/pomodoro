cmake_minimum_required(VERSION 3.17)
project(pomodoro_en VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

list(APPEND lib_pomodoro_en_objects
    Tpomodoro_cfg
    Tpomodoro_state
    Tpomodoro        
)

add_library(Tpomodoro_cfg OBJECT src/Tpomodoro_cfg.cpp)
add_library(Tpomodoro_state OBJECT src/Tpomodoro_state.cpp)
add_library(Tpomodoro OBJECT src/Tpomodoro.cpp)

foreach(my_obj IN LISTS lib_pomodoro_en_objects)
    message(${my_obj})
    target_include_directories(${my_obj} PUBLIC 
        #include
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )
    target_compile_options(${my_obj} PUBLIC -Wall -fPIC)
    target_compile_definitions(${my_obj} PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
endforeach()

add_library(${PROJECT_NAME} SHARED 
    $<TARGET_OBJECTS:Tpomodoro_cfg> 
    $<TARGET_OBJECTS:Tpomodoro_state> 
    $<TARGET_OBJECTS:Tpomodoro> 
)

install(
    FILES include/${PROJECT_NAME}/${PROJECT_NAME}.h 
    #FILES include/${PROJECT_NAME}/Tpomodoro.h 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}
)
install(
    TARGETS ${PROJECT_NAME} 
    EXPORT ${PROJECT_NAME}_export 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}
)
install(
    EXPORT ${PROJECT_NAME}_export 
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}
)

enable_testing()
add_subdirectory(test)

