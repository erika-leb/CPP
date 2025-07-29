#include "Dog.hpp"

Dog::Dog() : Animal ("Dog")
{
	_brain = new Brain();
	std::cout << "Dog constructor called" <<std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor called" <<std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog desctructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
	{
		delete _brain;
		_brain = new Brain(*rhs._brain);
		_type = rhs._type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "wouaf" <<std::endl;
}

void Dog::setIdea(int idx, std::string idea)
{
	_brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const
{
	return (_brain->getIdea(idx));
}
