#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat constructor called" <<std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" <<std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat desctructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		std::cout << "Cat assignment operator called" << std::endl;
	}
	else
		std::cout << "Cat assignment operator called for the same instance" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "meeow" << std::endl;
}
