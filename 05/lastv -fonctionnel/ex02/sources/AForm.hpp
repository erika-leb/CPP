#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:
		AForm();
		AForm (std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &src);
		virtual ~AForm();
		AForm &operator=(const AForm &rhs);

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
		virtual void execute(Bureaucrat const &executor) const = 0;

	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;

};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif
