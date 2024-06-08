cmake_minimum_required(VERSION 3.5)

project(flappy_ball)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(raylib-cpp)

find_package(raylib REQUIRED)

include_directories(raylib-cpp/include)

# Automatically include all .cpp files in the project directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(flappy_ball ${SOURCES})

target_link_libraries(flappy_ball raylib)
