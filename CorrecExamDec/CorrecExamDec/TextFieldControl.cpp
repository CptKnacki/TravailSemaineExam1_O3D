#include "TextFieldControl.h"

TextFieldControl::TextFieldControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _defaultText) : super(_controlID, _owner, _rect)
{
    defaultText = _defaultText;
    currentText = _defaultText;
}

TextFieldControl::TextFieldControl(const TextFieldControl& _copy) : super(_copy)
{
    defaultText = _copy.defaultText;
    currentText = _copy.defaultText;
}

std::wstring TextFieldControl::CurrentText() const
{
    return currentText;
}

void TextFieldControl::OnTextChange(const wchar_t* _text)
{
    currentText = _text;
}

HWND TextFieldControl::Create()
{
    instance = CreateWindowEx(0, TEXT("EDIT"), defaultText, WS_CHILD | WS_VISIBLE,
        rect.X(), rect.Y(), rect.Width(), rect.Height(), owner, (HMENU)controlID, ownerInstance, nullptr);
    if (instance != NULL)
    {
        isInitialized = true;
        textFields.insert(std::pair(controlID, this));
        Show();
    }
    return instance;
}
