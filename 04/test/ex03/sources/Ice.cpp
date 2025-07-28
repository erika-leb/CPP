#include "Ice.hpp"
#include "AMateria.hpp"

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
	std::cout << "Ice Assigment operator called" << std::endl;
	if (this != &rhs)
	{
	}
	return(*this);
}

AMateria* Ice::clone() const
{
	std::cout << "Ice Materia cloned !" << std::endl;
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
