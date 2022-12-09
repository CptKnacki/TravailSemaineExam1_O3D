#pragma once

class Date
{
#pragma region f/p
private:
	int day = 0; 
	int month = 0;
	int year = 0;
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
	/// <returns> Value of the day </returns>
	int GetDay();

	/// <summary>
	///		Return the value of the month
	/// </summary>
	/// <returns> Value of the month </returns>
	int GetMonth();

	/// <summary>
	///		Return the value of the year
	/// </summary>
	/// <returns> Value of the year </returns>
	int GetYear();
#pragma endregion


};

