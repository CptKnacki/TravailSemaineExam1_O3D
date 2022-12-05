#include "Booking.h"

#pragma region Constructor

Booking::Booking(const std::string _firstName, const std::string _lastName, const int _numberOfGuests, const Date& _arrivalDate, const Date& _departureDate)
{
	clientFirstName = _firstName;
	clientLastName = _lastName;
	numberOfGuests = _numberOfGuests;
	arrivalDate = _arrivalDate;
	departureDate = _departureDate;
}

Booking::Booking(const Booking& _copy)
{
	clientFirstName = _copy.clientFirstName;
	clientLastName = _copy.clientLastName;
	numberOfGuests = _copy.numberOfGuests;
	arrivalDate = _copy.arrivalDate;
	departureDate = _copy.departureDate;
}

#pragma endregion

#pragma region Methods

std::string Booking::GetFirstName()
{
	return clientFirstName;
}

std::string Booking::GetLastName()
{
	return clientLastName;
}

int Booking::GetNumberOfGuests()
{
	return numberOfGuests;
}

Date Booking::GetArrivalDate()
{
	return arrivalDate;
}

Date Booking::GetDepartureDate()
{
	return departureDate;
}

#pragma endregion


