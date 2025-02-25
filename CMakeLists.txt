cmake_minimum_required(VERSION 3.5)
project(EndlessDungeon)

set(CMAKE_CXX_STANDARD 20)

# Disable raylib examples and tests if you don't need them.
set(BUILD_EXAMPLES OFF CACHE BOOL "Disable raylib examples")
set(BUILD_TESTING OFF CACHE BOOL "Disable raylib tests")

# Add the raylib subdirectory from its location on disk.
add_subdirectory("C:/raylib/raylib" raylib_build)

# Create an executable using main.cpp.
add_executable(EndlessDungeon main.cpp
        PlayerController.cpp
        gridRender.cpp
        dungeonController.cpp
        common.cpp
        gameController.cpp
        gameController.h
)


# Link your executable to the raylib target.
target_link_libraries(EndlessDungeon PRIVATE raylib)
