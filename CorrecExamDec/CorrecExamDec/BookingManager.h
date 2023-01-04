
#pragma once
#include "Singleton.h"
#include <vector>

class Booking;

class BookingManager : public Singleton<BookingManager>
{
	DECLARE_CLASS_INFO(Singleton<BookingManager>)

#pragma region f/p
private:
	std::vector<Booking*> bookings = std::vector<Booking*>();
#pragma endregion f/p
#pragma region methods
public:
	void RegisterBooking(Booking* _booking);
	void DeleteBoooking(Booking* _booking);
	std::vector<Booking*> Bookings() const;

#pragma endregion methods
#pragma region override
public:
	void OnDestroy() override;
#pragma endregion override
};