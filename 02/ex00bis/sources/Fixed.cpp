#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	// _n = src.getRawBits(); //on peut aussi
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rsh)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rsh)
		this->_n = rsh.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_n);
}

void Fixed::setRawBits( int const raw )
{
	_n = raw;
	std::cout << "setRawBits member function called" << std::endl;
	return ;
}
