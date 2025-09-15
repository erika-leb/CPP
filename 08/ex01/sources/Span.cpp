# include "Span.hpp"

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
		throw std::out_of_range("container is full; cannot add any integer");
}

long Span::shortestSpan()
{

	if (_v.size() < 2)
		throw std::length_error("not enough integers to calculate shortest span");
	std::vector<int> temp = _v;
	std::sort(temp.begin(), temp.end());
	double res = temp[1] - temp[0];
	for (size_t i = 2; i < temp.size(); i++)
	{
		double diff = temp[i] - temp[i - 1];
		if (diff < res)
			res = diff;
	}
	return (res);
}

long Span::longestSpan()
{
	if (_v.size() < 2)
		throw std::length_error("not enough integers to calculate longest span");
	double max = *std::max_element(_v.begin(), _v.end());
	double min = *std::min_element(_v.begin(), _v.end());
	return (max - min);
}

void Span::addRange(std::vector<int>::iterator a, std::vector<int>::iterator b)
{
	if (_v.size() + std::distance(a, b) > _n)
		throw std::out_of_range("cannot add more integers");
	_v.insert(_v.end(), a, b);
}
