#include "CalendarControl.h"
#include <CommCtrl.h>

#pragma region Constructor

CalendarControl::CalendarControl(int _controlID, HWND _owner, const Rect& _rect)
	: super(_controlID, _owner, _rect)
{
}

CalendarControl::CalendarControl(const CalendarControl& _copy)
	: super(_copy)
{
}

#pragma endregion

#pragma region Methods

void CalendarControl::SetMaxSelected(UINT _value)
{
	if (!IsInitialized()) return;
	// MonthCal_SetSelRange(instance, _value);
}

void CalendarControl::SetValue(const DateTime& _a, const DateTime& _b)
{
	const SYSTEMTIME _start = _a.ToSystemTime();
	const SYSTEMTIME _end = _b.ToSystemTime();
	LPSYSTEMTIME _tab = new SYSTEMTIME[2]{ _start, _end };
	MonthCal_SetSelRange(instance, _tab);
}
DateTime CalendarControl::ArrivedDate() const
{
	return arrivedDate;
}
DateTime CalendarControl::DepartureDate() const
{
	return departureDate;
}
void CalendarControl::OnChoice(LPNMSELCHANGE _value)
{
	DateTime arriveDate = DateTime(_value->stSelStart);
	DateTime departureDate = DateTime(_value->stSelEnd);
}
#pragma endregion

#pragma region Override
HWND CalendarControl::Create()
{
	instance = CreateWindowEx(0, MONTHCAL_CLASS, L"", WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_DAYSTATE | MCS_NOTODAY | MCS_MULTISELECT,
		rect.X(), rect.Y(), rect.Width(), rect.Height(), owner, (HMENU)controlID, ownerInstance, nullptr);
	RECT _minRect = {};
	MonthCal_GetMinReqRect(instance, &_minRect);
	SetWindowPos(instance, NULL, rect.X(), rect.Y(), _minRect.right, _minRect.bottom, SWP_NOZORDER);

	SYSTEMTIME* _time = new SYSTEMTIME[2];
	GetSystemTime(&_time[0]);
	MonthCal_SetRange(instance, GDTR_MIN, &_time[0]);

	MonthCal_SetCurrentView(instance, MCMV_MONTH);
	if (instance != NULL)
	{
		isInitialized = true;
		Show();
	}
	return instance;
}

#pragma endregion