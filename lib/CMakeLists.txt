cmake_minimum_required(VERSION 3.17)
project(pomodoro_en VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(tests_google)

# list(APPEND lib_pomodoro_en_objects
#     Tpomodoro_cfg
#     Tpomodoro_state
#     Tpomodoro   
#     tests_helper_functions_Tpomodoro     
#     tests_helper_functions_Tpomodoro_cfg
#     tests_helper_functions_Tpomodoro_state
# )

# add_library(Tpomodoro_cfg OBJECT src/Tpomodoro_cfg.cpp)
# add_library(Tpomodoro_state OBJECT src/Tpomodoro_state.cpp)
# add_library(Tpomodoro OBJECT src/Tpomodoro.cpp)

# #helper functions objects for tests only (not part of library)
# add_library(tests_helper_functions_Tpomodoro OBJECT src/tests_helper_functions_Tpomodoro.cpp)
# add_library(tests_helper_functions_Tpomodoro_cfg OBJECT src/tests_helper_functions_Tpomodoro_cfg.cpp)
# add_library(tests_helper_functions_Tpomodoro_state OBJECT src/tests_helper_functions_Tpomodoro_state.cpp)

# foreach(my_obj IN LISTS lib_pomodoro_en_objects)
#     message(${my_obj})
#     target_include_directories(${my_obj} PUBLIC 
#         #include
#         $<INSTALL_INTERFACE:include>
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#     )
#     target_compile_options(${my_obj} PUBLIC -Wall -fPIC -g3)
#     target_compile_definitions(${my_obj} PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
# endforeach()

# add_library(${PROJECT_NAME} SHARED 
#     $<TARGET_OBJECTS:Tpomodoro_cfg> 
#     $<TARGET_OBJECTS:Tpomodoro_state> 
#     $<TARGET_OBJECTS:Tpomodoro> 
# )

install(
    FILES 
        include/${PROJECT_NAME}/${PROJECT_NAME}.h 
        include/${PROJECT_NAME}/Tpomodoro_stage.h
        include/${PROJECT_NAME}/Tmonitoring_callback.h    
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




