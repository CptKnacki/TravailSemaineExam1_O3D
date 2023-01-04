#include "BookingManager.h"


#pragma region methods
void BookingManager::RegisterBooking(Booking* _booking)
{
	bookings.push_back(_booking);
}

void BookingManager::DeleteBoooking(Booking* _booking)
{
	const size_t _size = bookings.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (bookings[i] == _booking)
		{
			bookings.erase(bookings.begin() + i);
			delete _booking;
			break;
		}
	}
}

std::vector<Booking*> BookingManager::Bookings() const
{
	return bookings;
}
#pragma endregion methods
#pragma region override
void BookingManager::OnDestroy()
{
	const size_t _size = bookings.size();
	for (size_t i = 0; i < _size; i++)
	{
		delete bookings[i];

	}
	bookings.clear();
}
#pragma endregion override