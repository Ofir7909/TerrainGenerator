#include "Application.h"

#include "Core.h"
#include "Log.h"

#include <GLFW/glfw3.h> //REMOVE THIS
namespace forge
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

Application::Application()
{
	m_Window = std::unique_ptr< Window >(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
}
Application::~Application() {}

void Application::Run()
{
	while (m_Running) {
		glClearColor(0.35f, 0.45f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack) { layer->OnUpdate(); }

		m_Window->OnUpdate();
	}
}

void Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);

	// If the event is a WindowCloseEvent Close the window
	dispatcher.Dispatch< WindowCloseEvent >(BIND_EVENT_FN(Application::OnWindowClose));

	FRG_CORE_TRACE("{0}", e);

	for (auto it = m_LayerStack.end(); it > m_LayerStack.begin();) {
		it--;
		(*it)->OnEvent(e);

		if (e.m_Handled)
			break;
	}
}

void Application::PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); }

void Application::PushOverlay(Layer* layer) { m_LayerStack.PushOverlay(layer); }

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}


} // namespace forge
