cmake_minimum_required(VERSION 3.2)
project(SuperSnake VERSION 0.1)

find_package(Curses REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_BUILD_TYPE Debug)

add_executable(snake main.cpp draw.cpp entity.cpp Keyboard.cpp)
target_link_libraries(snake ${CURSES_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})