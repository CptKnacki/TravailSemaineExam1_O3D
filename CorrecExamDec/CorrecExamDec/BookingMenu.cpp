#include "BookingMenu.h"
#include "DataBase.h"
#include "CalendarControl.h"

BookingMenu::BookingMenu(Window* _owner) : super(_owner, BOOKINGMENU)
{
}

void BookingMenu::Initialize()
{
	super::Initialize();
	CreateTextField(Rect(10, 50 ,255, 20), L"first name...");
	CreateTextField(Rect(10, 80 ,255, 20), L"last name...");
	CreateTextField(Rect(10, 110 ,255, 20), L"number of people...");

	CalendarControl* _calendar = CreateCalendar(Rect(10, 140, 170, 160));
	// _calendar->SetMaxSelected(15);

	CreateButton(Rect(60, 320, 150, 40), L"Save Booking");

	isInitialized = true;
	Close();
}
