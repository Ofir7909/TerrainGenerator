#pragma once

#include <glad/glad.h>

#include <assert.h>

#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

#define GLCall(x)                                                              \
  GLClearError();                                                              \
  x;                                                                           \
  assert(GLLogCall())

namespace forge {
void GLClearError();
bool GLLogCall();

class Renderer {
private:
public:
  void Clear() const;
  void Draw(const VertexArray &va, const IndexBuffer &ib,
            const Shader &shader) const;
};
} // namespace forge