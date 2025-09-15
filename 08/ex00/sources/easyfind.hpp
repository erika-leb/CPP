#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &a, int n)
{
	typename T::iterator it;
	
	it = std::find(a.begin(), a.end(), n);
	if (it == a.end())
		throw std::out_of_range("integer not found");
	return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T &a, int n)
{
	typename T::const_iterator it;

	it = std::find(a.begin(), a.end(), n);
	if (it == a.end())
		throw std::out_of_range("integer not found");
	return (it);
}

#endif
