#pragma once

template<typename T>
class Singleton
{
#pragma region f/p
private:
	static inline T* instance = nullptr;
#pragma endregion

#pragma region Constructor
public:
	Singleton() = default;
	~Singleton();
#pragma endregion

#pragma region Methods
public:

	/// <summary>
	///		Return the instance of the singleton
	/// </summary>
	/// <returns> instance </returns>
	T* GetInstance();

	/// <summary>
	///		Will be used by herited singleton to redifine the destructor
	/// </summary>
	virtual void OnDestroy();
#pragma endregion

};

#pragma region Destructor

template<typename T>
inline Singleton<T>::~Singleton()
{
	OnDestroy();
	delete instance;
}


#pragma endregion

#pragma region Methods

template<typename T>
inline T* Singleton<T>::GetInstance()
{
	if (instance == nullptr)
		instance = new T();
	return instance;
}

template<typename T>
inline void Singleton<T>::OnDestroy()
{
}

#pragma endregion