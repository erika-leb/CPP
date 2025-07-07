# include "Fixed.hpp"

Fixed::Fixed(void) : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
Fixed::Fixed(Fixed const  &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this=src;
	return ;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_n = rhs.getRawBits(); //comment il y a acces alors que c est pas la meme instance ?
	}
	return (*this); //what ? ok
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_n);
}


void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
	return ;
}


