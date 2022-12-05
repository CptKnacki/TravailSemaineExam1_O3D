#pragma once
#include "Window.h"

class BookingWindow : public Window
{
#pragma region f/p
private:

#pragma endregion

#pragma region Constructor
public:
	BookingWindow(const std::string _title = "Booking of : ");
#pragma endregion

#pragma region Override
public:

	/// <summary>
	///		Used to display a booking window with bookings information, it contains the three main client's informations in text
	///		 and a calendar with the client's schedule highlighted
	/// </summary>
	void Show() override;

	/// <summary>
	///		Used to close these window to let another one open on top of it
	/// </summary>
	void Close() override;
#pragma endregion

};

