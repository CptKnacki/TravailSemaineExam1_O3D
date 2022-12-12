#include "WindowControl.h"

#pragma region Constructor

WindowControl::WindowControl(int _controlID, HWND _owner, const Rect& _rect) : super()
{
	controlID = _controlID;
	owner = _owner;
	ownerInstance = (HINSTANCE)GetWindowLongPtr(owner, GWLP_HINSTANCE);
	rect = _rect;
}

WindowControl::WindowControl(const WindowControl& _copy) : super(_copy)
{
	controlID = _copy.controlID;
	owner = _copy.owner;
	ownerInstance = _copy.ownerInstance;
	rect = _copy.rect;
}


#pragma endregion

#pragma region Methods

void WindowControl::Show()
{
	if (!isInitialized) return;
	ShowWindow(instance, true);
	isShow = true;
}

void WindowControl::Hide()
{
	if (!isInitialized) return;
	ShowWindow(instance, false);
	isShow = false;
}

HWND WindowControl::Create()
{
	return HWND();
}

bool WindowControl::IsInitialized() const
{
	return isInitialized;
}

#pragma endregion
