#include "Window.h"
#include "ButtonControl.h"
#include "LabelControl.h"
#include "TextFieldControl.h"
#include "BaseMenu.h"
#include "CalendarControl.h"
#include <ranges>
#include <format>
#include <iostream>

#pragma region Constructor

Window::Window(const wchar_t* _title, int _width, int _height)
{
	title = _title;
	width = _width;
	height = _height;

	INITCOMMONCONTROLSEX _iccex;
	_iccex.dwSize = sizeof(_iccex);
	_iccex.dwICC = ICC_DATE_CLASSES;

	if (!InitCommonControlsEx(&_iccex))
	{
		throw std::exception("[WINDOW] -> failed to initialize common controls !");
	}

	hInstance = GetModuleHandle(NULL);
	LPCWSTR _className = TEXT("Sample Window Class");
	WNDCLASS _wndClass = {};
	_wndClass.style = CS_HREDRAW | CS_VREDRAW;
	_wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	_wndClass.lpszClassName = _className;
	_wndClass.hInstance = hInstance;
	_wndClass.lpfnWndProc = WindowProcInternal;
	RegisterClass(&_wndClass);
	
	windowInstance = CreateWindowEx(WS_EX_APPWINDOW, _className, title, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, hInstance, this);

	std::wstring _wstr = title;
	std::string _titleCstr(_wstr.begin(), _wstr.end());
	SetWindowTextA(windowInstance, _titleCstr.c_str());

}

Window::~Window()
{
	for (BaseMenu* menu : menus | std::ranges::views::values)
		delete menu;
	menus.clear();
	if (isOpen)
		Close();
}

#pragma endregion

#pragma region Proc

LRESULT __stdcall Window::WindowProcInternal(HWND _window, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	if (_msg == WM_NCCREATE)
	{
		SetWindowLongPtr(_window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(_lparam)->lpCreateParams));
		return true;
	}
	return reinterpret_cast<Window*>(GetWindowLongPtr(_window, GWLP_USERDATA))->WindowProc(_window, _msg, _wparam, _lparam);
}

LRESULT __stdcall Window::WindowProc(HWND _window, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	if (_window == nullptr) return false;
	switch (_msg)
	{
	case WM_COMMAND:
	{
		if (!ButtonControl::buttons.contains(_wparam)) break;

		ButtonControl::buttons[_wparam]->OnUse();
		break;
	}
	case WM_NOTIFY:
	{
		LPNMHDR _lpm = (LPNMHDR) _lparam;
		switch (_lpm->code)
		{
		case MCN_SELECT:
		{
			std::map<int, CalendarControl*> _calendars = CalendarControl::calendars;
			for (std::pair<int, CalendarControl*> _pair : _calendars)
			{
				if (_pair.first == _wparam)
				{
					_pair.second->OnChoice((LPNMSELCHANGE)_lparam);
					break;
				}
			}
			break;
		}
		}
		break;

	}
	case WM_DESTROY:
	{
		isOpen = false;
		exit(0);
		break;
	}
	}
	return DefWindowProc(_window, _msg, _wparam, _lparam);
}

#pragma endregion


#pragma region Methods

void Window::Open()
{
	if (windowInstance == nullptr)
		throw std::exception("[WINDOW] -> window instance is null");

	ShowWindow(windowInstance, SW_SHOW);
	UpdateWindow(windowInstance);
	isOpen = true;
	Update();
}

void Window::Close()
{
	if (windowInstance == nullptr || !isOpen)
		throw std::exception("[WINDOW] -> window instance is already closed");

	isOpen = false;
}

void Window::Update()
{
	MSG _msg = {};

	while (isOpen)
	{
		try
		{

			while (PeekMessage(&_msg, windowInstance, 0, 0, PM_REMOVE))
			{
				if (!TranslateAccelerator(_msg.hwnd, nullptr, &_msg))
				{
					TranslateMessage(&_msg);
					DispatchMessage(&_msg);
				}
			}

		}
		catch (const std::exception& _e)
		{
			std::cout << _e.what() << std::endl;

		}
	}
}

void Window::RegisterMenu(BaseMenu* _menu)
{
	if (menus.contains(_menu->Name())) return;
	if (!_menu->IsInitialized()) _menu->Initialize();
	menus.insert(std::pair(_menu->Name(), _menu));
}

void Window::SetCurrentMenu(const char* _menuName)
{
	if (!menus.contains(_menuName))
		throw std::exception(std::format("[WINDOW] -> {} doesnt exist", _menuName).c_str());

	if (currentMenu != nullptr)
		currentMenu->Close();

	currentMenu = menus[_menuName];
	currentMenu->Open();
}

int Window::Width() const
{
	return width;
}

int Window::Height() const
{
	return height;
}

HWND Window::WindowInstance() const
{
	return windowInstance;
}

#pragma endregion
