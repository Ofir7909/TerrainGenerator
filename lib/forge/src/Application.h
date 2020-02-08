#pragma once

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Window.h"

namespace forge
{
class Application
{
  public:
	Application();
	virtual ~Application();

	void Run();
	void OnEvent(Event& e);

  private:
	bool OnWindowClose(WindowCloseEvent& e);


	std::unique_ptr< Window > m_Window;
	bool m_Running = true;
};

Application* CreateApplication();

} // namespace forge