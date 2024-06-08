cmake_minimum_required(VERSION 3.5)

project(flappy_ball)

set(CMAKE_CXX_STANDARD 20)

# Detect if we are cross-compiling
if (CMAKE_CROSSCOMPILING)
    message(STATUS "Cross-compiling for Windows")

    # Set Windows-specific defines
    add_definitions(-D_WIN32_WINNT=0x0601) # Windows 7 or later

    # Add additional Windows-specific flags if needed
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

add_subdirectory(raylib-cpp)

set(raylib_DIR /opt/raylib-windows/cmake)

find_package(raylib REQUIRED)
include_directories(raylib-cpp/include)

# Automatically include all .cpp files in the project directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(flappy_ball ${SOURCES})

if (CMAKE_CROSSCOMPILING)
    target_link_libraries(flappy_ball raylib winmm)
else()
    target_link_libraries(flappy_ball raylib)
endif()
