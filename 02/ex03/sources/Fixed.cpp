#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	// std::cout << "Default constructor called" <<std::endl;
	return ;
}

Fixed::Fixed(int const n) : _n(n << _bit)
{
	// std::cout << "Int constructor called" <<std::endl;
	return ;
}
Fixed::Fixed(float const n) : _n(static_cast<int>(roundf(n * (1 << _bit))))
{
	// std::cout << "Float constructor called" <<std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" <<std::endl;
	_n = src.getRawBits();
	return ;
}
Fixed &Fixed::operator=(const Fixed &rhs)
{
	// std::cout << "Copy assignment operator called" <<std::endl;
	if (this != &rhs)
		this->_n = rhs.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	Fixed res(this->toFloat() + rhs.toFloat());
	return (res);
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	Fixed res(this->toFloat() - rhs.toFloat());
	return (res);
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	Fixed res((this->toFloat() * rhs.toFloat()));
	return (res);
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	Fixed res((this->toFloat() / rhs.toFloat()));
	return (res);
}


bool Fixed::operator<(const Fixed &rhs)const
{
	if (this->_n < rhs._n)
		return (true);
	else
		return (false);
}

bool Fixed::operator>(const Fixed &rhs)const
{
	if (this->_n > rhs._n)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed &rhs)const
{
	if (this->_n >= rhs._n)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed &rhs)const
{
	if (this->_n <= rhs._n)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed &rhs)const
{
	if (this->_n == rhs._n)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed &rhs)const
{
	if (this->_n != rhs._n)
		return (true);
	else
		return (false);
}

Fixed &Fixed::operator++(void)//preincrementaiton
{
	_n++;
	return (*this);
}

Fixed Fixed::operator++(int)//postincrementaiton
{
	Fixed cpy(*this);
	_n++;
	return (cpy);
}

Fixed &Fixed::operator--(void)//preincrementaiton
{
	_n--;
	return (*this);
}

Fixed Fixed::operator--(int)//postincrementaiton
{
	Fixed cpy(*this);
	_n--;
	return (cpy);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" <<std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" <<std::endl;
	return (_n);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / static_cast<float>((1 << _bit)));
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
Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

Fixed const &Fixed::min(Fixed const &n1, Fixed const &n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

Fixed const &Fixed::max(Fixed const &n1, Fixed const &n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

std::ostream &operator<<(std::ostream &os, Fixed const &n)
{
	os << n.toFloat();
	return (os);
}
