#include "ButtonBookingControl.h"

ButtonBookingControl::ButtonBookingControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text, Booking* _booking)
	: super(_controlID, _owner, _rect, _text)
{
	booking = _booking;
}

ButtonBookingControl::ButtonBookingControl(const ButtonBookingControl& _copy)
	: super(_copy)
{
	booking = _copy.booking;
}

HWND ButtonBookingControl::Create()
{
	return super::Create();
}

void ButtonBookingControl::OnUse()
{
	onClickBooking.Invoke(booking);
	super::OnUse();
}
