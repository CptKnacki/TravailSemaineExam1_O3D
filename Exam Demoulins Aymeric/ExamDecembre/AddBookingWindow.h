#pragma once
#include "Window.h"
#include "Booking.h"

class AddBookingWindow : public Window
{
#pragma region f/p
private:

#pragma endregion

#pragma region Constructor
public:
	AddBookingWindow(const std::string _title = "Create New Booking");
#pragma endregion

#pragma region Methods
public:

	/// <summary>
	///		Will display the Add booking window, that contains 3 text zone where you enter client's information and a calendar
	///		 to choose client's schedule, there is also a return button and a save booking button
	///		 that will send the info and create a new booking
	/// </summary>
	/// <param name="_window"> instance of the parent window</param>
	/// <return> Return the booking created by the saving the user's input, or a blank booking if not </return>
	Booking Show(HWND _window);

#pragma endregion

};

