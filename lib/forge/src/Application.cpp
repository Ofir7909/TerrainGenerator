#include "Application.h"

#include "Input.h"

#include <GLFW/glfw3.h> //REMOVE THIS
namespace forge
{
Application* Application::s_Instance = nullptr;

Application::Application()
{
	FRG_CORE_ASSERT(!s_Instance, "Application already exist!");
	s_Instance = this;

	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(FRG_BIND_EVENT_FN(Application::OnEvent));

	m_ImGuiLayer = new ImGuiLayer();
	PushOverlay(m_ImGuiLayer);
}
Application::~Application()
{
}

void Application::Run()
{
	while (m_Running) {
		glClearColor(0.35f, 0.45f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack) { layer->OnUpdate(); }

		m_ImGuiLayer->Begin();
		for (Layer* layer : m_LayerStack) { layer->OnImGuiRender(); }
		m_ImGuiLayer->End();

		m_Window->OnUpdate();
	}
}

void Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);

	// If the event is a WindowCloseEvent Close the window
	dispatcher.Dispatch<WindowCloseEvent>(FRG_BIND_EVENT_FN(Application::OnWindowClose));

	// FRG_CORE_TRACE("{0}", e);

	for (auto it = m_LayerStack.end(); it > m_LayerStack.begin();) {
		it--;
		(*it)->OnEvent(e);

		if (e.m_Handled)
			break;
	}
}

void Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
	layer->OnAttach();
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}
} // namespace forge
