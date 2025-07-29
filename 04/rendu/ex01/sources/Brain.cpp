#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = "";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignement operator called" << std::endl;
	if (this != &rhs)
	{
		for(int i = 0; i < 100; i++)
			_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int idx, std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (i == idx)
		{
			_ideas[i] = idea;
			return ;
		}
	}
	std::cout << "index not found" << std::endl;
}

std::string Brain::getIdea(int idx) const
{
	for (int i = 0; i < 100; i++)
	{
		if (i == idx)
			return (_ideas[i]);
	}
	std::cout << "index not found" << std::endl;
	return ("");
}
