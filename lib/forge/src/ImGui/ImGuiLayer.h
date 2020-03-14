#pragma once

#include "Core.h"
#include "Layer.h"
#include "imgui.h"

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
	float m_Time = 0;
};
} // namespace forge