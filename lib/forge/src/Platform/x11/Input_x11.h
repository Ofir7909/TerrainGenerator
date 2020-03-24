#pragma once

#include "Input.h"

namespace forge
{
class Input_x11 : public Input
{
  protected:
	bool IsKeyPressedImpl(int keycode) override;

	bool IsMouseButonPressedImpl(int button) override;
	std::pair<float, float> GetMousePositionImpl() override;
	float GetMouseXImpl() override;
	float GetMouseYImpl() override;
};
} // namespace forge