#pragma once
#include "Object.h"

template <typename Res, typename... Args>
class Delegate : public Object
{
	DECLARE_CLASS_INFO(Object)

#pragma region f/p
private:
	typedef Res(Object::* Function)(Args...);
	Function function = nullptr;
	Object* instance = nullptr;
#pragma endregion

#pragma region Constructor
public:
	Delegate() = default;
	Delegate(nullptr_t)
	{
		instance = nullptr;
		function = nullptr;
	}
#pragma endregion

#pragma region Methods
public:
	template<class Class>
	void SetDynamic(Class* _instance, Res(Class::* _ptr)(Args...))
	{
		if constexpr(!std::is_base_of_v<Object, Class>)
			throw std::exception("[DELEGATE] -> Class must be inherited of object !");
		instance = _instance;
		function = reinterpret_cast<Function>(_ptr);

	}

	Res Invoke(Args... _args)
	{
		if (function == nullptr || instance == nullptr)
			throw std::exception("[DELEGATE] -> function or instance is null");
		return (instance->*function) (_args...);
	}
#pragma endregion

#pragma region Operator
public:
	void operator=(nullptr_t)
	{
		instance = function = nullptr;
	}
#pragma endregion

};