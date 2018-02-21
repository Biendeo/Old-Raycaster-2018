cmake_minimum_required(VERSION 3.9)
project(Raycaster VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Raycaster src/Main.cpp src/Framerate.cpp src/Framerate.h src/Engine.cpp src/Engine.h src/View.cpp src/View.h)

target_link_libraries(Raycaster ${SDL2_LIBRARY})