# include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _n(n << _bit)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float f) : _n(static_cast<int>(roundf(f * (1 << _bit))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		_n = src._n;
	}
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_n);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
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
