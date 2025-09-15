#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor called for " << _type << std::endl;
}

AMateria::AMateria(const AMateria &src) : _type(src._type) //inutile apparement
{
	std::cout << "Copy AMateria constructor called for " << _type << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called"  << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
	{
		std::cout << "AMateria assignment operator called for " << rhs._type << std::endl;
		this->_type = rhs._type;
	}
	else
		std::cout << "AMateria assignment operator called for the same instance" << std::endl;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "hola co" << " *" <<std::endl;
	std::cout << _type << "Materia's use on " << target.getName() << std::endl;
}

