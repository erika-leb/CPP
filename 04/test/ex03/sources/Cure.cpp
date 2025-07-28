#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs)
{
	std::cout << "Cure Assigment operator called" << std::endl;
	if (this != &rhs)
	{
	}
	return(*this);
}

AMateria* Cure::clone() const
{
	std::cout << "Cure Materia cloned !" << std::endl;
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << std::endl;
}
