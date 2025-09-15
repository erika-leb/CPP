#include "Character.hpp"
#include "AMateria.hpp"


#include <stdio.h>

Character::Character() : _name("default")
{
	for(int i = 0; i < 4; i++)
		_items[i] = NULL;
	for(int j = 0; j < 100; j++)
		_garbage[j] = NULL;
	std::cout << "Default character constructor called" << std::endl;
}
Character::Character(std::string name) : _name(name)
{
	for(int i = 0; i < 4; i++)
		_items[i] = NULL;
	for(int j = 0; j < 100; j++)
		_garbage[j] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character &src) : _name(src._name)
{
	for(int i = 0; i < 4; i++)
	{
		if (src._items[i])
			_items[i] = src._items[i]->clone();
		else
			_items[i] = NULL;
	}
	for(int j = 0; j < 100; j++)
	{
		if (src._garbage[j])
			_garbage[j] = src._garbage[j]->clone();
		else
			_garbage[j] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	perror("terre");
	for(int i = 0; i < 4; i++)
	{
		perror("landes");
		std::cout << i << std::endl;
		std::cout << _items[i] << std::endl;
		if (_items[i])
		{
			// std::cout << _items[i]->getType() << std::endl;
			perror("conemmaa");
			delete _items[i];
			_items[i] = NULL;
			perror("la hauta");
		}
		perror("decors");
	}
	perror("des");
	for(int j = 0; j < 100; j++)
	{
		// perror("landes");
		if (_garbage[j])
		{
			delete _garbage[j];
			_garbage[j] = NULL;
		}
	}
	perror("brulee");
	std::cout << "Character destructor called" << std::endl;
}

Character &Character::operator=(const Character &rhs)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for(int i = 0; i < 4; i++)
		{
			if (_items[i])
			{
				std::cout << "Deleting _items[" << i << "] at " << _items[i] << std::endl;
				delete _items[i];
				_items[i] = NULL;
			}
			if (rhs._items[i])
				_items[i] = rhs._items[i]->clone();
			else
				_items[i] = NULL;
		}
		for(int j = 0; j < 100; j++)
		{
			if (_garbage[j])
			{
				std::cout << "Deleting _garbage[" << j << "] at " << _garbage[j] << std::endl;
				delete _garbage[j];
				_garbage[j] = NULL;
			}
			if (rhs._garbage[j])
				_garbage[j] = rhs._garbage[j]->clone();
			else
				_garbage[j] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_items[i])
		{
			std::cout << m->getType() << " item equiped" << std::endl;
			_items[i] = m;
			return ;
		}
	}
	std::cout << "the character's inventory is full, you cannot add any materia" << std::endl;
	for (int j = 0; j < 100; j++)
	{
		if (_garbage[j] == NULL)
		{
			_garbage[j] = m;
			return ;
		}
	}
	delete m;
	m = NULL;
}

void Character::unequip(int idx)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
		{
			if (!_items[i])
			{
				std::cout << "no materia registered in position " << idx << std::endl;
				return ;
			}
			else
			{
				for (int j = 0; j < 100; j++)
				{
					if (_garbage[j] == NULL)
					{
						std::cout << _items[i]->getType() << " item unequiped" << std::endl;
						_garbage[j] = _items[i];
						std::cout << "Moved materia from _items[" << idx << "] at "
                      << _items[idx] << " to _garbage[" << j << "]" << std::endl;
						_items[i] = NULL;

						return ;
					}
				}
				std::cout << "no space left in garbage, unequipment impossible" << std::endl;
				return;
			}
		}
	}
	std::cout << "Wrong index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == idx && _items[i])
		{
			_items[i]->use(target);
			return ;
		}
	}
	std::cout << "Wrong index or unexisting materia" << std::endl;
}

