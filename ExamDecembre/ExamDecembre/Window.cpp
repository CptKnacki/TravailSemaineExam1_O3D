#include "Window.h"
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h> // Librairie pour le calendrier //

#pragma region Constructor

Window::Window(const std::string _title)
{
	title = _title;
}

Window::Window(const Window& _copy)
{
	title = _copy.title;
}

#pragma endregion

#pragma region Methods

    LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.

            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
        }
        return 0;

        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

void Window::Show()
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };
    HINSTANCE hInstance = HINSTANCE();

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Hotel Application",           // Window text
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,            // Window style

        
        0, // posX
        0, // posY
        1600, // width
        900, // length

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );


    HWND hwndButton1 = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"OK",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD   | BS_PUSHLIKE,  // Styles 
        10,         // x position 
        10,         // y position 
        100,        // Button width
        30,        // Button height
        hwnd,     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.

    HWND hwndButton2 = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"OK",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD  ,  // Styles 
        150,         // x position 
        10,         // y position 
        100,        // Button width
        30,        // Button height
        hwnd,     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.

    HWND hwndCal = CreateWindow(
        MONTHCAL_CLASS,  // Predefined class; Unicode assumed 
        L"OK",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | MCS_NOTODAY,  // Styles 
        10,         // x position 
        50,         // y position 
        250,        // Button width
        150,        // Button height
        hwnd,     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.

    HWND hwndText = CreateWindow(
        L"TextBox",  // Predefined class; Unicode assumed 
        L"OK",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD,  // Styles 
        400,         // x position 
        10,         // y position 
        100,        // Button width
        30,        // Button height
        hwnd,     // Parent window
        NULL,       // No menu.
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.


    ShowWindow(hwnd, SW_SHOW);
   
    MSG msg = {};

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DestroyWindow(hwnd);
}

void Window::Close()
{
}

std::string Window::GetTitle()
{
	return title;
}

#pragma endregion


