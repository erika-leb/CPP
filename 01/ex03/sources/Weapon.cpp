#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string type) : type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string	Weapon::getType(void)
{
	return (type);
}
void	Weapon::setType(std::string str)
{
	type = str;
	return ;
}
