#pragma once
#include "WindowControl.h"
#include "Delegate.h"
#include <map>


class ButtonControl : public WindowControl
{
	DECLARE_CLASS_INFO(WindowControl)

#pragma region f/p
public:
	static inline std::map<int, ButtonControl*> buttons = std::map<int, ButtonControl*>();

private:
	const wchar_t* text = TEXT("Default");
public:
	Delegate<void> OnClick = nullptr;
#pragma endregion

#pragma region Constructor
public:
	ButtonControl() = default;
	ButtonControl(int _controlID, HWND _owner, const Rect& _rect, const wchar_t* _text);
	ButtonControl(const ButtonControl& _copy);

#pragma endregion

#pragma region Override
	HWND Create() override;
#pragma endregion
};

