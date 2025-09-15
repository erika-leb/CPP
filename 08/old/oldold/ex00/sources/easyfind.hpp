#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (it == a.end())
		throw std::out_of_range("int not found");
	return (it);
}

#endif


