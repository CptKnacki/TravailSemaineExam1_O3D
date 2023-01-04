#pragma once
#include "WindowControl.h"
#include "Delegate.h"
#include <map>


class LabelControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

#pragma region f/p

private:
	const wchar_t* text = TEXT("Default");
public:
	Delegate<void> OnClick = nullptr;
#pragma endregion

#pragma region Constructor
public:
	LabelControl() = default;
	LabelControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text);
	LabelControl(const LabelControl& _copy);

#pragma endregion

#pragma region Methods
public:
	std::string TextStr();
	std::wstring Text();
	void SetText(const wchar_t* _newText);
	void SetText(const std::string& _str);
#pragma endregion

#pragma region Override
	HWND Create() override;
#pragma endregion
};

