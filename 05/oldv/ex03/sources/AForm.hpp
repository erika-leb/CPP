#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &src);
		virtual ~AForm();
		AForm &operator=(const AForm &rhs);

		const std::string &getName() const;
		const int &getGradeToSign() const;
		const int &getGradeToExec() const;
		bool getSigned() const;
		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		} ;

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		} ;

		virtual void execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _signed;

};

std::ostream &operator<<(std::ostream &os, AForm &Form);

#endif
