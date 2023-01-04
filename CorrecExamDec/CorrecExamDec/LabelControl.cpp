#include "LabelControl.h"

#pragma region Constructor

LabelControl::LabelControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text) : super(_controlID, _owner, _rect)
{
	text = _text;
}

LabelControl::LabelControl(const LabelControl& _copy) : super(_copy)
{
	text = _copy.text;
}

#pragma endregion

#pragma region Override

std::string LabelControl::TextStr()
{
	const std::wstring _text = Text();
	return std::string(_text.begin(), _text.end());
}

std::wstring LabelControl::Text()
{
	return text;
}

void LabelControl::SetText(const wchar_t* _newText)
{
	text = _newText;
}

void LabelControl::SetText(const std::string& _str)
{
	const std::wstring _wstr(_str.begin(), _str.end());
	SetText(_wstr.c_str());
}

HWND LabelControl::Create()
{
	instance = CreateWindow(TEXT("STATIC"), text, WS_VISIBLE | WS_CHILD,
		rect.X(), rect.Y(), rect.Width(), rect.Height(), owner, (HMENU)controlID, ownerInstance, NULL);

	if (instance != NULL)
	{
		isInitialized = true;
		Show();
	}

	return instance;
}

#pragma endregion
