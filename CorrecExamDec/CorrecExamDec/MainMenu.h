#pragma once
#include "BaseMenu.h"

class MainMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)

#pragma region Constructor
public:
	MainMenu() = default;
	MainMenu(Window* _owner);
	MainMenu(const MainMenu& _copy) = default;
#pragma endregion

#pragma region Override
public:
	void Initialize() override;
#pragma endregion
};

