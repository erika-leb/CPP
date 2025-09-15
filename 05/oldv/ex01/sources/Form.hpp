#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form {

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &src);
		~Form();
		Form &operator=(const Form &rhs);

		const std::string &getName() const;
		const int &getGradeToSign() const;
		const int &getGradeToExec() const;
		bool getSigned();
		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		} ;

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		} ;

	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExec;
		bool _signed;

};

std::ostream &operator<<(std::ostream &os, Form &Form);

#endif
