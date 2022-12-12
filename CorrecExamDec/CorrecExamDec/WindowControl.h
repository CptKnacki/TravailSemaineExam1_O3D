#pragma once
#include "Rect.h"
#include "Object.h"
#include <Windows.h>

class WindowControl : public Object
{
	DECLARE_CLASS_INFO(Object)

#pragma region f/p
protected:
	int controlID = 0;
	HWND owner = nullptr;
	HWND instance = nullptr;
	HINSTANCE ownerInstance;
	bool isInitialized = false;
	bool isShow = true;
	Rect rect = Rect();

#pragma endregion

#pragma region Constructor
public:
	WindowControl() = default;
	WindowControl(int _controlID, HWND _owner, const Rect& _rect);
	WindowControl(const WindowControl& _copy);
#pragma endregion

#pragma region Methods
public:
	void Show();
	void Hide();
	virtual HWND Create();
	bool IsInitialized() const;
#pragma endregion

};

