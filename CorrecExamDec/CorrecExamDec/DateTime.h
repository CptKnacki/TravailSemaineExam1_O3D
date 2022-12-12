#pragma once
#include "Object.h"
#include <Windows.h>

class DateTime : public Object
{
	DECLARE_CLASS_INFO(Object)

#pragma region f/p
private:
	int day = 0;
	int month = 0;
	int year = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;

public:
	static const DateTime Now;
#pragma endregion

#pragma region Constructor
public:
	DateTime() = default;
	DateTime(int _day, int _month, int year, int _hour, int _minute, int _second);
	DateTime(const SYSTEMTIME& _time);
	DateTime(const DateTime& _copy);
#pragma endregion

#pragma region Methods
private:
	static DateTime NowInternal();
#pragma endregion

#pragma region Override
public:
	std::string ToString() const override;
#pragma endregion

};

