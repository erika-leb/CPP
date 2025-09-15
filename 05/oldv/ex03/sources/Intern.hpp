#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &rhs);
		AForm *makeForm(std::string name, std::string form);
} ;

#endif
