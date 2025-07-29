#include "Cat.hpp"

Cat::Cat() : Animal ("Cat")
{
	_brain = new Brain();
	std::cout << "Cat constructor called" <<std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	_brain = new Brain(*src._brain);
	std::cout << "Cat copy constructor called" <<std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat desctructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "miaou" <<std::endl;
}

void Cat::setIdea(int idx, std::string idea)
{
	_brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const
{
	return (_brain->getIdea(idx));
}
