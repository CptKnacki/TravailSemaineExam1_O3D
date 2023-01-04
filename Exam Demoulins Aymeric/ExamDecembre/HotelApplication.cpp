#include "HotelApplication.h"
#include "Booking.h"
#include "Window.h"
#include "AddBookingWindow.h"
#include "BookingWindow.h"
#include "MainMenuWindow.h"
#include "ShowBookingWindow.h"

LRESULT WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(_hwnd, &ps);
	RECT _rect = RECT(tagRECT(0,0,1600,900));

	FillRect(hdc, &_rect, (HBRUSH)(CreateSolidBrush(RGB(240, 240, 240))));

	EndPaint(_hwnd, &ps);

	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);

}

#pragma region Constructor

HotelApplication::HotelApplication()
{
	const wchar_t CLASS_NAME[] = L"Sample Window Class";

	WNDCLASS wc = { };
	HINSTANCE hInstance = HINSTANCE();

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Hotel Application",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,

		0,
		0,
		1600,
		900,

		NULL,
		NULL,
		hInstance,
		NULL
	); // Window //

	window = hwnd;
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
	return 1;
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
	return 1;
}

void HotelApplication::ShowAddMenu()
{

	Booking _newBooking = addBooking.GetInstance()->Show(window);

	if (_newBooking.GetFirstName() != "FALSE_BOOKING")
		CreateBooking(_newBooking);
	
	ShowMainMenu();
}

void HotelApplication::ShowMainMenu()
{
	int _result = mainMenu.GetInstance()->Show(window);


	switch (_result)
	{
	case 1:
		ShowAddMenu();
		break;

	case 2:
		ShowAllBookings();
		break;

	default:
		ShowMainMenu();
	}
}

void HotelApplication::ShowAllBookings()
{
	int _result = showAllBookings.GetInstance()->Show(window, bookingsList);

	if (_result > 1)
		ShowBooking(_result - 2);
	else
		ShowMainMenu();
}

void HotelApplication::ShowBooking(int _index)
{
	if (_index < 0 || _index > bookingsList.size()) ShowMainMenu();

	Booking _booking = bookingsList[_index];
	int _result = showBooking.GetInstance()->Show(window, _booking.GetFirstName(), _booking.GetLastName(), _booking.GetNumberOfGuests(), _booking.GetArrivalDate(), _booking.GetDepartureDate());

	if (_result == 2)
		DeleteBooking(_index);

	ShowMainMenu();
}

#pragma endregion


