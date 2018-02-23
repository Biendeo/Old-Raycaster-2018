cmake_minimum_required(VERSION 3.9)
project(Raycaster VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(./include)

add_library(RaycasterEngine SHARED src/Engine/Framerate.cpp include/Framerate.h src/Engine/Engine.cpp include/Engine.h src/Engine/Player.cpp include/Player.h src/Engine/Vector3.cpp include/Vector3.h)

add_executable(Raycaster src/View/Main.cpp src/Engine/Framerate.cpp include/Framerate.h src/Engine/Engine.cpp include/Engine.h src/View/View.cpp src/View/View.h src/View/Input.cpp src/View/Input.h)

target_include_directories(Raycaster PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(Raycaster ${SDL2_LIBRARY} RaycasterEngine)