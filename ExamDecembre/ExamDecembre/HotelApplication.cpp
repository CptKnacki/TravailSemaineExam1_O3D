#include "HotelApplication.h"
#include "Booking.h"


#include "Window.h"
#include "AddBookingWindow.h"
#include "BookingWindow.h"
#include "MainMenuWindow.h"
#include "ShowBookingWindow.h"

#pragma region Constructor

HotelApplication::HotelApplication()
{

	title = "Hotel Application";
}

#pragma endregion


#pragma region Methods

int HotelApplication::CreateBooking(const std::string _firstName, const std::string _lastName, const int _numberOfGuests, const Date& _arrivalDate, const Date& _departureDate)
{
	size_t _size = bookingsList.size();

	for (size_t i = 0; i < _size; i++)
		if (bookingsList[i].GetFirstName() == _firstName && bookingsList[i].GetLastName() == _lastName)
			return -2;
	
	bookingsList.push_back(Booking(_firstName, _lastName, _numberOfGuests, _arrivalDate, _departureDate));
	return 1;
}

int HotelApplication::CreateBooking(Booking& _other)
{
	size_t _size = bookingsList.size();

	for (size_t i = 0; i < _size; i++)
		if (bookingsList[i].GetFirstName() == _other.GetFirstName() && bookingsList[i].GetLastName() == _other.GetLastName())
			return -2;

	bookingsList.push_back(_other);
}

int HotelApplication::DeleteBooking(const int _index)
{
	size_t _size = bookingsList.size();

	if (_index >= _size || _index < 0) return -4;

	std::vector<Booking> _temp = std::vector<Booking>();

	for (size_t i = 0; i < _size; i++)
		if (i != _index)
			_temp.push_back(bookingsList[i]);
	
	bookingsList = _temp;
}

#pragma endregion


