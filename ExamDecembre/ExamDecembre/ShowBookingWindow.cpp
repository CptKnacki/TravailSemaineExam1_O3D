#include "ShowBookingWindow.h"

#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h> // Librairie pour le calendrier //
#include <map>

#pragma region Constructor

ShowBookingWindow::ShowBookingWindow(const std::string _title) : Window(_title)
{
}


#pragma endregion


#pragma region Override

int ShowBookingWindow::Show(HWND _window, std::vector<Booking> _bookings)
{

    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(_window, &ps);

    HWND hwndButton1 = CreateWindow(
        L"BUTTON",
        L"Return",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHLIKE,

        10,
        10,
        100,
        25,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Button 1 //     

    size_t _size = _bookings.size();
    std::vector<HWND> _buttonList = std::vector<HWND>();

    if (_size == 0)
    {
        TextOut(hdc, 30, 50, L"No bookings...", 15); // Title //
    }
    else
    {

        HWND hwndButtonlist = HWND();
        
        int _width = 300;
        int _height = 25;
        int _posX = 20;
        int _posY = 50;
        int _indexTriple = 0;


        for (size_t i = 0; i < _size; i++)
        {
            
            std::string _temp1 = _bookings[i].GetFirstName();
            std::string _temp2 = _bookings[i].GetLastName();

            std::wstring _str1 = std::wstring(_temp1.begin(), _temp1.end());
            std::wstring _str2 = std::wstring(_temp2.begin(), _temp2.end());
            std::wstring _str3 = _str1 + (wchar_t)' ' + _str2;

                hwndButtonlist = CreateWindow(
                L"BUTTON",
                _str3.c_str(),
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | TBSTATE_ELLIPSES,
                _posX,
                _posY,
                _width,
                _height,

                _window,
                NULL,
                (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
                NULL
            ); // Button Booking //   

            _buttonList.push_back(hwndButtonlist);

            _posX += 320;
            _indexTriple++;

            if (_indexTriple == 3)
            {
                _posX = 20;
                _posY += 60;
                _indexTriple = 0;
            }
        }
    }
            

    TextOut(hdc, 300, 10, L"// Booking View //", 19); // Title //

    ShowWindow(_window, SW_SHOW);

    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        if (SendMessage(hwndButton1, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);

            for (size_t i = 0; i < _size; i++)
                ShowWindow((HWND)_buttonList[i], SW_HIDE);
            
            UpdateWindow(_window);

            return 1;
        }

        for (size_t i = 0; i < _size; i++)
        {
            if(SendMessage((HWND)_buttonList[i], BM_GETSTATE, 0, 0) == 620)
            {
                ShowWindow(hwndButton1, SW_HIDE);

                for (size_t x = 0; x < _size; x++)
                    ShowWindow((HWND)_buttonList[x], SW_HIDE);

                UpdateWindow(_window);

                return i + 2;
            }
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DestroyWindow(_window);
}

#pragma endregion