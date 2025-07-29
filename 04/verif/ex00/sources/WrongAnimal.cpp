#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "default WrongAnimal constructor called" << std::endl;
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
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "an WrongAnimal is making a sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}
