#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitP = 100;
	this->_enerP = 50;
	this->_attD = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) //puis-je utiliser le constructeur de ClapTrap par defaut ?
{
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
	// this->_name = name;
	this->_hitP = 100;
	this->_enerP = 50;
	this->_attD = 20;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << _name << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitP = rhs._hitP;
		_enerP = rhs._enerP;
		_attD = rhs._attD;
		std::cout << "FragTrap assignment operator called" << std::endl;
	}
	else
		std::cout << "Assignment operator called for the same instance" << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap " << _name << " attacks " << target << std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "Give me a high five" << std::endl;
}
