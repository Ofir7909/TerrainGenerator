#include "Application.h"

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace forge
{
Application::Application() {}
Application::~Application() {}

void Application::Run()
{
	WindowResizeEvent e(1280, 720);
	FRG_TRACE(e);

	while (true) {}
}

} // namespace forge
