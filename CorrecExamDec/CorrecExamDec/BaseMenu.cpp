#include "BaseMenu.h"
#include "WindowControl.h"
#include "Window.h"
#include "ButtonControl.h"
#include "LabelControl.h"
#include "DataBase.h"
#include "TextFieldControl.h"
#include "CalendarControl.h"
#pragma region Constructor

BaseMenu::BaseMenu(Window* _owner, const char* _name) : super()
{
	owner = _owner;
	name = _name;
}

BaseMenu::BaseMenu(const BaseMenu& _copy) : super(_copy)
{
	owner = _copy.owner;
	name = _copy.name;
}


#pragma endregion


#pragma region Methods

bool BaseMenu::IsInitialized() const
{
	return isInitialized;
}

void BaseMenu::Open()
{
	if (!isInitialized) return;
	for (WindowControl* _control : controls)
		_control->Show();
}

void BaseMenu::Close()
{
	if (!isInitialized) return;
	for (WindowControl* _control : controls)
		_control->Hide();
}

void BaseMenu::Initialize()
{
	isInitialized = true;

	std::string _str = name;
	std::wstring _wstr(_str.begin(), _str.end());
	CreateLabel(Rect(owner->Width() / 2, 0, 255, 20), _wstr.c_str());
}

std::string BaseMenu::Name() const
{
	return name;
}

void BaseMenu::CreateButton(const Rect& _rect, const wchar_t* text)
{
	ButtonControl* _button = new ButtonControl(currentControlID++, owner->WindowInstance(), _rect, text);
	_button->Create();
	controls.push_back(_button);
}

void BaseMenu::CreateLabel(const Rect& _rect, const wchar_t* text)
{
	LabelControl* _label = new LabelControl(currentControlID++, owner->WindowInstance(), _rect, text);
	_label->Create();
	controls.push_back(_label);
}

void BaseMenu::CreateTextField(const Rect& _rect, const wchar_t* _defaulttext)
{
	TextFieldControl* _textField = new TextFieldControl(currentControlID++, owner->WindowInstance(), _rect, _defaulttext);
	_textField->Create();
	controls.push_back(_textField);
}

CalendarControl* BaseMenu::CreateCalendar(const Rect& _rect)
{
	CalendarControl* _calendar = new CalendarControl(currentControlID++, owner->WindowInstance(), _rect);
	_calendar->Create();
	controls.push_back(_calendar);
	return _calendar;
}

#pragma endregion
