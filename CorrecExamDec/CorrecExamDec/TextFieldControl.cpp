#include "TextFieldControl.h"


#pragma region Constructor
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

#pragma endregion

#pragma region Methods

void TextFieldControl::OnValueChange()
{
    const int _length = GetWindowTextLength(instance) + 1;
    char* _array = new char[_length];
    GetWindowTextA(instance, &_array[0], _length);
    std::string _result = _array;
    currentText = std::wstring(_result.begin(), _result.end());
}

std::wstring TextFieldControl::CurrentText() const
{
    return currentText;
}

std::string TextFieldControl::CurrentTextStr() const
{
    return std::string(currentText.begin(), currentText.end());
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
