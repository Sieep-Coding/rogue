cmake_minimum_required(VERSION 3.10)
project(roguelike)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include Raylib
find_package(raylib REQUIRED)

# Add source files
add_executable(roguelike
    src/main.cpp
    src/core/Game.cpp
    src/entities/Player.cpp
    src/entities/Enemy.cpp
    src/entities/Entity.cpp
)

# Link Raylib
target_link_libraries(roguelike raylib)
