cmake_minimum_required(VERSION 3.0)

project(terraGen VERSION 0.1)

cmake_policy(SET CMP0072 NEW)

set(SOURCE_FILES
    src/TerraGenApplication.cpp
)

add_executable(terraGen ${SOURCE_FILES})


#include forge engine.
add_subdirectory(lib/forge EXCLUDE_FROM_ALL)
target_link_libraries(terraGen PRIVATE forge)