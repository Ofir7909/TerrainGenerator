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
		m_Window->OnUpdate();
	}
}

void Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch< WindowCloseEvent >(BIND_EVENT_FN(Application::OnWindowClose));

	FRG_CORE_TRACE("{0}", e);
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}


} // namespace forge
