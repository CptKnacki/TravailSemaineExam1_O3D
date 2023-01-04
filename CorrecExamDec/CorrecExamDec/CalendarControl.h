#pragma once
#include "WindowControl.h"
#include "DateTime.h"
#include <CommCtrl.h>
#include <map>

class CalendarControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

#pragma region f/p
public:
	static inline std::map<int, CalendarControl*> calendars = std::map<int, CalendarControl*>();
private:
	DateTime arrivedDate = DateTime();
	DateTime departureDate = DateTime();

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
	void SetValue(const DateTime& _a, const DateTime& _b);
	void OnChoice(LPNMSELCHANGE _value);
	DateTime ArrivedDate() const;
	DateTime DepartureDate() const;
#pragma endregion

#pragma region Override
public:
	HWND Create() override;
#pragma endregion

};

