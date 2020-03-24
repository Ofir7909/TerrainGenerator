#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace forge
{
class Layer
{
  public:
	Layer(const std::string& name = "Layer"): m_DebugName(name) {}
	virtual ~Layer() {}

	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual void OnUpdate() {}
	virtual void OnEvent(Event& event) {}

	inline const std::string& GetName() const { return m_DebugName; }

  protected:
	std::string m_DebugName;
};
} // namespace forge