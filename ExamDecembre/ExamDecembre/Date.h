#pragma once

class Date
{
#pragma region f/p
private:
	int day = 5; 
	int month = 12;
	int year = 2022;
#pragma endregion

#pragma region Constructor
public:
	Date() = default; // TODO put the localtime as the default value by using ctime //
	Date(const int _day, const int _month, const int _year);
	Date(const Date& _copy);
#pragma endregion

#pragma region Methods
public:

	/// <summary>
	///		Return the value of the day
	/// </summary>
	/// <returns> day </returns>
	int GetDay();

	/// <summary>
	///		Return the value of the month
	/// </summary>
	/// <returns> month </returns>
	int GetMonth();

	/// <summary>
	///		Return the value of the year
	/// </summary>
	/// <returns> year </returns>
	int GetYear();
#pragma endregion


};

