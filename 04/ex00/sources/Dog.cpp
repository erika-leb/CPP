#include "Dog.hpp"

Dog::Dog() : Animal ("Dog")
{
	std::cout << "Dog constructor called" <<std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" <<std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog desctructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "wouaf" <<std::endl;
}
