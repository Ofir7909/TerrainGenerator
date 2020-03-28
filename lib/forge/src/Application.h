#pragma once

#include "Events/ApplicationEvent.h"
#include "ImGui/ImGuiLayer.h"
#include "LayerStack.h"
#include "Window.h"

#include <glad/glad.h>

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

	inline const Window& GetWindow() { return *m_Window; }

	inline static Application& Get() { return *s_Instance; }

  private:
	bool OnWindowClose(WindowCloseEvent& e);

	std::unique_ptr<Window> m_Window;
	ImGuiLayer* m_ImGuiLayer;
	bool m_Running = true;
	LayerStack m_LayerStack;

	static Application* s_Instance;
};

// Defind in client
Application* CreateApplication();

} // namespace forge