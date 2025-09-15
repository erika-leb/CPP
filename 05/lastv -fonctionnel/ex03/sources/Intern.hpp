#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class Intern {

	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &rhs);

		AForm *makeForm(std::string formName, std::string formTarget);

		class InextingForm : public std::exception {
			const char *what() const throw();
		} ;

};

#endif
