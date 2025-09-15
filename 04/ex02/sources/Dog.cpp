#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		delete _brain;
		_brain = new Brain(*rhs._brain);
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

void Dog::setIdeas(const int i, const std::string idea)
{
	_brain->setIdea(i, idea);
}

std::string Dog::getIdeas(const int i) const
{
	return (_brain->getIdea(i));
}
