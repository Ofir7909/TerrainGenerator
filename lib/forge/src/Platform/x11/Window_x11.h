#pragma once

#include "Core.h"

#include "Window.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

namespace forge
{
class Window_x11 : public Window
{
  public:
	Window_x11(const WindowProps& props);
	virtual ~Window_x11();

	void OnUpdate() override;

	inline unsigned int GetWidth() const override { return m_Data.Width; }
	inline unsigned int GetHeight() const override { return m_Data.Height; }

	inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

	void SetVsync(bool enabled) override;
	inline bool IsVsync() const override { return m_Data.Vsync; }

  private:
	virtual void Init(const WindowProps& props);
	virtual void Shutdown();

	GLFWwindow* m_Window;

	struct WindowData
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		bool Vsync;

		EventCallbackFn EventCallback;
	};
	WindowData m_Data;
};
} // namespace forge
