#include "Date.h"
#include <ctime>

#pragma region Constructor

Date::Date(const int _day, const int _month, const int _year)
{
	day = _day;
	month = _month;
	year = _year;
}

Date::Date(const Date& _copy)
{
	day = _copy.day;
	month = _copy.month;
	year = _copy.year;
}

#pragma endregion

#pragma region Methods

int Date::GetDay()
{
	return day;
}

int Date::GetMonth()
{
	return month;
}

int Date::GetYear()
{
	return year;
}

int Date::GetTotalOfDays()
{
	bool isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	int _result = 0;

	_result += year * 365;

	for (int i = 1; i < month; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) _result += 31;
		if (i == 4 || i == 6 || i == 9 || i == 11) _result += 30;

		if (i == 2 && isLeapYear) _result += 29;
		else if (i == 2 && !isLeapYear) _result += 28;
	}

	_result += day;

	return _result;
}

#pragma endregion
