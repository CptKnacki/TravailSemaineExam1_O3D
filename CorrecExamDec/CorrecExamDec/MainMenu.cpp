#include "MainMenu.h"
#include "DataBase.h"
#include "LabelControl.h"
#include "ButtonControl.h"
#include "Window.h"

MainMenu::MainMenu(Window* _owner) : super(_owner, MAINMENU) {}

void MainMenu::Initialize()
{
	HWND _instance = owner->WindowInstance();
	super::Initialize();

	CreateButton(Rect(60, 50, 200, 20), TEXT("Create Booking"));
	CreateButton(Rect(280, 50, 200, 20), TEXT("View Booking"));

	isInitialized = true;
	Close();
}
