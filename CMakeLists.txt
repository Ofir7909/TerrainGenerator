cmake_minimum_required(VERSION 3.0)

project(TerrainGenerator VERSION 0.1)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3")

set(SOURCE_FILES
    src/main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})