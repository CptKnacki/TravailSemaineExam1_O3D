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

    //HotelApplication _hotel1;
    //
    //Date _date1 = Date(5, 12, 2022);
    //Date _date2 = Date(15, 12, 2022);
    //
    //Date _date3 = Date(21, 01, 2023);
    //Date _date4 = Date(31, 01, 2023);
    //
    //Booking _booking1 = Booking("Demoulins", "Aymeric", 4, _date1, _date2);
    //
    //_hotel1.CreateBooking(_booking1);
    //_hotel1.CreateBooking("Terrieur", "Alain", 2, _date3, _date4);
    //
    //_hotel1.DeleteBooking(1);
    //_hotel1.DeleteBooking(0);

    //MainMenuWindow _window;
    //BookingWindow _window;
    //ShowBookingWindow _window;
    //AddBookingWindow _window;


    //_window.Show();

    HotelApplication _hotel1 = HotelApplication();

    Booking _booking1("Demoulins", "Aymeric", 2, Date(7,12,2022), Date(15,12,2022));
    Booking _booking2("Terrieur", "Alain", 5, Date(16,12,2022), Date(31,12,2022));
    //Booking _booking3("Terrieur", "Alex", 3, Date(21,1,2023), Date(25,1,2023));
    //Booking _booking4("Onette", "Camille", 2, Date(13,2,2023), Date(27,2,2023));
    //Booking _booking5("Koidal", "Elie", 2, Date(13,2,2023), Date(27,2,2023));
    //Booking _booking6("Nouie", "Eva", 2, Date(13,2,2023), Date(27,2,2023));
    //Booking _booking7("Vedertchi", "Harry", 2, Date(13,2,2023), Date(27,2,2023));

    _hotel1.CreateBooking(_booking1);
    _hotel1.CreateBooking(_booking2);
 
    _hotel1.ShowBooking(0);

    std::cout << "Hello World!\n";

    return 0;
}

