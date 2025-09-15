#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &rhs);

		const std::string &getName() const;
		int getGrade() const;

		void decrementGrade(int n);
		void incrementGrade(int n);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();

		};

		class GradeTooLowException : public std::exception {
			public :
				const char *what() const throw();
		} ;

		void signForm(AForm &form);
		void executeForm(AForm const & form) const;

	private:
		const std::string _name;
		int _grade;
} ;

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
