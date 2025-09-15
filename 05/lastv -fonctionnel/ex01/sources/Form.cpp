# include "Form.hpp"

Form::Form() : _name("unknown"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Form constructor called" << std::endl;
}
Form::Form (std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw(GradeTooLowException());
	if (gradeToSign < 1 || gradeToExec < 1)
		throw(GradeTooHighException());
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	_signed = false;
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: grade too low");
}


std::string Form::getName() const
{
	return (_name);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExec() const
{
	return(_gradeToExec);
}

bool Form::isSigned() const
{
	return (_signed);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw(GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << "; grade to sign: " << form.getGradeToSign() << "; grade to execute: " << form.getGradeToExec() << "; signed: " << form.isSigned();
	return (os);
}

