#include "MateriaSource.hpp"

#include <stdio.h>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
	std::cout << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = src._inv[i]->clone();
	std::cout << "MateriaSource copy constructor called" << std::endl;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inv[i])
		{
			delete (_inv[i]);
			_inv[i] = NULL;
		}
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << "MateriaSource assignement operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inv[i])
			{
				delete (_inv[i]);
				_inv[i] = NULL;
			}
			_inv[i] = rhs._inv[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria*m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inv[i])
		{
			std::cout << m->getType() << " materiasource learnt!" << std::endl;
			_inv[i] = m;
			return ;
		}
	}
	std::cout << "this materiasource cannot learn more" << std::endl;
	delete m;
	m = NULL;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inv[i] && _inv[i]->getType() == type)
		{
			return (_inv[i]->clone());
		}
	}
	return (NULL);
}
