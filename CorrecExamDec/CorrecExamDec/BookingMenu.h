#pragma once
#include "BaseMenu.h"

class BookingMenu : public BaseMenu
{
	DECLARE_CLASS_INFO(BaseMenu)

public:
#pragma region Constructor
public:
	BookingMenu() = default;
	BookingMenu(Window* _owner);
	BookingMenu(const BookingMenu& _copy) = default;
#pragma endregion

#pragma region Override
public:
	 void Initialize() override;
#pragma endregion

};

