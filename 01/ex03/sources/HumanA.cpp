#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : name(name), _w_ref(w)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << _w_ref.getType() << std::endl;
	return ;
}

