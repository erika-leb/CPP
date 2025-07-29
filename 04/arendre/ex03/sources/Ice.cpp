#include "Ice.hpp"
#include "ICharacter.hpp"

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
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return (*this);
}
AMateria* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}