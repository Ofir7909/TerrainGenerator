#pragma once

#include "Core.h"

namespace forge
{
class Input
{
  public:
	// Keyboard input
	inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

	// Mouse input
	inline static bool IsMouseButonPressed(int button) { return s_Instance->IsMouseButonPressedImpl(button); }
	inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
	inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
	inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

  protected:
	// Keyboard input

	virtual bool IsKeyPressedImpl(int keycode) = 0;
	// Mouse Input
	virtual bool IsMouseButonPressedImpl(int button)	   = 0;
	virtual std::pair<float, float> GetMousePositionImpl() = 0;
	virtual float GetMouseXImpl()						   = 0;
	virtual float GetMouseYImpl()						   = 0;

  private:
	static Input* s_Instance;
};
} // namespace forge