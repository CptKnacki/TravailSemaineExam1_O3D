#pragma once
#include "Window.h"
#include "Date.h"

class BookingWindow : public Window
{
#pragma region f/p
private:

#pragma endregion

#pragma region Constructor
public:
	BookingWindow(const std::string _title = "Booking of : ");
#pragma endregion

#pragma region Methods
public:

	/// <summary>
	/// 	Used to display a booking window with bookings information, it contains the three main client's informations in text
	///		 and a calendar with the client's schedule highlighted
	/// </summary>
	/// <param name="_firstName"> first name of the client </param>
	/// <param name="_lastName"> last name of the client </param>
	/// <param name="_peopleNmbr"> number of people for the booking </param>
	/// <param name="_arrivalDate"> arrival date </param>
	/// <param name="_departureDate"> departure date </param>
	int Show(HWND _window, std::string _firstName, std::string _lastName, int _peopleNmbr, Date& _arrivalDate, Date& _departureDate);
 
#pragma endregion

};

