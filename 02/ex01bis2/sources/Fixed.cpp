#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" <<std::endl;
	return ;
}

Fixed::Fixed(int const n) : _n(n << _bit)
{
	std::cout << "Int constructor called" <<std::endl;
	return ;
}
Fixed::Fixed(float const n) : _n(static_cast<int>(roundf(n) * (1 << _bit)))
{
	std::cout << "Float constructor called" <<std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" <<std::endl;
	_n = src.getRawBits();
	return ;
}
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &rhs)
		this->_n = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" <<std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" <<std::endl;
	return (_n);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits() / (1 << _bit)));
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() / (1 << _bit));
}

void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function calledd" <<std::endl;
	_n = raw;
	return ;
}

std::ostream &operator<<(std::ostream &os, Fixed const &n)
{
	os << n.toFloat();
	return (os);
}
