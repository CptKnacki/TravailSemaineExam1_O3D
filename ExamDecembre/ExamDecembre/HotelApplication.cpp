#include "HotelApplication.h"
#include "Booking.h"
#include "Window.h"
#include "AddBookingWindow.h"
#include "BookingWindow.h"
#include "MainMenuWindow.h"
#include "ShowBookingWindow.h"

#pragma region Constructor

LRESULT WindowProc(HWND _hwnd, UINT _uMsg, WPARAM _wParam, LPARAM _lParam)
{
	switch (_uMsg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(_hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		//TextOut(hdc, 20, 100, L"Enter first name : ", 20); // Text 1 //
		//TextOut(hdc, 20, 130, L"Enter last name : ", 19); // Text 2 //

		//TextOut(hdc, 20, 180, L"For how many people : ", 23); // Text 3 //

		//TextOut(hdc, 300, 10, L"// Create New Booking //", 25); // Title //

		EndPaint(_hwnd, &ps);
	}
		break;

	default:
		break;
	}
	return DefWindowProc(_hwnd, _uMsg, _wParam, _lParam);
}

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
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(window, &ps);

		int _result = CreateBooking(_newBooking);

		 if(_result == 1) TextOut(hdc, 300, 60, L"/ Booking Sucessfully Created ! /", 34); // Title //
		 else TextOut(hdc, 300, 60, L"/ ERROR No Booking Created ! /", 31); // Title //
	}

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


	if (_result == 1)
		ShowMainMenu();
	else if (_result > 1)
		ShowBooking(_result - 2);
	else
		ShowMainMenu();
}

void HotelApplication::ShowBooking(int _index)
{
	if (_index < 0 || _index > bookingsList.size()) return;

	Booking _booking = bookingsList[_index];
	int _result = showBooking.GetInstance()->Show(window, _booking.GetFirstName(), _booking.GetLastName(), _booking.GetNumberOfGuests(), _booking.GetArrivalDate(), _booking.GetDepartureDate());

	if (_result == 2)
		DeleteBooking(_index);

	ShowMainMenu();
}
#pragma endregion


