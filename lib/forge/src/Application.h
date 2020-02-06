#pragma once

#include "Window.h"

namespace forge
{
class Application
{
  public:
	Application();
	virtual ~Application();

	void Run();

  private:
	std::unique_ptr< Window > m_Window;

	bool m_Running = true;
};

Application* CreateApplication();

} // namespace forge