#include "HumanB.hpp"

HumanB::HumanB(void)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon& w)
{
	_w_ptr = &w;
}
void	HumanB::attack(void) const
{
	std::cout << name << " attacks with their" << _w_ptr->getType() << std::endl;
	return ;
}

