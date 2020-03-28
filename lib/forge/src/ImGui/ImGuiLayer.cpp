#include "ImGuiLayer.h"

#include "Application.h"

#include "ImGuiBuild.h"

// REMOVE THIS
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace forge
{
ImGuiLayer::ImGuiLayer(): Layer("ImGuiLayer")
{
}

ImGuiLayer::~ImGuiLayer()
{
}

void ImGuiLayer::OnAttach()
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
	// io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;	// Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
	// io.ConfigViewportsNoAutoMerge = true;
	// io.ConfigViewportsNoTaskBarIcon = true;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular
	// ones.
	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		style.WindowRounding			  = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	// Setup Platform/Renderer bindings
	Application& app   = Application::Get();
	GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 410");
}

void ImGuiLayer::OnDetach()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiLayer::OnImGuiRender()
{
	static bool show = true;
	ImGui::ShowDemoWindow(&show);
}

void ImGuiLayer::Begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void ImGuiLayer::End()
{
	ImGuiIO& io		 = ImGui::GetIO();
	Application& app = Application::Get();
	io.DisplaySize	 = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}
}

// void ImGuiLayer::OnEvent(Event& event)
//{
//	EventDispatcher dispatcher(event);
//	dispatcher.Dispatch<MouseButtonPressedEvent>(FRG_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
//	dispatcher.Dispatch<MouseButtonReleasedEvent>(FRG_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
//	dispatcher.Dispatch<MouseMovedEvent>(FRG_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
//	dispatcher.Dispatch<MouseScrolledEvent>(FRG_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
//	dispatcher.Dispatch<KeyPressedEvent>(FRG_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
//	dispatcher.Dispatch<KeyReleasedEvent>(FRG_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
//	dispatcher.Dispatch<KeyTypedEvent>(FRG_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
//	dispatcher.Dispatch<WindowResizedEvent>(FRG_BIND_EVENT_FN(ImGuiLayer::OnWindowResizedEvent));
//}
//
// bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
//{
//	ImGuiIO& io = ImGui::GetIO();
//
//	io.MouseDown[e.GetMouseButton()] = true;
//
//	return false;
//}
//
// bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
//{
//	ImGuiIO& io = ImGui::GetIO();
//
//	io.MouseDown[e.GetMouseButton()] = false;
//
//	return false;
//}
//
// bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
//{
//	ImGuiIO& io = ImGui::GetIO();
//
//	io.MousePos = ImVec2(e.GetX(), e.GetY());
//
//	return false;
//}
//
// bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
//{
//	ImGuiIO& io = ImGui::GetIO();
//
//	io.MouseWheel += e.GetOffsetY();
//	io.MouseWheelH += e.GetOffsetX();
//
//	return false;
//}
//
// bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
//{
//	ImGuiIO& io = ImGui::GetIO();
//
//	io.KeysDown[e.GetKeyCode()] = true;
//
//	io.KeyCtrl	= io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
//	io.KeyAlt	= io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
//	io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
//	io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
//
//	return false;
//}
//
// bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
//{
//	ImGuiIO& io = ImGui::GetIO();
//
//	io.KeysDown[e.GetKeyCode()] = false;
//
//	io.KeyCtrl	= io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
//	io.KeyAlt	= io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
//	io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
//	io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
//
//	return false;
//}
//
// bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
//{
//	ImGuiIO& io = ImGui::GetIO();
//
//	int keycode = e.GetKeyCode();
//
//	if (keycode > 0 && keycode < 0x10000)
//		io.AddInputCharacter((unsigned short)keycode);
//
//	return false;
//}
//
// bool ImGuiLayer::OnWindowResizedEvent(WindowResizedEvent& e)
//{
//	ImGuiIO& io = ImGui::GetIO();
//
//	io.DisplaySize			   = ImVec2(e.GetWidth(), e.GetHeight());
//	io.DisplayFramebufferScale = ImVec2(1, 1);
//
//	glViewport(0, 0, e.GetWidth(), e.GetHeight());
//
//	return false;
//}

} // namespace forge