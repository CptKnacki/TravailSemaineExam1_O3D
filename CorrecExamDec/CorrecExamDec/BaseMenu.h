#pragma once
#include "Object.h"
#include "Rect.h"
#include <vector>

class Window;
class WindowControl;
class LabelControl;

class BaseMenu : public Object
{
	DECLARE_CLASS_INFO(Object)

#pragma region f/p
protected:
	static inline int currentControlID = 0;
	const char* name = "";
	bool isInitialized = false;
	Window* owner = nullptr;
	std::vector<WindowControl*> controls = std::vector<WindowControl*>();
	LabelControl* titleControl = nullptr;
#pragma endregion

#pragma region Constructor
public:
	BaseMenu() = default;
	BaseMenu(Window* _owner, const char* name);
	BaseMenu(const BaseMenu& _copy);
#pragma endregion

#pragma region Methods
public:
	bool IsInitialized() const;
	virtual void Open();
	virtual void Close();
	virtual void Initialize();
	std::string Name() const;

protected:
	class ButtonControl* CreateButton(const Rect& _rect, const wchar_t* text);
	class LabelControl* CreateLabel(const Rect& _rect, const wchar_t* text);
	class TextFieldControl* CreateTextField(const Rect& _rect, const wchar_t* _defaulttext);
	class ButtonBookingControl* CreateBookingButton(const Rect& _rect, const wchar_t* _defaulttext, class Booking* _booking);
	class CalendarControl* CreateCalendar(const Rect& _rect);
#pragma endregion
};

