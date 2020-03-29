cmake_minimum_required(VERSION 3.0)

project(imgui VERSION 0.1)

add_library(imgui 
	imgui/imgui.cpp
	imgui/imgui_demo.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_widgets.cpp
)

target_include_directories(imgui PUBLIC imgui/)
