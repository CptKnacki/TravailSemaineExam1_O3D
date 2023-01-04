#include "AddBookingWindow.h"

#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h> // Librairie pour le calendrier //
#include <vector>
#include <iostream>

#pragma region Constructor

AddBookingWindow::AddBookingWindow(const std::string _title) : Window(_title)
{
}

#pragma endregion


#pragma region Methods

Booking AddBookingWindow::Show(HWND _window)
{

    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(_window, &ps);

    MSG msg = {};

    HWND hwndButton1 = CreateWindow(
        WC_BUTTON, 
        L"Return",     
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,  

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
        L"Save Booking",    
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,  
        30,       
        400,       
        150,       
        40,        
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

    SYSTEMTIME lt;
    GetLocalTime(&lt);

    MonthCal_GetToday(hwndCal, &lt);
    MonthCal_SetRange(hwndCal, GDTR_MIN, &lt);

    HWND hwndText = CreateWindow(
        L"Edit", 
        L"first name...",      
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER,

        150,       
        100,       
        120,       
        20,  

        _window,     
        NULL,  
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Edit Text Zone 1 //      

    HWND hwndText2 = CreateWindow(
        L"Edit", 
        L"last name...",     
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER,

        150,       
        130,       
        120,       
        20, 

        _window,     
        NULL,  
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Edit Text Zone 2 //     

    HWND hwndText3 = CreateWindow(
        L"Edit",    
        L"2",      
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER,

        180,        
        180,        
        40,        
        20,    

        _window,     
        NULL,   
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Edit Text Zone 3 //      

    MonthCal_SetMaxSelCount(hwndCal, 100);

    HWND hwndStatic1 = CreateWindow(
        L"Static",
        L"Enter first name : ",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        20,
        100,
        110,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 1 // 
    
    HWND hwndStatic2 = CreateWindow(
        L"Static",
        L"Enter last name : ",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        20,
        130,
        110,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 2 // 

    HWND hwndStatic3 = CreateWindow(
        L"Static",
        L"For how many people : ",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        20,
        180,
        150,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 3 // 

    HWND hwndStatic4 = CreateWindow(
        L"Static",
        L"// Create New Booking //",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        300,
        10,
        160,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 4 // 

    

    ShowWindow(_window, SW_SHOW);

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {

        if (SendMessage(hwndButton1, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);

            ShowWindow(hwndText, SW_HIDE);
            ShowWindow(hwndText2, SW_HIDE);
            ShowWindow(hwndText3, SW_HIDE);

            ShowWindow(hwndStatic1, SW_HIDE);
            ShowWindow(hwndStatic2, SW_HIDE);
            ShowWindow(hwndStatic3, SW_HIDE);
            ShowWindow(hwndStatic4, SW_HIDE);

            ShowWindow(hwndCal, SW_HIDE);

            UpdateWindow(_window);

            return Booking("FALSE_BOOKING", "FALSE_BOOKING", 0, Date(), Date());
        }

        if (SendMessage(hwndButton2, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);

            ShowWindow(hwndText, SW_HIDE);
            ShowWindow(hwndText2, SW_HIDE);
            ShowWindow(hwndText3, SW_HIDE);

            ShowWindow(hwndStatic1, SW_HIDE);
            ShowWindow(hwndStatic2, SW_HIDE);
            ShowWindow(hwndStatic3, SW_HIDE);
            ShowWindow(hwndStatic4, SW_HIDE);

            ShowWindow(hwndCal, SW_HIDE);


            wchar_t _firstNameValue[20];
            wchar_t _lastNameValue[20];
            wchar_t _guestNmbrValue[5];

            GetWindowText(hwndText, _firstNameValue, 20);
            GetWindowText(hwndText2, _lastNameValue, 20);
            GetWindowText(hwndText3, _guestNmbrValue, 5);

            std::string _firNameString = "";
            std::string _lasNameString = "";
            std::string _gueNmbrString = "";

            for (size_t i = 0; i < 20; i++)
            {
                if (_firstNameValue[i] == '\0') break;
                _firNameString += _firstNameValue[i];
            }

            for (size_t i = 0; i < 20; i++)
            {
                if (_lastNameValue[i] == '\0') break;
                _lasNameString += _lastNameValue[i];
            }

            for (size_t i = 0; i < 20; i++)
            {
                if (_guestNmbrValue[i] == '\0') break;
                _gueNmbrString += _guestNmbrValue[i];
            }

            SYSTEMTIME* _time = new SYSTEMTIME[2];

            _time[0] = SYSTEMTIME(2022, 12, 7);
            _time[1] = SYSTEMTIME(2022, 12, 8);

            MonthCal_GetSelRange(hwndCal, _time);

            Booking _newBooking = Booking(_firNameString,
                                          _lasNameString,
                                          std::stoi(_gueNmbrString),
                                          Date(_time[0].wDay, _time[0].wMonth, _time[0].wYear),
                                          Date(_time[1].wDay, _time[1].wMonth, _time[1].wYear));

            UpdateWindow(_window);
            return _newBooking;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

    DestroyWindow(_window);
}



#pragma endregion