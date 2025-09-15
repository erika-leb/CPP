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

// AForm *Intern::makeForm(std::string formName, std::string formTarget)
// {
// 	std::string list[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
// 	int i;
// 	AForm *f;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (list[i] == formName)
// 			break;
// 		i++;
// 	}
// 	switch (i)
// 	{
// 		case 0:
// 		{
// 			f = new RobotomyRequestForm(formTarget);
// 			std::cout << "Intern creates " << formName << " form" << std::endl;
// 			return f;
// 		}
// 		case 1:
// 		{
// 			f = new PresidentialPardonForm(formTarget);
// 			std::cout << "Intern creates " << formName << " form" << std::endl;
// 			return f;
// 		}
// 		case 2:
// 		{
// 			f = new ShrubberyCreationForm(formTarget);
// 			std::cout << "Intern creates " << formName << " form" << std::endl;
// 			return f;
// 		}
// 		default:
// 		{
// 			std::cout << "the " << formName << " form does not exist. Form not created" << std::endl;
// 			return (NULL);
// 		}
// 	}
// }

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string list[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *f;

	for (int i = 0; i < 3; i++)
	{
		if (list[i] == formName)
		{
			switch (i)
			{
				case 0:
				{
					f = new RobotomyRequestForm(formTarget);
					std::cout << "Intern creates " << formName << " form" << std::endl;
					return f;
				}
				case 1:
				{
					f = new PresidentialPardonForm(formTarget);
					std::cout << "Intern creates " << formName << " form" << std::endl;
					return f;
				}
				case 2:
				{
					f = new ShrubberyCreationForm(formTarget);
					std::cout << "Intern creates " << formName << " form" << std::endl;
					return f;
				}
			}
		}
	}
	throw(InextingForm());
	// std::cout << "the " << formName << " form does not exist. Form not created" << std::endl;
	return (NULL);
}

const char *Intern::InextingForm::what() const throw()
{
	return ("Form does not exit");
}
