#include "ButtonControl.h"

#pragma region Constructor

ButtonControl::ButtonControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text) : super(_controlID, _owner, _rect)
{
	text = _text;
}

ButtonControl::ButtonControl(const ButtonControl& _copy) : super(_copy)
{
	text = _copy.text;
}

void ButtonControl::OnUse()
{
	OnClick.Invoke();
}

HWND ButtonControl::Create()
{
	instance = CreateWindow(TEXT("BUTTON"), text, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		rect.X(), rect.Y(), rect.Width(), rect.Height(), owner, (HMENU)controlID, ownerInstance, NULL);

	if (instance != NULL)
	{
		isInitialized = true;
		buttons.insert(std::pair(controlID, this));
		Show();
	}

	return instance;
}

#pragma endregion

