# include "Array.hpp"

template <typename T>
Array<T>::Array() : _n(0), _arr(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_n = n;
	_arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array &src)
{
	_n = src._n;
	if (_n != 0)
	{
		_arr = new T[_n];
		for (unsigned i = 0; i < _n; i++)
			_arr[i] = src._arr[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	if (_arr)
		delete[] _arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		if (_arr)
			delete[] _arr;
		if (_n != 0)
		{
			_arr = new T[_n];
			for (unsigned int i = 0; i < _n; i++)
				_arr[i] = rhs._arr[i];
		}
	}
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_n);
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
	for (unsigned int i = 0; i < _n; i++)
	{
		if (i == n)
			return (_arr[i]);
	}
	throw std::out_of_range("Error: index out of range");
}

template <typename T>
const T &Array<T>::operator[](unsigned int n) const
{
	for (unsigned int i = 0; i < _n; i++)
	{
		if (i == n)
			return (_arr[i]);
	}
	throw std::out_of_range("Error: index out of range");
}

