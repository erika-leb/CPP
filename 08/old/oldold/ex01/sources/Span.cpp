#include "Span.hpp"

Span::Span() : _n(10)
{
}

Span::Span(unsigned int n) : _n(n)
{
}


Span::Span(const Span &src) : _n(src._n), _v(src._v)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw std::length_error("Span is full");
}

// int Span::shortestSpan()
// {
// 	int r;
// 	int s = _v.size();
// 	if (s == 0 || s == 0)
// 		throw std::length_error("Span is not long enough");
// 	if (_v[0] - _v[1] >= 0)
// 		r = _v[0] - _v[1];
// 	else
// 		r = _v[1] - _v[0];
// 	// std::cout << r << std::endl;
// 	for (int i = 0; i < s; i++)
// 	{
// 		for (int j = 1; j < s; j++)
// 		{

// 			if ((i != j) && (_v[j] - _v[i] >= 0) && (_v[j] - _v[i] < r))
// 			{
// 				// std::cout << "1 : " << r << std::endl;
// 				r = _v[j] - _v[i];
// 				// std::cout << "i : " << i << "j = " << j << std::endl;
// 				// std::cout << _v[j] - _v[i] << "after" << r << std::endl;
// 			}
// 			if ((i != j) && (_v[i] - _v[j] >= 0) && (_v[i] - _v[j] < r))
// 			{
// 				r = _v[i] - _v[j];
// 			}
// 			// std::cout << r << std::endl;
// 		}
// 	}
// 	return (r);
// }

int Span::shortestSpan()
{
	int s = _v.size();
	if (s == 0 || s == 1)
		throw std::length_error("Span is not long enough");

	std::vector<int> temp = _v;
	std::sort(temp.begin(), temp.end());
	int res = temp[1] - temp[0];
	for (unsigned int i = 2; i < temp.size(); i++)
	{
		int diff = temp[i] - temp[i - 1];
		if (diff < res)
			res = diff;
	}
	return (res);
}

// int Span::longestSpan()
// {
// 	int s = _v.size();
// 	int r = 0;
// 	if (s == 0 || s == 0)
// 		throw std::length_error("Span is not long enough");
// 	for (int i = 0; i < s; i++)
// 	{
// 		for (int j = 1; j < s; j++)
// 		{
// 			if (_v[j] - _v[i] > r)
// 				r = _v[j] - _v[i];
// 			if (_v[i] - _v[j] > r)
// 				r = _v[i] - _v[j];
// 		}
// 	}
// 	return (r);
// }

int Span::longestSpan()
{
	int min;
	int max;
	int s;

	s = _v.size();
	if (s == 0 || s == 0)
		throw std::length_error("Span is not long enough");
	min = *std::min_element(_v.begin(), _v.end());
	max = *std::max_element(_v.begin(), _v.end());
	return (max - min);
}

void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	int s = std::distance(begin, end);
	if (_v.size() + s > _n)
		throw std::overflow_error("not enough space to add range");
	_v.insert(_v.end(), begin, end);
}
