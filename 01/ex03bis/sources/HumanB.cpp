#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}
// void	HumanB::setWeapon(Weapon &w)
// {
// 	_w = &w;
// 	return ;
// }

void	HumanB::setWeapon(Weapon *w)
{

	if (w != NULL)
	{
		_w = w;
	}
	return ;
}

void	HumanB::attack(void) const
{
	if (_w != NULL)
		std::cout << _name << " attacks with their " << (*_w).getType() << std::endl;
	else
		std::cout << _name << " attacks with no weapon" << std::endl;
	return ;
}
