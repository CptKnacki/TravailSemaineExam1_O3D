#include <iostream>
#include "Window.h"
#include "MainMenu.h"
#include "BookingMenu.h"
#include "BookingViewMenu.h"
#include "DataBase.h"

int main()
{
	Window win = Window(L"Hotel O3D", 900, 800);
	win.RegisterMenu(new MainMenu(&win));
	win.RegisterMenu(new BookingMenu(&win));
	win.RegisterMenu(new BookingViewMenu(&win));
	win.SetCurrentMenu(MAINMENU);

	win.Open();

	return 0;
}
