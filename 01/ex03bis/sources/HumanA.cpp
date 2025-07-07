#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : _name(name), _w(w)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _w.getType() << std::endl;
	return ;
}

