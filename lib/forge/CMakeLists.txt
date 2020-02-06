cmake_minimum_required(VERSION 3.16)

project(forge VERSION 0.1)

#Tell Cmake to use modern OpenGL
cmake_policy(SET CMP0072 NEW)

set(SOURCE_FILES
    src/Application.cpp
	src/Log.cpp
	src/Platform/x11/Window_x11.cpp
)

set(HEADER_FILES
	src/Core.h
    src/Log.h
    src/Application.h
	src/Events/Event.h
)

add_library(forge ${SOURCE_FILES})
 
target_include_directories(forge INTERFACE include)
target_include_directories(forge PUBLIC src) 

# Precompiled header
target_precompile_headers(forge PUBLIC src/frgpch.h)

# might be removed after adding proper support for glad
find_package(OpenGL REQUIRED)
target_link_libraries(forge PUBLIC OpenGL::GL)

# glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(forge PUBLIC glfw)


#glad
add_subdirectory(lib/glad EXCLUDE_FROM_ALL)
# add_library("glad" "${GLAD_DIR}/src/glad.c")
# target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
#target_include_directories(forge PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/lib/glad/include")
#message("[-]Added include Directory ${CMAKE_CURRENT_BINARY_DIR}/lib/glad/include")
target_link_libraries(forge PUBLIC glad)

# glm
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)
target_link_libraries(forge PUBLIC glm)

#stb_image
add_subdirectory(lib/stb EXCLUDE_FROM_ALL)
target_link_libraries(forge PUBLIC stb)

#spdlog
add_subdirectory(lib/spdlog EXCLUDE_FROM_ALL)
target_link_libraries(forge PUBLIC spdlog)