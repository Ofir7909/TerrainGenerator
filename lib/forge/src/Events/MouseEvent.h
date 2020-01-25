#pragma once

#include "Event.h"

namespace forge
{
class MouseMovedEvent : public Event
{
  private:
	float m_MouseX;
	float m_MouseY;

  public:
	MouseMovedEvent(float mouseX, float mouseY): m_MouseX(mouseX), m_MouseY(mouseY) {}

	inline float GetX() const { return m_MouseX; }
	inline float GetY() const { return m_MouseY; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseMoved)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};

class MouseScrolledEvent : public Event
{
  private:
	float m_OffsetX;
	float m_OffsetY;

  public:
	MouseScrolledEvent(float offsetX, float offsetY): m_OffsetX(offsetX), m_OffsetY(offsetY) {}

	inline float GetOffsetX() const { return m_OffsetX; }
	inline float GetOffsetY() const { return m_OffsetY; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseScrolled)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};

// MouseKey Events
class MouseButtonEvent : public Event
{
  protected:
	MouseButtonEvent(int button): m_Button(button) {}

	int m_Button;

  public:
	inline int GetMouseButton() const { return m_Button; }

	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
  public:
	MouseButtonPressedEvent(int button): MouseButtonEvent(button) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_Button;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class MouseButtonReleasedEvent : public MouseButtonEvent
{
  public:
	MouseButtonReleasedEvent(int button): MouseButtonEvent(button) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_Button;
		return ss.str();
	}

	EVENT_CLASS_TYPE(MouseButtonReleased)
};

} // namespace forge
