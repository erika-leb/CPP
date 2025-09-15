#include "Span.hpp"


Span::Span() : _n(10)
{
}
Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &src) : _n(src._n)
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

void Span::addNumber(int nb)
{
	if (_v.size() < _n)
	_v.push_back(nb);
	else
	throw std::out_of_range("maximum size reached, cannot add any number");
}


int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw std::length_error("Span is not long enough");
	std::vector<int> temp = _v;
	std::sort(temp.begin(), temp.end());
	int res = temp[1] - temp[0];
	for (size_t i = 2; i < temp.size(); i++)
	{
		int diff = temp[i] - temp[i - 1];
		if (diff < res)
			res = diff;
	}
	return (res);
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw std::length_error("Span is not long enough");
	int min = *std::min_element(_v.begin(), _v.end());
	int max = *std::max_element(_v.begin(), _v.end());
	return (max -  min);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _n)
		throw std::out_of_range("cannot add numbers");
	_v.insert(_v.begin(), begin, end);
}
