#include "DateTime.h"
#include <ctime>
#include <format>

#pragma region f/p
const DateTime DateTime::Now = NowInternal();
#pragma endregion


#pragma region Constructor

DateTime::DateTime(int _day, int _month, int _year, int _hour, int _minute, int _second)
{
    day = _day;
    month = _month;
    year = _year;
    hour = _hour;
    minute = _minute;
    second = _second;
}

DateTime::DateTime(const SYSTEMTIME& _time)
{
    day = _time.wDay;
    month = _time.wMonth;
    year = _time.wYear;
    hour = _time.wHour;
    minute = _time.wMinute;
    second = _time.wSecond;
}

DateTime::DateTime(const DateTime& _copy)
{
    day = _copy.day;
    month = _copy.month;
    year = _copy.year;
    hour = _copy.hour;
    minute = _copy.minute;
    second = _copy.second;
}

#pragma endregion


DateTime DateTime::NowInternal()
{
    const time_t _now = time(nullptr);
    std::tm _tm = { };
    localtime_s(&_tm, &_now);
    return DateTime(_tm.tm_mday, _tm.tm_mon, _tm.tm_year + 1900, _tm.tm_hour, _tm.tm_min , _tm.tm_sec);
}

SYSTEMTIME DateTime::ToSystemTime() const
{
    SYSTEMTIME _time = SYSTEMTIME();
    _time.wDay = day;
    _time.wMonth = month;
    _time.wYear = year;
    _time.wHour = hour;
    _time.wMinute = minute;
    _time.wSecond = second;

    return _time;
}

std::string DateTime::ToString() const
{
    return std::format("{:02}/{:02}/{:02} {:02}:{:02}:{:02}", day, month, year, hour, minute, second);
}
