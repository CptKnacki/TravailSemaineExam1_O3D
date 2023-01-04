#pragma once
#include "Object.h"

template<typename T>
class Singleton : public Object
{
	DECLARE_CLASS_INFO(Object)

#pragma region f/p
private:
	static inline T* instance = nullptr;

#pragma endregion f/p
#pragma region constructor
public:
	Singleton() = default;
	~Singleton()
	{
		OnDestroy();
		delete instance;
		instance = nullptr;
	}

#pragma endregion contructor
#pragma region methods
protected:
	virtual void OnDestroy()
	{

	}
public:
	static T* Instance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
#pragma endregion methods


};