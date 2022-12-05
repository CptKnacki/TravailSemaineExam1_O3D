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

#pragma region Override
public:
	/// <summary>
	///		Used to display the main menu of the application, made of two buttons,
	///		 one to go to the add booking menu and the other to the show booking menu
	/// </summary>
	void Show() override;

	/// <summary>
	///		Used to close the main menu window to let another one open 
	/// </summary>
	void Close() override;
#pragma endregion

};

