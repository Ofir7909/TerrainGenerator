cmake_minimum_required(VERSION 3.0)

project(stb VERSION 0.1)

add_library(stb stb_image.h stb_image.cpp)

target_include_directories(stb PUBLIC .)
