#include "Window_x11.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace forge
{
static bool s_GLFWInitialized = false;

static void GLFWErrorCallback(int error, const char* description)
{
	FRG_CORE_ERROR("GLFW EROOR ({0}): {1}", error, description);
}

Window* Window::Create(const WindowProps& props) { return new Window_x11(props); }

Window_x11::Window_x11(const WindowProps& props) { Init(props); }

Window_x11::~Window_x11() { Shutdown(); }

void Window_x11::Init(const WindowProps& props)
{
	m_Data.Title  = props.Title;
	m_Data.Width  = props.Width;
	m_Data.Height = props.Height;

	FRG_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

	// Init GLFW
	if (!s_GLFWInitialized) {
		FRG_CORE_INFO("Initializing GLFW");
		int success = glfwInit();
		FRG_CORE_ASSERT(success, "Could not Initialize GLFW");

		glfwSetErrorCallback(GLFWErrorCallback);

		s_GLFWInitialized = true;
		FRG_CORE_INFO("GLFW initialized successfully");
	}

	m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(),
								nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);

	// Init GLAD
	FRG_CORE_INFO("Initializing GLAD");
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	FRG_CORE_ASSERT(status, "Failed to initialize GLAD");

	glfwSetWindowUserPointer(m_Window, &m_Data);
	SetVsync(true);

	// Set GLFW Callbacks
	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		data.Width	= width;
		data.Height = height;

		WindowResizedEvent event(width, height);
		data.EventCallback(event);
	});

	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		WindowCloseEvent event;
		data.EventCallback(event);
	});

	glfwSetKeyCallback(m_Window,
					   [](GLFWwindow* window, int key, int scancode, int action, int mods) {
						   WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

						   switch (action) {
						   case GLFW_PRESS: {
							   KeyPressedEvent event(key, 0);
							   data.EventCallback(event);
							   break;
						   }

						   case GLFW_RELEASE: {
							   KeyReleasedEvent event(key);
							   data.EventCallback(event);
							   break;
						   }

						   case GLFW_REPEAT: {
							   KeyPressedEvent event(key, 1);
							   data.EventCallback(event);
							   break;
						   }

						   default: break;
						   }
					   });

	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		switch (action) {
		case GLFW_PRESS: {
			MouseButtonPressedEvent event(button);
			data.EventCallback(event);
			break;
		}

		case GLFW_RELEASE: {
			MouseButtonReleasedEvent event(button);
			data.EventCallback(event);
			break;
		}

		default: break;
		}
	});

	glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		data.EventCallback(event);
	});

	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		MouseMovedEvent event((float)xPos, (float)yPos);
		data.EventCallback(event);
	});
} // namespace forge

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
