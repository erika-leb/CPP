#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		std::cout << "Dog assignment operator called" << std::endl;
	}
	else
		std::cout << "Dog asssignment operator constructor called for the same instance" << std::endl;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "wouaf" << std::endl;
}
