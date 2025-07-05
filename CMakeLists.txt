cmake_minimum_required(VERSION 3.31)
project(nbody_simulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT SHALLOW TRUE
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

add_executable(nbody_simulation src/main.cpp
        src/body.h)
target_link_libraries(nbody_simulation PRIVATE SFML::Graphics)
