#include "Application.h"

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

#include <GLFW/glfw3.h>
namespace forge
{
Application::Application() { m_Window = std::unique_ptr< Window >(Window::Create()); }
Application::~Application() {}

void Application::Run()
{
	WindowResizeEvent e(1280, 720);
	FRG_TRACE(e);

	while (m_Running) {
		glClearColor(0.35f, 0.45f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}
}

} // namespace forge
