cmake_minimum_required(VERSION 3.20)
project(WG-App_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES
        "src/*.cpp"
)

add_executable(WGManager
        src/main.cpp
        ${SOURCES}
)
