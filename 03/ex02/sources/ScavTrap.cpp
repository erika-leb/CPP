#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitP = 100;
	this->_enerP = 50;
	this->_attD = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) //puis-je utiliser le constructeur de ClapTrap par defaut ?
{
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
	// this->_name = name;
	this->_hitP = 100;
	this->_enerP = 50;
	this->_attD = 20;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap(src)
{
	std::cout  << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << _name << " ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitP = rhs._hitP;
		_enerP = rhs._enerP;
		_attD = rhs._attD;
		std::cout << "ScavTrap assignment operator called" << std::endl;
	}
	else
		std::cout << "Assignment operator called for the same instance" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << _name << " attacks " << target << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" <<std::endl;
}
