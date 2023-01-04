#include <iostream>
#include <Windows.h>

//#pragma comment(lib, "Comctl32.lib")
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
//#include <CommCtrl.h> // Librairie pour le calendrier //

#include "HotelApplication.h"
#include "Window.h"
#include "MainMenuWindow.h"
#include "BookingWindow.h"
#include "ShowBookingWindow.h"
#include "AddBookingWindow.h"


int main()
{

    HotelApplication _hotel1 = HotelApplication();

    Booking _booking1("Demoulins", "Aymeric", 2, Date(10,12,2022), Date(15,12,2022));

    _hotel1.CreateBooking(_booking1);
    _hotel1.ShowBooking(0);

    std::cout << "App ended !\n";

    return 0;
}

