#pragma once

#include "Event.h"

namespace forge
{
class WindowResizedEvent : public Event
{
  private:
	unsigned int m_Width, m_Height;

  public:
	WindowResizedEvent(unsigned int width, unsigned int height): m_Width(width), m_Height(height) {}

	inline unsigned int GetWidth() const { return m_Width; }
	inline unsigned int GetHeight() const { return m_Height; }

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class WindowCloseEvent : public Event
{
  public:
	WindowCloseEvent() {}

	EVENT_CLASS_TYPE(WindowClose)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};


} // namespace forge