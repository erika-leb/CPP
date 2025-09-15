#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "nothing";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
Brain &Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
		std::cout << "Brain assignment operator called for the same instance" << std::endl;
	}
	else
		std::cout << "Brain assignment operator called for the same instance" << std::endl;
	return (*this);
}


std::string Brain::getIdea(int i) const
{
	for (int j = 0; j < 100; j++)
	{
		if (j == i)
			return (ideas[i]);
	}
	return ("");
}

void Brain::setIdea(int i, std::string idea)
{
	for (int j = 0; j < 100; j++)
	{
		if (j == i)
		{
			ideas[i] = idea;
			return ;
		}
	}
	std::cout << "Invalid index" <<std::endl;
}
