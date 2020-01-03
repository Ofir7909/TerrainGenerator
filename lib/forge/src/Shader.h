#pragma once

#include <glm/glm.hpp>
#include <string>
#include <unordered_map>

namespace forge {

// Struct that contain strings with the source code for each shader.
struct ShaderProgramSource {
  std::string VertexSource;
  std::string FragmentSource;
};

class Shader {
private:
  unsigned int m_RendererID;
  std::string m_Filepath;
  std::unordered_map<std::string, int> m_UniformLocationCache;

public:
  Shader(const std::string &filepath);
  ~Shader();

  void Bind() const;
  void Unbind() const;

  // Set Uniforms
  // Integers
  void SetUniform1i(const std::string &name, int value);
  // Floats
  void SetUniform1f(const std::string &name, float value);
  void SetUniform4f(const std::string &name, float v0, float v1, float v2,
                    float v3);
  // Matrices
  void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix);

private:
  int GetUniformLocation(const std::string &name);
  ShaderProgramSource ParseShader(const std::string &filepath);
  unsigned int CompileShader(unsigned int type, const std::string &source);
  unsigned int CreateShader(const std::string &vertexShader,
                            const std::string &fragmentShader);
};
} // namespace forge