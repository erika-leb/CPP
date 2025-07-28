#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		std::cout << "AAnimal assignment operator called" << std::endl;
	}
	else
		std::cout << "AAnimal assignment operator called for the same instance" << std::endl;
	return (*this);
}

std::string AAnimal::getType(void) const
{
	return (_type);
}

