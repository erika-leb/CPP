#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " died." << std::endl;
	return ;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
void Zombie::setName(std::string name)
{
	_name = name;
	return ;
}
