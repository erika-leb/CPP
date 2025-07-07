#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" <<std::endl;
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
	std::cout << "getRawBits member function called" <<std::endl;
	return (_n);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function calledd" <<std::endl;
	_n = raw;
	return ;
}
