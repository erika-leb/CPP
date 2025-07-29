# include "Character.hpp"
# include "AMateria.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int j = 0; j < 100; j++)
		_garbage[j] = NULL;
	std::cout << "default Character constructor called" <<std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int j = 0; j < 100; j++)
		_garbage[j] = NULL;
	std::cout << "Character constructor called" <<std::endl;
}

Character::Character(const Character &src) : _name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (int j = 0; j < 100; j++)
	{
		if (src._garbage[j])
			this->_garbage[j] = src._garbage[j]->clone();
		else
			this->_garbage[j] = NULL;
	}
	std::cout << "Character copy constructor called" <<std::endl;
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	for (int j = 0; j < 100; j++)
	{
		if (_garbage[j])
			delete _garbage[j];
	}
	std::cout << "Character destructor called" <<std::endl;
}
Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = rhs._inventory[i]->clone();
		}
		for (int j = 0; j < 100; j++)
		{
			if (_garbage[j])
				delete _garbage[j];
			_garbage[j] = rhs._garbage[j]->clone();
		}
		std::cout << "Character assignment operator called" << std::endl;
		this->_name = rhs._name;
	}
	else
		std::cout << "Character assignment operator called for the same instance" << std::endl;
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
		std::cout << "ici" << std::endl;
		if (!_inventory[i])
		{
			std::cout << "la" << std::endl;
			_inventory[i] = m;
			std::cout << "who" << std::endl;
			// std::cout << m->getType() << " has been added to inventory in position" << std::endl;
			std::cout << "what" << std::endl;
			return ;
		}
	}
	std::cout << "ici" << std::endl;
	std::cout << _name << "'s inventory is full. Materia cannot be added" << std::endl;
}

void Character::unequip(int idx)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
		{
			std::cout << "Materia " << _inventory[i]->getType() << " in position " << idx << " is unequiped" << std::endl;
			for (int j = 0; i < 100 && _garbage[j]; j++)
				_garbage[j] = _inventory[i];
			_inventory[i] = NULL;
		}
	}
	std::cout << "index not found" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
		{

			std::cout << _inventory[i] << std::endl;
			if (_inventory[i])
				_inventory[i]->use(target);
			return ;
		}
	}
	std::cout << "index not found" << std::endl;
}
