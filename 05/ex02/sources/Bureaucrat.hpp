#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat {

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &rhs);

		std::string getName() const;
		int getGrade() const;

		void incrementGrade(int n);
		void decrementGrade(int n);

		void signForm(AForm &f) const ;
		void executeForm(AForm const & form) const;

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
		int _grade;
} ;

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);


#endif
