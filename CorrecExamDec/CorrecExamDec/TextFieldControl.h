#pragma once
#include "WindowControl.h"
#include <map>

class TextFieldControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

#pragma region f/p
public:
	static inline std::map<int, TextFieldControl*> textFields = std::map<int, TextFieldControl*>();
private:
	const wchar_t* defaultText = TEXT("");
	const wchar_t* currentText = TEXT("");

#pragma endregion


#pragma region Constructor
public:
	TextFieldControl() = default;
	TextFieldControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _defaultText);
	TextFieldControl(const TextFieldControl& _copy);

#pragma endregion


#pragma region Methods
public:
	std::wstring CurrentText() const;
	void OnTextChange(const wchar_t* _text);

#pragma endregion

#pragma region Override
public:
	HWND Create() override;
#pragma endregion
};

