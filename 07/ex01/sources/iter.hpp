#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *arr, size_t s, void (*f)(T &))
{
	for (size_t i = 0; i < s; i++)
		f(arr[i]);
};

#endif
