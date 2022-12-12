#pragma once
#include "Object.h"
#include <windows.h>
#pragma comment(lib, "Comctl32.lib")
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h>
#include <map>

class BaseMenu;

class Window : public Object
{
	DECLARE_CLASS_INFO(Object)

#pragma region f/p
private:
	HWND windowInstance = nullptr;
	HINSTANCE hInstance = HINSTANCE();
	const wchar_t* title = TEXT("Default Window");
	int width = 1920;
	int height = 1080;
	bool isOpen = false;
	BaseMenu* currentMenu = nullptr;
	std::map<std::string, BaseMenu*> menus = std::map<std::string, BaseMenu*>();
#pragma endregion

#pragma region Constructor
public:
	Window() = default;
	Window(const wchar_t* _title, int _width = 1920 , int _height = 1080);
	~Window() override;
#pragma endregion

#pragma region Proc
	static LRESULT __stdcall WindowProcInternal(HWND _window, UINT _msg, WPARAM _wparam, LPARAM _lparam);
	LRESULT __stdcall WindowProc(HWND _window, UINT _msg, WPARAM _wparam, LPARAM _lparam);
#pragma endregion

#pragma region Methods
public:
	void Open();
	void Close();
	void Update();
	void RegisterMenu(BaseMenu* _menu);
	void SetCurrentMenu(const char* _menuName);
	int Width() const;
	int Height() const;
	HWND WindowInstance() const;
#pragma endregion

};

