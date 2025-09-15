#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:
		Form();
		Form (std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &src);
		~Form();
		Form &operator=(const Form &rhs);

		class GradeTooHighException : public std::exception{
			public :
				const char *what() const throw();
		} ;

		class GradeTooLowException : public std::exception{
			public :
				const char *what() const throw();
		} ;

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		bool isSigned() const;

		void beSigned(const Bureaucrat &b);

	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;

};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
