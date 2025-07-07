#include "Zombie.hpp"

Zombie::Zombie(std::string str)
{
	_name = str;
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
