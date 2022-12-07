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


#pragma region Override

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



    HWND hwndText = CreateWindow(
        L"Edit", 
        L"first name...",      
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,  

        150,       
        100,       
        100,       
        20,  

        _window,     
        NULL,  
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Edit Text Zone 1 //      

    HWND hwndText2 = CreateWindow(
        L"Edit", 
        L"last name...",     
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        150,       
        130,       
        100,       
        20, 

        _window,     
        NULL,  
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Edit Text Zone 2 //     

    HWND hwndText3 = CreateWindow(
        L"Edit",    
        L"2",      
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        180,        
        180,        
        100,        
        20,    

        _window,     
        NULL,   
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Edit Text Zone 3 //      

    MonthCal_SetMaxSelCount(hwndCal, 100);

    TextOut(hdc, 20, 100, L"Enter first name : ", 20); // Text 1 //
    TextOut(hdc, 20, 130, L"Enter last name : ", 19); // Text 2 //

    TextOut(hdc, 20, 180, L"For how many people : ", 23); // Text 3 //

    TextOut(hdc, 300, 10, L"// Create New Booking //", 25); // Title //


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

            ShowWindow(hwndCal, SW_HIDE);


            UpdateWindow(_window);

            TextOut(hdc, 300, 10, L"// Hotel Objectif3D //", 23); // Title //

            return Booking("FALSE_BOOKING", "FALSE_BOOKING", 0, Date(), Date());
        }

        if (SendMessage(hwndButton2, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);

            ShowWindow(hwndText, SW_HIDE);
            ShowWindow(hwndText2, SW_HIDE);
            ShowWindow(hwndText3, SW_HIDE);

            ShowWindow(hwndCal, SW_HIDE);

            TCHAR _firstNameValue[20];
            TCHAR _lastNameValue[20];
            TCHAR _guestNmbrValue[20];

            GetWindowText(hwndText, _firstNameValue, 20);
            GetWindowText(hwndText2, _lastNameValue, 20);
            GetWindowText(hwndText3, _guestNmbrValue, 20);

            std::string _firNameString = "";
            std::string _lasNameString = "";
            std::string _gueNmbrString = "";

            for (size_t i = 0; i < 20; i++)
            {
                _firNameString += _firstNameValue[i];
                _lasNameString += _lastNameValue[i];
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

   

            return _newBooking;
        }


        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

    DestroyWindow(_window);
}



#pragma endregion