#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;
	std::cout << "default MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._memory[i])
			_memory[i] = src._memory[i]->clone();
		else
			_memory[i] = NULL;
	}
	std::cout << "copy MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "hello1 " << " *" <<std::endl;
		if (_memory[i])
		{
			std::cout << _memory[i] << std::endl;
			std::cout << "hola51 " << " *" <<std::endl;
			delete _memory[i];
			_memory[i] = NULL;
			std::cout << "hola122 " << " *" <<std::endl;
		}
		std::cout << "hola12 " << " *" <<std::endl;
	}
	std::cout << "hola1 " << " *" <<std::endl;
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_memory[i])
				delete _memory[i];
			_memory[i] = rhs._memory[i]->clone();
		}
		std::cout << "MateriaSource assignment operator called" << std::endl;
	}
	else
		std::cout << "AMateriaSource assignment operator called for the same instance" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria*m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_memory[i])
		{
			std::cout << " MateriaSource adds " << m->getType() << " to its memory" << std::endl;
			_memory[i] = m;
		}
	}
	std::cout << "MateriaCourse cannot add any AMateria" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if (type == _memory[i]->getType())
			return (_memory[i]->clone());
	}
	std::cout << "Type not found in MateriaSource" << std::endl;
	return (NULL);
}
