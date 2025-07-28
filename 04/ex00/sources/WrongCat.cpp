#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		std::cout << "WrongCat assignment operator called" << std::endl;
	}
	else
		std::cout << "WrongCat assignment operator called for the same instance" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "miaouh" << std::endl;
}
