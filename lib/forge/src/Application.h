#pragma once

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Layer.h"
#include "LayerStack.h"
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

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);

  private:
	bool OnWindowClose(WindowCloseEvent& e);


	std::unique_ptr< Window > m_Window;
	bool m_Running = true;
	LayerStack m_LayerStack;
};

// Defind in client
Application* CreateApplication();

} // namespace forge