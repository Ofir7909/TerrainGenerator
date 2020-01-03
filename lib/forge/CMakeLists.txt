cmake_minimum_required(VERSION 3.0)

project(forge VERSION 0.1)

set(SOURCE_FILES
    src/IndexBuffer.cpp
    src/IndexBuffer.h
    src/Renderer.cpp
    src/Renderer.h
    src/Shader.cpp
    src/Shader.h
    src/test.cpp
    src/test.h
    src/Texture.cpp
    src/Texture.h
    src/VertexArray.cpp
    src/VertexArray.h
    src/VertexBuffer.cpp
    src/VertexBuffer.h
    src/VertexBufferLayout.cpp
    src/VertexBufferLayout.h
)

add_library(forge ${SOURCE_FILES})

target_include_directories(forge PUBLIC include)

# glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(forge PRIVATE glfw)


#glad
add_subdirectory(lib/glad EXCLUDE_FROM_ALL)
# add_library("glad" "${GLAD_DIR}/src/glad.c")
# target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
# target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(forge PRIVATE glad)

# glm
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)
target_link_libraries(forge PRIVATE glm)

#stb_image
add_subdirectory(lib/stb EXCLUDE_FROM_ALL)
target_link_libraries(forge PRIVATE stb)


