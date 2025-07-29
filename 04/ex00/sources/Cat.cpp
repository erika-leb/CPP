#include "Cat.hpp"

Cat::Cat() : Animal ("Cat")
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
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "miaou" <<std::endl;
}
