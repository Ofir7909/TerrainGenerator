#include "Window_x11.h"

namespace forge
{
static bool s_GLFWInitialized = false;

Window* Window::Create(const WindowProps& props) { return new Window_x11(props); }

Window_x11::Window_x11(const WindowProps& props) { Init(props); }

Window_x11::~Window_x11() { Shutdown(); }

void Window_x11::Init(const WindowProps& props)
{
	m_Data.Title  = props.Title;
	m_Data.Width  = props.Width;
	m_Data.Height = props.Height;

	FRG_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

	if (!s_GLFWInitialized) {
		int success = glfwInit();
		FRG_CORE_ASSERT(success, "Could not Initialize GLFW");

		s_GLFWInitialized = true;
	}

	m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(),
								nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, &m_Data);
	SetVsync(true);
}

void Window_x11::Shutdown() { glfwDestroyWindow(m_Window); }

void Window_x11::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void Window_x11::SetVsync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	m_Data.Vsync = enabled;
}



} // namespace forge
