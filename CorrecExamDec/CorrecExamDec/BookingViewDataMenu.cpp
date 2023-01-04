#include "BookingViewDataMenu.h"
#include "DataBase.h"
#include "BookingViewMenu.h"
#include "BookingManager.h"
#include "ButtonControl.h"
#include "Window.h"
#include "Booking.h"
#include "CalendarControl.h"
#include "LabelControl.h"
#include "Client.h"

#pragma region Constructor

BookingViewDataMenu::BookingViewDataMenu(Window* _owner) : super(_owner, BOOKINGVIEWDATAMENU)
{

}

#pragma endregion

#pragma region Methods

void BookingViewDataMenu::Delete()
{
	BookingManager::Instance()->DeleteBoooking(BookingViewMenu::CurrentBooking);
	ReturnToBookingView();
}

void BookingViewDataMenu::ReturnToBookingView()
{
	owner->SetCurrentMenu(BOOKINGVIEWMENU);
}


#pragma endregion


#pragma region Override

void BookingViewDataMenu::Initialize()
{
	super::Initialize();
	ButtonControl* _returnControl = CreateButton(Rect(10 , 0 , 100, 20), TEXT("Return"));
	_returnControl->OnClick.SetDynamic(this, &BookingViewDataMenu::ReturnToBookingView);

	firstName = CreateLabel(Rect(10, 60, 250, 20), L"");
	lastName = CreateLabel(Rect(10, 90, 250, 20), L"");
	numberOfPeople = CreateLabel(Rect(10, 120, 250, 20), L"");
	calendar = CreateCalendar(Rect(10, 160, 200, 100));

	ButtonControl* _deleteControl = CreateButton(Rect(10, 360, 100, 20), TEXT("Delete"));
	_deleteControl->OnClick.SetDynamic(this, &BookingViewDataMenu::Delete);

	isInitialized = true;
	Close();

}

void BookingViewDataMenu::Open()
{
	const Booking* _current = BookingViewMenu::CurrentBooking;
	if (_current == nullptr)
	{
		ReturnToBookingView();
		return;
	}

	const Client _client = _current->GetClient();
	firstName->SetText("First name : " + _client.FirstName());
	lastName->SetText("Last Name : " + _client.LastName());
	numberOfPeople->SetText("Numer of people : " + std::to_string(_client.NumberOfClient()));
	calendar->SetValue(_current->ArrivedDate(), _current->DepartureDate());
	titleControl->SetText(_client.FirstName() + " " + _client.LastName());
	super::Open();
}

#pragma endregion

