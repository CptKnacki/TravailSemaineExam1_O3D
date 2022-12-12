#pragma once
#include "WindowControl.h"
class CalendarControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

#pragma region f/p
private:

#pragma endregion

#pragma region Constructor
public:
	CalendarControl() = default;
	CalendarControl(int _controlID, HWND _owner, const Rect& _rect);
	CalendarControl(const CalendarControl& _copy);
#pragma endregion

#pragma region Methods
public:
	void SetMaxSelected(UINT _value);
#pragma endregion

#pragma region Override
public:
	HWND Create() override;
#pragma endregion

};

