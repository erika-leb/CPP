#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm {

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int GradeToExec);
		AForm(const AForm &src);
		virtual ~AForm();
		AForm &operator=(const AForm &rhs);

		const std::string &getName() const;
		bool isSigned() const;
		const int &getGradeToSign() const;
		const int &getGradeToExec() const;

		void beSigned (const Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		} ;

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		} ;

		class NotSignedException : public std::exception {
			public:
				const char *what() const throw();
		} ;

	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;
} ;

std::ostream &operator<<(std::ostream &os, const AForm &f);


#endif
