#pragma once
#include "Window.h"

class ShowBookingWindow : public Window
{
#pragma region f/p
private:

#pragma endregion

#pragma region Constructor
public:
	ShowBookingWindow(const std::string _title = "Booking View");
#pragma endregion

#pragma region Override
public:
	/// <summary>
	///		Used to display the show booking menu that contains a return button and an array
	///		 of button regarding the number of saved bookings, if clicked on,
	///		 it will display the booking window of the chosen booking
	/// </summary>
	void Show() override;

	/// <summary>
	///		Used to close these window to let another one open on top of it
	/// </summary>
	void Close() override;
#pragma endregion

};

