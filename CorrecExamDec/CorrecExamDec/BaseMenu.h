#pragma once
#include "Object.h"
#include "Rect.h"
#include <vector>

class Window;
class WindowControl;

class BaseMenu : public Object
{
	DECLARE_CLASS_INFO(Object)

#pragma region f/p
protected:
	static inline int currentControlID = 0;

protected:
	const char* name = "";
	bool isInitialized = false;
	Window* owner = nullptr;
	std::vector<WindowControl*> controls = std::vector<WindowControl*>();
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
	void CreateButton(const Rect& _rect, const wchar_t* text);
	void CreateLabel(const Rect& _rect, const wchar_t* text);
	void CreateTextField(const Rect& _rect, const wchar_t* _defaulttext);
	class CalendarControl* CreateCalendar(const Rect& _rect);
#pragma endregion
};

