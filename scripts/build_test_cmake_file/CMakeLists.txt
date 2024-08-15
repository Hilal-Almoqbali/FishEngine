cmake_minimum_required(VERSION 3.26)
project(test)
#TODO: do this
file(COPY ./assets/ DESTINATION ./build_test/)
SET( CMAKE_CXX_FLAGS "-Oz")
add_subdirectory(3rdParty)

add_subdirectory(./src/Engine/debug_sys/logging_sys/)

add_library(window_sys STATIC ./src/Engine/core/window-sys/window-sys.cpp)
target_include_directories(window_sys PUBLIC ./src/Engine/core/window-sys)
target_include_directories(window_sys PUBLIC ./src/Engine/debug_sys/logging_sys)
target_link_libraries(window_sys PUBLIC glfw)
target_link_libraries(window_sys PUBLIC glad)
target_link_libraries(window_sys PUBLIC glm)
target_link_libraries(window_sys PUBLIC logging_system)
#add_subdirectory(./src/Engine/core/event_system/)


add_executable(logging_system_test ./test/logging_system/logging_system_test.cpp)
target_link_libraries(logging_system_test PUBLIC logging_system)

add_executable(test_window_system ./test/window_system/test_window.cpp )
target_link_libraries(test_window_system PUBLIC window_sys)
#target_link_libraries(test_window_system PUBLIC event)
target_link_libraries(test_window_system PUBLIC glfw)
target_link_libraries(test_window_system PUBLIC glad)
target_link_libraries(test_window_system PUBLIC glm)
target_link_libraries(test_window_system PUBLIC logging_system)
target_include_directories(test_window_system PUBLIC ${INCLUDE})



#sandbox
#add_subdirectory(./src/Engine/)#build core
#add_subdirectory(./test/sand_box/)#build sand box

