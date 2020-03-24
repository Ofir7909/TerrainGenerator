#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h";
#include "Events/MouseEvent.h"
#include "Layer.h"

namespace forge
{
class ImGuiLayer : public Layer
{
  public:
	ImGuiLayer();
	~ImGuiLayer();

	void OnAttach() override;
	void OnDetach() override;
	void OnUpdate() override;
	void OnEvent(Event& event) override;

  private:
	bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
	bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
	bool OnMouseMovedEvent(MouseMovedEvent& e);
	bool OnMouseScrolledEvent(MouseScrolledEvent& e);

	bool OnKeyPressedEvent(KeyPressedEvent& e);
	bool OnKeyReleasedEvent(KeyReleasedEvent& e);
	bool OnKeyTypedEvent(KeyTypedEvent& e);

	bool OnWindowResizedEvent(WindowResizedEvent& e);

  private:
	float m_Time = 0; // Temp until we have time class
};
} // namespace forge