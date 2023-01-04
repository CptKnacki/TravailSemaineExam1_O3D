#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include "Singleton.h"
#include "Booking.h"

class MainMenuWindow;
class BookingWindow;
class ShowBookingWindow;
class AddBookingWindow;


class HotelApplication
{
#pragma region f/p
private:
	std::vector<Booking> bookingsList = std::vector<Booking>();
	Singleton<AddBookingWindow> addBooking;
	Singleton<MainMenuWindow> mainMenu;
	Singleton<ShowBookingWindow> showAllBookings;
	Singleton<BookingWindow> showBooking;


	HWND window;
	std::wstring title = L"Hotel Application";
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
	/// <param name="_firstName"> first name of the client </param>
	/// <param name="_lastName"> last name of the client </param>
	/// <param name="_numberOfGuests"> number of people for the booking </param>
	/// <param name="_arrivalDate"> arrival date </param>
	/// <param name="_departureDate"> departure date </param>
	/// <return> Indicate if the method successfully worked </return>
	int CreateBooking(const std::string _firstName, const std::string _lastName, const int _numberOfGuests, const Date& _arrivalDate, const Date& _departureDate);
	
	/// <summary>
	///		Create a new booking with an already created Booking
	/// </summary>
	/// <param name="_other"> instance of the booking that will be created </param>
	/// <return> Indicate if the method successfully worked </return>
	int CreateBooking(Booking& _other);
	
	/// <summary>
	///		Delete a booking regarding of the given index, also return -4 if the _index is out of range
	/// </summary>
	/// <param name="_index"> index of the booking that will be erased </param>
	/// <return> Indicate if the method successfully worked </return>
	int DeleteBooking(const int _index);

	/// <summary>
	///		Call the Show method off the add booking window
	/// </summary>
	void ShowAddMenu();

	/// <summary>
	///		Call the Show method off the main menu window
	/// </summary>
	void ShowMainMenu();

	/// <summary>
	///		Call the Show method off the booking window
	/// </summary>
	/// <param name="_index"> index of the booking that will be displayed </param>
	void ShowBooking(int _index);

	/// <summary>
	///		Display all the bookings saved in the hotel application
	/// </summary>
	void ShowAllBookings();
#pragma endregion

};

