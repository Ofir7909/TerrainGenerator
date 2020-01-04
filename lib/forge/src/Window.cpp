#include "Window.h"

namespace forge {
Window::Window(int width, int height, const std::string &title) {
  // Initialize glfw
  if (!glfwInit())
    return;

  // Global Settigns for openGL version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(width, 540, title.c_str(), NULL, NULL);
  if (!window) {
    // if window invalid, terminate the program.
    glfwTerminate();
    return;
  }

  // Set framerate to monitor refresh rate.
  glfwSwapInterval(1);

  // Make the window's context current
  glfwMakeContextCurrent(window);

  if (!gladLoadGL()) {
    return;
  }
  // Print OpenGL version.
  // std::cout << glGetString(GL_VERSION) << std::endl;
}

Window::~Window() { glfwTerminate(); }

void Window::Clear(float r, float g, float b, float a) {
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Update() { glfwPollEvents(); }

void Window::Draw() { glfwSwapBuffers(window); }

} // namespace forge
