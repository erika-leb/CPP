#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
}
Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}
Ice &Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
		std::cout << "ice assignment operator called" << std::endl;
	}
	else
		std::cout << "ice assignment operator called for the same instance" << std::endl;
	return (*this);
}

AMateria* Ice::clone(void) const
{
	AMateria *cpy;
	cpy = new Ice();
	return (cpy);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
