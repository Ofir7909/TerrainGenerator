#include "Renderer.h"

#include <iostream>

namespace forge {

void GLClearError() {
  while (glGetError() != GL_NO_ERROR)
    ;
}

bool GLLogCall() {
  while (GLenum error = glGetError()) {
    std::cout << "[!] OpenGL Error: " << error << std::endl;
    return false;
  }

  return true;
}

void Renderer::Clear() const {
  GLCall(glClearColor(0.2f, 0.2f, 0.2f, 1));

  GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib,
                    const Shader &shader) const {
  // Bind relevent objects
  va.Bind();
  ib.Bind();
  shader.Bind();

  GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
} // namespace forge