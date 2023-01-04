#include "BookingWindow.h"
#include <CommCtrl.h> // Librairie pour le calendrier //
#include <format>

#pragma region Constructor

BookingWindow::BookingWindow(const std::string _title) : Window(_title)
{
}

#pragma endregion

#pragma region Methods

int BookingWindow::Show(HWND _window, std::string _firstName, std::string _lastName, int _peopleNmbr, Date& _arrivalDate, Date& _departureDate)
{

    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(_window, &ps);


    HWND hwndButton1 = CreateWindow(
        WC_BUTTON,
        L"Return",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHLIKE,

        10,
        10,
        100,
        30,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Button 1 //     

    HWND hwndButton2 = CreateWindow(
        WC_BUTTON,
        L"Delete",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        30,
        400,
        110,
        30,
        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Button 2 //      

    HWND hwndCal = CreateWindow(
        MONTHCAL_CLASS,
        L"OK",
        WS_VISIBLE | WS_CHILD | MCS_NOTODAY | MCS_MULTISELECT,
        10,
        200,
        250,
        150,
        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Calendar //         

    SYSTEMTIME lt;
    GetLocalTime(&lt);
    MonthCal_SetRange(hwndCal, GDTR_MIN, &lt);
    MonthCal_SetMaxSelCount(hwndCal, 100);

    // TODO make this work to highlight the booking duration //

    //SYSTEMTIME* _timeTab= new SYSTEMTIME[2];
    //_timeTab[0] = SYSTEMTIME(_arrivalDate.GetYear(), _arrivalDate.GetMonth(), _arrivalDate.GetDay());
    //_timeTab[1] = SYSTEMTIME(_departureDate.GetYear(), _departureDate.GetMonth(), _departureDate.GetDay());
    //
    //MonthCal_SetSelRange(hwndCal, &_timeTab);
    //MonthCal_SetMaxSelCount(hwndCal, 0);

    size_t _size1 = _firstName.size();
    size_t _size2 = _lastName.size();
    size_t _size3 = std::to_string(_peopleNmbr).size();
    size_t _size4 = _size1 + _size2 + 4;

    std::wstring _str1 = L"First name : " + std::wstring(_firstName.begin(), _firstName.end());
    std::wstring _str2 = L"Last name : " + std::wstring(_lastName.begin(), _lastName.end());
    std::wstring _str3 = L"People number : " + std::to_wstring(_peopleNmbr);

    std::string _end1 = " //";
    std::wstring _end2 = std::wstring(_end1.begin(), _end1.end());

    std::wstring _str4 = L"// Booking of : " + std::wstring(_firstName.begin(), _firstName.end()) + L" " + std::wstring(_lastName.begin(), _lastName.end()) + _end2;

    LPCWSTR _LasName(_str2.c_str());

    HWND hwndStatic1 = CreateWindow(
        L"Static",
        _str1.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        10,
        100,
        200,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 1 // 

    HWND hwndStatic2 = CreateWindow(
        L"Static",
        _str2.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        10,
        130,
        200,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 2 // 

    HWND hwndStatic3 = CreateWindow(
        L"Static",
        _str3.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        10,
        160,
        150,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 3 // 

    HWND hwndStatic4 = CreateWindow(
        L"Static",
        _str4.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        300,
        10,
        300,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 4 // 


    int _numberOfDays = _departureDate.GetTotalOfDays() - _arrivalDate.GetTotalOfDays() + 1;

    std::wstring _arrivalSTR = L"Arrival date : " + std::to_wstring(_arrivalDate.GetDay()) + L"/" + std::to_wstring(_arrivalDate.GetMonth()) + L"/" + std::to_wstring(_arrivalDate.GetYear());
    std::wstring _departureSTR = L"Departure date : " + std::to_wstring(_departureDate.GetDay()) + L"/" + std::to_wstring(_departureDate.GetMonth()) + L"/" + std::to_wstring(_departureDate.GetYear());
    std::wstring _bookingDuration = L"Booking duration : " + std::to_wstring(_numberOfDays) + L" days";

    HWND hwndStatic5 = CreateWindow(
        L"Static",
        _arrivalSTR.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        280,
        200,
        200,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 5 // 

    HWND hwndStatic6 = CreateWindow(
        L"Static",
        _departureSTR.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        280,
        230,
        200,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 6 // 

    HWND hwndStatic7 = CreateWindow(
        L"Static",
        _bookingDuration.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        280,
        260,
        200,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 7 // 
    ShowWindow(_window, SW_SHOW);

    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        if (SendMessage(hwndButton1, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);
            ShowWindow(hwndCal, SW_HIDE);

            ShowWindow(hwndStatic1, SW_HIDE);
            ShowWindow(hwndStatic2, SW_HIDE);
            ShowWindow(hwndStatic3, SW_HIDE);
            ShowWindow(hwndStatic4, SW_HIDE);

            ShowWindow(hwndStatic5, SW_HIDE);
            ShowWindow(hwndStatic6, SW_HIDE);
            ShowWindow(hwndStatic7, SW_HIDE);

            UpdateWindow(_window);
       
            return 1;
        }

        if (SendMessage(hwndButton2, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);
            ShowWindow(hwndCal, SW_HIDE);

            ShowWindow(hwndStatic1, SW_HIDE);
            ShowWindow(hwndStatic2, SW_HIDE);
            ShowWindow(hwndStatic3, SW_HIDE);
            ShowWindow(hwndStatic4, SW_HIDE);

            ShowWindow(hwndStatic5, SW_HIDE);
            ShowWindow(hwndStatic6, SW_HIDE);
            ShowWindow(hwndStatic7, SW_HIDE);

            UpdateWindow(_window);

            return 2;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DestroyWindow(_window);
}

#pragma endregion