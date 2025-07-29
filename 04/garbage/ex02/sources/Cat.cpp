#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	_brain = new Brain;
	std::cout << "Cat constructor called" <<std::endl;
}

Cat::Cat(const Cat &src) : AAnimal(src)
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
	if (this != &rhs)
	{
		delete _brain;
		_brain = new Brain(*rhs._brain);
		_type = rhs._type;
		std::cout << "Cat assignment operator called for the same instance" << std::endl;
	}
	else
		std::cout << "Cat assignment operator called for the same instance" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "meeow" << std::endl;
}

void Cat::setIdeas(const int i, const std::string idea)
{
	_brain->setIdea(i, idea);
}

std::string Cat::getIdeas(const int i) const
{
	return (_brain->getIdea(i));
}
