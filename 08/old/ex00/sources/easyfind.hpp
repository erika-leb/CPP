#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template < typename T>
typename T::iterator easyfind(T &a, int n)
{
	typename T::iterator it = std::find(a.begin(), a.end(), n);
	if (it == a.end())
		throw std::out_of_range("int not found");
	return (it);
}

#endif
