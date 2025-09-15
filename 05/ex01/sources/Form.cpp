#include "Form.hpp"

Form::Form() : _name("unknown"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw(GradeTooLowException());
	if (gradeToSign < 1 || gradeToExec < 1)
		throw(GradeTooHighException());
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &src) : _name(src._name),  _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

const std::string &Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_signed);
}

const int &Form::getGradeToSign() const
{
	return (_gradeToSign);
}

const int &Form::getGradeToExec() const
{
	return (_gradeToExec);
}

void Form::beSigned (const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw(GradeTooLowException());
	else
		_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: grade too low");
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form name : " << f.getName() << "; signed : " << f.isSigned() << "; grade to sign : " << f.getGradeToSign() << "; grade to execute : " << f.getGradeToExec();
	return (os);
}
