#pragma once
#include <string>

#define DECLARE_CLASS_INFO(parent) \
	public: \
		typedef parent super;

class Object
{
#pragma region Constructor / Destructor
public:
	Object() = default;
	virtual ~Object() = default;

#pragma endregion

#pragma region Methods
public:
	virtual std::string ToString() const;

#pragma endregion

};

