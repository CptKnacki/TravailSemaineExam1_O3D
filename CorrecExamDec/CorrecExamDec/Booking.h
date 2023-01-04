#pragma once
#include "Client.h"
#include "DateTime.h"

class Booking : public Object
{
	DECLARE_CLASS_INFO(Object)

private:
	DateTime arrivedDate = DateTime();
	DateTime departureDate = DateTime();
	Client client = Client();
	int numberOfPeople = 1;

public:
	Booking() = default;
	Booking(DateTime _arrivedDate, DateTime _departureDate, const Client& _client , int _numberOfPeople);
	Booking(const Booking& _copy);

public:
	DateTime ArrivedDate() const;
	DateTime DepartureDate() const;
	Client GetClient() const;
	int NumberOfPeople() const;
};