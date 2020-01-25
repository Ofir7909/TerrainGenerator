#pragma once

#include "Core.h"

namespace forge
{
// Events are blocking, meaning when an event gets called it must be delt with
// before execution continues.

enum class EventType
{
	None = 0,

	WindowClose,
	WindowResize,
	WindowFocus,
	WindowLostFocus,
	WindowMoved,

	// Currently not implemented
	AppTick,
	AppUpdate,
	AppRender,

	KeyPressed,
	KeyReleased,

	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved,
	MouseScrolled
};

enum EventCategory
{
	None					 = 0,
	EventCategoryApplication = BIT(0),
	EventCategoryInput		 = BIT(1),
	EventCategoryKeyboard	 = BIT(2),
	EventCategoryMouse		 = BIT(3),
	EventCategoryMouseButton = BIT(4)
};

#define EVENT_CLASS_TYPE(type)                                                  \
	static EventType GetStaticType() { return EventType::type; }                \
	virtual EventType GetEventType() const override { return GetStaticType(); } \
	virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
	virtual int GetCategoryFlags() const override { return category; }

class Event
{
	friend class EventDispatcher;

  protected:
	bool m_Handled = false;

  public:
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const	   = 0;
	virtual int GetCategoryFlags() const   = 0;
	virtual std::string ToString() const { return GetName(); }

	inline bool IsInCategory(EventCategory cat) { return (GetCategoryFlags() & cat); }
};

class EventDispatcher
{
	// EventFn type decleration
	template< typename T >
	using EventFn = std::function< bool(T&) >;

  private:
	Event& m_Event;

  public:
	EventDispatcher(Event& event): m_Event(event) {}

	// func is the handeling function, T is the type of event we are sending
	template< typename T >
	bool Dispatch(EventFn< T > func)
	{
		if (m_Event.GetEventType() == T::GetStaticType()) {
			// Take m_Event location, convert it to T pointer, and derefrence it.
			m_Event.m_Handled = func(*(T*)&m_Event);
			return true;
		}
		return false;
	}
};

inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.ToString(); }
} // namespace forge
