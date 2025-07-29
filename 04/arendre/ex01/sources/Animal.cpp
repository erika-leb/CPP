#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type)
{
	// *this = src;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		std::cout << "Animal assignment operator called" << std::endl;
	}
	else
		std::cout << "Animal assignment operator called for the same instance" << std::endl;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "an animal is making a sound" << std::endl;
}
