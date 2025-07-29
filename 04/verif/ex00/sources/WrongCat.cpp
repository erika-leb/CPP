#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal ("WrongCat")
{
	std::cout << "WrongCat constructor called" <<std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" <<std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat desctructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "miaou" <<std::endl;
}
