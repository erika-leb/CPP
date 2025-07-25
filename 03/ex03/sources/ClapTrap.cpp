#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitP(10), _enerP(10), _attD(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitP(10), _enerP(10), _attD(0)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : _name(src._name), _hitP(src._hitP), _enerP(src._enerP), _attD(src._attD)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitP = rhs._hitP;
		_enerP = rhs._enerP;
		_attD = rhs._attD;
		std::cout << _name << " ClapTrap assignment operator called" << std::endl;
	}
	else
		std::cout << _name << "ClapTrap assignment operator called for the same instance" << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitP > 0 && _enerP > 0)
	{
		_enerP--;
		std::cout << "ClapTrap "  << _name << " attacks " << target << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " cannot attacks " << target << std::endl;
	std::cout << _name << " hit point: " << _hitP << "; energy points: " << _enerP << "; Attack damages: " << _attD << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hitP)
	{
		std::cout << _name << " loses " << _hitP << " hit points" << std::endl;
		_hitP = 0;
	}
	else
	{
		std::cout << _name << " loses " << amount << " hit points" << std::endl;
		_hitP = _hitP - amount;
	}
	std::cout << _name << " hit point: " << _hitP << "; energy points: " << _enerP << "; Attack damages: " << _attD << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitP > 0 && _enerP > 0)
	{
		_hitP = _hitP + amount;
		_enerP--;
		std::cout << _name << " gains " << amount << " hit points" <<std::endl;
	}
	else
		std::cout << _name << " cannot gain any hit point" << std::endl;
	std::cout << _name << " hit point: " << _hitP << "; energy points: " << _enerP << "; Attack damages: " << _attD << std::endl;
	}

