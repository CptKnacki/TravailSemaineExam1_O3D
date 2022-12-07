#include "BookingWindow.h"
#include <CommCtrl.h> // Librairie pour le calendrier //
#include <format>


#pragma region Constructor

BookingWindow::BookingWindow(const std::string _title) : Window(_title)
{
}

#pragma endregion


#pragma region Override

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
        230,
        250,
        150,
        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Calendar //         

    MonthCal_SetMaxSelCount(hwndCal, 100);

    LPSYSTEMTIME _time = new SYSTEMTIME[2];

    //_time[0] = SYSTEMTIME(_arrivalDate.GetYear(), _arrivalDate.GetMonth(), _arrivalDate.GetDay());
    //_time[1] = SYSTEMTIME(_departureDate.GetYear(), _departureDate.GetMonth(), _departureDate.GetDay());

    _time[0] = SYSTEMTIME(2022, 12, 07);
    _time[1] = SYSTEMTIME(9998, 12, 31);

    //MonthCal_SetCurSel(hwndCal, _time);

    MonthCal_SetRange(hwndCal, GDTR_MIN | GDTR_MAX, _time);


    size_t _size1 = _firstName.size();
    size_t _size2 = _lastName.size();
    size_t _size3 = _size1 + _size2 + 4;

    std::wstring _str1 = std::wstring(_firstName.begin(), _firstName.end());
    std::wstring _str2 = std::wstring(_lastName.begin(), _lastName.end());
    std::wstring _str3 = std::to_wstring(_peopleNmbr);

    std::string _end1 = " //";
    std::wstring _end2 = std::wstring(_end1.begin(), _end1.end());

    std::wstring _str4 = _str1 + (wchar_t)' ' + _str2 + _end2;
   
    LPCWSTR _LasName(_str2.c_str());

    TextOut(hdc, 10, 100, L"First name : ", 14); // Text 1 //
    TextOut(hdc, 100, 100, _str1.c_str(), _size1); // Answer Text 1 //

    TextOut(hdc, 10, 130, L"Last name : ", 13); // Text 2 //
    TextOut(hdc, 100, 130, _str2.c_str(), _size2); // Answer Text 2 //

    TextOut(hdc, 10, 180, L"People number : ", 17); // Text 3 //
    TextOut(hdc, 130, 180, _str3.c_str(), _str3.size()); // Answer Text 3 //

    TextOut(hdc, 300, 10, L"// Booking of : ", 17); // Title //
    TextOut(hdc, 395, 10, _str4.c_str(), _str4.size()); // Title Completion//


    ShowWindow(_window, SW_SHOW);

    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        if (SendMessage(hwndButton1, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);
            ShowWindow(hwndCal, SW_HIDE);

            UpdateWindow(_window);

            return 1;
        }

        if (SendMessage(hwndButton2, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);
            ShowWindow(hwndCal, SW_HIDE);

            UpdateWindow(_window);

            return 2;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DestroyWindow(_window);
}

#pragma endregion