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

#pragma endregion
