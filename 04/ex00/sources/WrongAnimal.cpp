#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Animal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		std::cout << "WrongAnimal assignment operator called" << std::endl;
	}
	else
		std::cout << "WrongAnimal assignment operator called for the same instance" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "a wrong animal makes a sound" << std::endl;
}

