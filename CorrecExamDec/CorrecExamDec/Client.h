#pragma once
#include "Object.h"
class Client : public Object
{

	DECLARE_CLASS_INFO(Object)

private:
	std::string firstName = "";
	std::string lastName = "";

public:
	Client() = default;
	Client(std::string _firstName, std::string _lastName);
	Client(const Client& _copy);

public:
	std::string FirstName() const;
	std::string LastName() const;
};

