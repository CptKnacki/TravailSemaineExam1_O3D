#pragma once
#include "Window.h"

class MainMenuWindow : public Window
{
#pragma region f/p
private:

#pragma endregion

#pragma region Constructor
public:
	MainMenuWindow(const std::string _title = "Hotel Objectif3D");
#pragma endregion

#pragma region Methods
public:
	/// <summary>
	///		Used to display the main menu of the application, made of two buttons,
	///		 one to go to the add booking menu and the other to the show booking menu
	/// </summary>
	int Show(HWND _window);

#pragma endregion

};

