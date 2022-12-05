#pragma once
#include "Window.h"

class AddBookingWindow : public Window
{
#pragma region f/p
private:

#pragma endregion

#pragma region Constructor
public:
	AddBookingWindow(const std::string _title = "Create New Booking");
#pragma endregion

#pragma region Override
public:

	/// <summary>
	///		Will display the Add booking window, that contains 3 text zone where you enter client's information and a calendar
	///		 to choose client's schedule, there is also a return button and a save booking button
	///		 that will send the info and create a new booking
	/// </summary>
	void Show() override;

	/// <summary>
	///		Used to close these window to let another one open on top of it
	/// </summary>
	void Close() override;
#pragma endregion

};

