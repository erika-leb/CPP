# include "Zombie.hpp"

Zombie::Zombie(std::string name) :_name(name)
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
