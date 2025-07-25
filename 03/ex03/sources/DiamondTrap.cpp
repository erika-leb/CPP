#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
	_name = "Default";
	_hitP = FragTrap::_defaultHitP;
	_enerP = ScavTrap::_defaultEnerP;
	_attD = FragTrap::_defaultAttD;
	std::cout << "DiamondTrap Default constructor called : _hitP = " << _hitP << "; _enerP = " << _enerP << "; _attD = " << _attD << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hitP = FragTrap::_defaultHitP;
	_enerP = ScavTrap::_defaultEnerP;
	_attD = FragTrap::_defaultAttD;
	std::cout << "DiamondTrap " << _name << " constructor called : _hitP = " << _hitP << "; _enerP = " << _enerP << "; _attD = " << _attD << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << _name << "DiamondTrap copy constructor called : _hitP = " << _hitP << "; _enerP = " << _enerP << "; _attD = " << _attD << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		// _hitP = rhs._hitP;
		// _enerP = rhs._enerP;
		// _attD = rhs._attD;
		ClapTrap::operator=(rhs);
		std::cout << _name << " DiamondTrap assignment operator called : _hitP = " << _hitP << "; _enerP = " << _enerP << "; _attD = " << _attD << std::endl;
	}
	else
		std::cout << _name << "DiamondTrap assignment operator called for the same instance" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
