# include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}
Zombie::~Zombie(void)
{
	std::cout << _name << " has died." << std::endl;
	return ;
}
void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ.." << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	_name = name;
	return ;
}
