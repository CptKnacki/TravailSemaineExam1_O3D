#include <iostream>
#include "Object.h"
#include "Window.h"
#include "MainMenu.h"
#include "DataBase.h"
#include "BookingMenu.h"

int main()
{
    Window _window = Window(L"Hotel O3D", 900, 800);
    _window.RegisterMenu(new BookingMenu(&_window));
    _window.SetCurrentMenu(BOOKINGMENU);
    _window.Open();

    return 0;
}
