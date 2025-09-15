#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}


Intern::Intern(const Intern &src)
{
	(void) src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string list[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *f;

	for (int i = 0; i < 3; i++)
	{
		if (list[i] == formName)
		{
			switch (i)
			{
				case (0) :
				{
					f = new RobotomyRequestForm(target);
					std::cout << "Intern creates " << formName << " form" << std::endl;
					return (f);
				}
				case (1) :
				{
					f = new PresidentialPardonForm(target);
					std::cout << "Intern creates " << formName << " form" << std::endl;
					return (f);
				}
				case (2) :
				{
					f = new ShrubberyCreationForm(target);
					std::cout << "Intern creates " << formName << " form" << std::endl;
					return (f);
				}
			}
		}
	}
	throw(InvalidFileTypeException());
}

const char *Intern::InvalidFileTypeException::what() const throw()
{
	return ("File type invalid");
}
