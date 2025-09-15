#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {

	public:
		Form();
		Form(std::string name, int gradeToSign, int GradeToExec);
		Form(const Form &src);
		~Form();
		Form &operator=(const Form &rhs);

		const std::string &getName() const;
		bool isSigned() const;
		const int &getGradeToSign() const;
		const int &getGradeToExec() const;

		void beSigned (const Bureaucrat &b);
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
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;
} ;

std::ostream &operator<<(std::ostream &os, const Form &f);


#endif
