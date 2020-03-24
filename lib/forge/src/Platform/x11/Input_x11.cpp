#include "Input_x11.h"

#include "Application.h"

#include <GLFW/glfw3.h>

namespace forge
{
Input* Input::s_Instance = new Input_x11();

bool Input_x11::IsKeyPressedImpl(int keycode)
{
	auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	int state	= glfwGetKey(window, keycode);

	return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input_x11::IsMouseButonPressedImpl(int button)
{
	auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	int state	= glfwGetMouseButton(window, button);

	return state == GLFW_PRESS;
}

std::pair<float, float> Input_x11::GetMousePositionImpl()
{
	auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	double x, y;
	glfwGetCursorPos(window, &x, &y);

	return {(float)x, (float)y};
}

float Input_x11::GetMouseXImpl()
{
	auto [x, y] = GetMousePositionImpl();
	return x;
}

float Input_x11::GetMouseYImpl()
{
	auto [x, y] = GetMousePositionImpl();
	return y;
}

} // namespace forge
