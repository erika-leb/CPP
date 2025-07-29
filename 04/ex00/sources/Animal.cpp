#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "an animal is making a sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return (_type);
}
