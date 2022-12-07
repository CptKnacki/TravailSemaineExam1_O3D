#pragma once
#include <string>
#include "Date.h"

class Booking
{
#pragma region f/p
private:
	std::string clientFirstName = "John";
	std::string clientLastName = "Smith";

	int numberOfGuests = 1;

	Date arrivalDate = Date();
	Date departureDate = Date();

#pragma endregion

#pragma region Constructor
public:
	Booking() = default;
	Booking(const std::string _firstName, const std::string _lastName, const int _numberOfGuests, const Date& _arrivalDate, const Date& _departureDate);
	Booking(const Booking& _copy);

#pragma endregion

#pragma region Methods
public:

	/// <summary>
	///		Return the value of the client's first name
	/// </summary>
	/// <returns> clientFirstName </returns>
	std::string GetFirstName();

	/// <summary>
	///		Return the value of the client's last name
	/// </summary>
	/// <returns> clientLastName </returns>
	std::string GetLastName();

	/// <summary>
	///		Return the value of the number of guests
	/// </summary>
	/// <returns> numberOfGuests </returns>
	int GetNumberOfGuests();

	/// <summary>
	///		Return the value of client's arrival date
	/// </summary>
	/// <returns> arrivalDate </returns>
	Date& GetArrivalDate();

	/// <summary>
	///		Return the value of client's departure date
	/// </summary>
	/// <returns> departureDate </returns>
	Date& GetDepartureDate();
#pragma endregion
};

