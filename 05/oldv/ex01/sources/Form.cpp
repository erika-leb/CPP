#include "Form.hpp"

Form::Form() : _name("unkwown"), _gradeToSign(1), _gradeToExec(1), _signed(false)
{
	std::cout << " Form " << _name << " is created with gradeToSign " << _gradeToSign  << " and gradeToExec " << _gradeToExec << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw (Form::GradeTooHighException());
	if (gradeToSign > 150 || gradeToExec > 150)
		throw (Form::GradeTooLowException());
	std::cout << " Form " << _name << " is created with gradeToSign " << _gradeToSign  << " and gradeToExec " << _gradeToExec << std::endl;
}
Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec), _signed(src._signed)
{
	std::cout << " Form " << _name << " is created with gradeToSign " << _gradeToSign  << " and gradeToExec " << _gradeToExec << std::endl;
}

Form::~Form()
{
	std::cout << " Form " << _name << " is destroyed" << std::endl;
}
Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}

const std::string &Form::getName() const
{
	return (_name);
}

const int &Form::getGradeToSign() const
{
	return (_gradeToSign);
}

const int &Form::getGradeToExec() const
{
	return (_gradeToExec);
}

bool Form::getSigned()
{
	return (_signed);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw(Form::GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade to low");
}

std::ostream &operator<<(std::ostream &os, Form &form)
{
	os << "Form's name: " << form.getName() << ", grade to sign: " << form.getGradeToSign() << ", grade to exec: " << form.getGradeToExec() << ", signed: " << form.getSigned();
	return (os);
}
