#pragma once
#include <string>
#include <Windows.h>

class Window
{
#pragma region f/p
private:
	std::string title = ""; // The title of the window is what will be displayed on top of the app screen //
#pragma endregion

#pragma region Constructor
public:
	Window() = default;
	Window(const std::string _title);
	Window(const Window& _copy);
#pragma endregion

#pragma region Methods
public:

	/// <summary>
	///		Supposed to do nothing here, will be used by herited class to display their elements on the app screen
	/// </summary>
	virtual void Show();

	/// <summary>
	///		Getter on the title of the window
	/// </summary>
	/// <returns> title </returns>
	std::string GetTitle();

#pragma endregion
};

