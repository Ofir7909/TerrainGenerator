#pragma once
namespace forge {

class Application {
public:
  Application();
  virtual ~Application();

  void Run();

private:
};

Application *CreateApplication();

} // namespace forge