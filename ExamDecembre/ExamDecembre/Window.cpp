#include "Window.h"

#pragma region Constructor

Window::Window(const std::string _title)
{
	title = _title;
}

Window::Window(const Window& _copy)
{
	title = _copy.title;
}

#pragma endregion

#pragma region Methods

void Window::Show()
{
}

std::string Window::GetTitle()
{
	return title;
}

#pragma endregion


