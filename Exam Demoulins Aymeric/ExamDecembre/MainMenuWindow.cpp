#include "MainMenuWindow.h"


#pragma region Constructor

MainMenuWindow::MainMenuWindow(const std::string _title) : Window(_title)
{
}

#pragma endregion


#pragma region Methods

int MainMenuWindow::Show(HWND _window)
{

    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(_window, &ps);

    HWND hwndButton1 = CreateWindow(
        L"BUTTON",
        L"Create new Booking",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHLIKE,

        30,
        70,
        150,
        30,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Button 1 //     

    HWND hwndButton2 = CreateWindow(
        L"BUTTON",
        L"View all Bookings",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        200,
        70,
        150,
        30,
        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Button 2 //          

    HWND hwndStatic1 = CreateWindow(
        L"Static",
        L"// Hotel Objectif3D //",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,

        300,
        10,
        140,
        20,

        _window,
        NULL,
        (HINSTANCE)GetWindowLongPtr(_window, GWLP_HINSTANCE),
        NULL
    ); // Static Zone 1 // 


    ShowWindow(_window, SW_SHOW);

    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        if (SendMessage(hwndButton1, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);

            ShowWindow(hwndStatic1, SW_HIDE);

            UpdateWindow(_window);

            return 1;

        }

        if (SendMessage(hwndButton2, BM_GETSTATE, 0, 0) == 620)
        {
            ShowWindow(hwndButton1, SW_HIDE);
            ShowWindow(hwndButton2, SW_HIDE);

            ShowWindow(hwndStatic1, SW_HIDE);

            UpdateWindow(_window);

            return 2;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DestroyWindow(_window);
}

#pragma endregion