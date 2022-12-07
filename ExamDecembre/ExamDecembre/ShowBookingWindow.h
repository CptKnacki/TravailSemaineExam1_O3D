#pragma once
#include "Window.h"
#include <vector>
#include "Booking.h"

class ShowBookingWindow : public Window
{
#pragma region f/p
private:

#pragma endregion

#pragma region Constructor
public:
	ShowBookingWindow(const std::string _title = "Booking View");
#pragma endregion

#pragma region Methods
public:
	/// <summary>
	///		Used to display the show booking menu that contains a return button and an array
	///		 of button regarding the number of saved bookings, if clicked on,
	///		 it will display the booking window of the chosen booking
	/// </summary>
	int Show(HWND _window, std::vector<Booking> _bookings);

#pragma endregion

};

