#include "Object.h"
#include <typeinfo>
std::string Object::ToString() const
{
	std::string _name = typeid(*this).name();
	return _name.substr(_name.find_last_of(' ' + 1));
}
