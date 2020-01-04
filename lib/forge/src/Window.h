#include <string>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

namespace forge {
class Window {
private:
  GLFWwindow *window;

public:
  Window(int Width, int Height, const std::string &title);
  ~Window();

  void Clear(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.1f);

  void Update();

  void Draw();

  inline bool IsOpen() const { return !glfwWindowShouldClose(window); }
};
} // namespace forge