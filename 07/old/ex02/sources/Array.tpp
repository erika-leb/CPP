#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	// _arr = new T();
	_n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_arr = new T[n]();
	_n = n;
}

template <typename T>
Array<T>::Array(const Array &src)
{
	_arr = new T[src._n]();
	for (unsigned int i = 0; i < src._n; i++)
		_arr[i] = src._arr[i];
	_n = src._n;
}

template <typename T>
Array<T>::~Array()
{
	delete []_arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		if (_arr)
			delete []_arr;
		_arr = new T[rhs._n]();
		for (unsigned int i = 0; i < rhs._n; i++)
			_arr[i] = rhs._arr[i];
		_n = rhs._n;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int n) const
{
	for (unsigned int i = 0; i < _n; i++)
	{
		if (i == n)
			return (_arr[i]);
	}
	throw (std::out_of_range("Index out of range"));
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_n);
}
