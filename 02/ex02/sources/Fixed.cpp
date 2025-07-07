#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n) : _n(n << _bit)
{
	// std::cout << "Int constructor called" << std::endl;
	return ;
}
Fixed::Fixed(const float n) : _n(roundf(n *(1 << _bit)))
{
	// std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	_n = src.getRawBits(); //on peut aussi
	// *this = src;
	return ;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rsh)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rsh)
		this->_n = rsh.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(Fixed const &src)
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(Fixed const &src)
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(Fixed const &src)
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(Fixed const &src)
{
	return (Fixed(this->toFloat() / src.toFloat()));
}

bool Fixed::operator<(Fixed const &src)
{
	if (this->toFloat() < src.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator>(Fixed const &src)
{
	if (this->toFloat() > src.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(Fixed const &src)
{
	if (this->toFloat() <= src.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(Fixed const &src)
{
	if (this->toFloat() >= src.toFloat())
		return (true);
	else
		return (false);
}

bool Fixed::operator==(Fixed const &src)
{
	if (this->toFloat() == src.toFloat())
		return (true);
	else
		return(false);
}

bool Fixed::operator!=(Fixed const &src)
{
	if (this->toFloat() != src.toFloat())
		return (true);
	else
		return(false);
}

Fixed Fixed::operator++(int)
{
	Fixed cpy = Fixed(this->toFloat());
	_n++;
	return(cpy);
}

Fixed &Fixed::operator++(void)
{
	_n++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed cpy = Fixed(this->toFloat());
	_n--;
	return(cpy);
}

Fixed &Fixed::operator--(void)
{
	_n--;
	return (*this);
}

Fixed const &Fixed::min(Fixed const &n1, Fixed const &n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	else
		return (n2);
}
Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() <= n2.toFloat())
		return (n1);
	else
		return (n2);
}

Fixed const &Fixed::max(Fixed const &n1, Fixed const &n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	else
		return (n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.toFloat() >= n2.toFloat())
		return (n1);
	else
		return (n2);
}

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_n);
}

void Fixed::setRawBits( int const raw )
{
	_n = raw;
	// std::cout << "setRawBits member function called" << std::endl;
	return ;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 <<_bit));
}

int	Fixed::toInt( void ) const
{
	return (this->getRawBits() / (1 << _bit));
}

std::ostream& operator<<(std::ostream& os, const Fixed &copy)
{
	os << copy.toFloat();//On injecte dans os le nombre qui a ete retransforme
	//dans sa valeur d'origine
	return (os);
}

