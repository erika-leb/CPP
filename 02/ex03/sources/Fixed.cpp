# include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
}

Fixed::Fixed(const int n) : _n(n << _bit)
{
}
Fixed::Fixed(const float f) : _n(static_cast<int>(roundf(f * (1 << _bit))))
{
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}
Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &src)
{
	if (this != &src)
		_n = src._n;
	return (*this);
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool Fixed::operator<(Fixed const &rhs) const
{
	if (this->_n < rhs._n)
		return (true);
	return (false);
}

bool Fixed::operator>(Fixed const &rhs) const
{
	if (this->_n > rhs._n)
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	if (this->_n <= rhs._n)
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	if (this->_n >= rhs._n)
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &rhs) const
{
	if (this->_n == rhs._n)
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	if (this->_n != rhs._n)
		return (true);
	return (false);
}

Fixed &Fixed::operator++(void) //prein
{
	_n++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	_n--;
	return (*this);
}

Fixed Fixed::operator++(int) //postin
{
	Fixed cpy(*this);
	_n++;
	return (cpy);
}

Fixed Fixed::operator--(int)
{
	Fixed cpy(*this);
	_n--;
	return (cpy);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.getRawBits() >= n2.getRawBits())
		return (n2);
	return (n1);
}
Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.getRawBits() <= n2.getRawBits())
		return (n2);
	return (n1);
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() >= n2.getRawBits())
		return (n2);
	return (n1);
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.getRawBits() <= n2.getRawBits())
		return (n2);
	return (n1);
}

int Fixed::getRawBits( void ) const
{
	return (_n);
}

void Fixed::setRawBits( int const raw )
{
	_n = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_n) / (1 << _bit));
}

int Fixed::toInt( void ) const
{
	return (_n / ( 1 << _bit));
}

std::ostream &operator<<(std::ostream &os, const Fixed &n)
{
	os << n.toFloat();
	return (os);
}
