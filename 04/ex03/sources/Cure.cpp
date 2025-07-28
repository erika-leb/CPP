#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
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
	if (this != &rhs)
	{
		std::cout << "Cure assignment operator called" << std::endl;
		// this->_type = rhs._type;
	}
	else
		std::cout << "Cure assignment operator called for the same instance" << std::endl;
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " 's wounds *" <<std::endl;
}

AMateria* Cure::clone(void) const
{
	return (new Cure());
}
