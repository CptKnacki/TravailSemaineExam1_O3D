#pragma once
#include <vector>
#include <string>
#include "Booking.h"

class HotelApplication
{
#pragma region f/p
private:
	std::vector<Booking> bookingsList = std::vector<Booking>();

	std::string title;
#pragma endregion

#pragma region Constructor
public:
	HotelApplication();
#pragma endregion

#pragma region Methods
public:

	/// <summary>
	///		Create a new booking with the given parameters, also return -2 if the booking already exists
	/// </summary>
	int CreateBooking(const std::string _firstName, const std::string _lastName, const int _numberOfGuests, const Date& _arrivalDate, const Date& _departureDate);
	
	/// <summary>
	///		Create a new booking with an already created Booking,
	/// </summary>
	int CreateBooking(Booking& _other);
	
	/// <summary>
	///		Delete a booking regarding of the given index, also return -4 if the _index is out of range
	/// </summary>
	int DeleteBooking(const int _index);
#pragma endregion

};

