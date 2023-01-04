#pragma once
#include "ButtonControl.h"

class Booking;

class ButtonBookingControl : public ButtonControl
{
	DECLARE_CLASS_INFO(ButtonControl)

public:
	Delegate<void, Booking*> onClickBooking = nullptr;

private:
	Booking* booking = nullptr;

public:
	ButtonBookingControl() = default;
	ButtonBookingControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text, Booking* _booking);
	ButtonBookingControl(const ButtonBookingControl& _copy);

public:
	HWND Create() override;
	void OnUse() override;
};

