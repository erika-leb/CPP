#include "Cure.hpp"
#include "ICharacter.hpp"

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
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return (*this);
}
AMateria* Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}