#include "AForm.hpp"

AForm::AForm() : _name("unknown"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw(GradeTooLowException());
	if (gradeToSign < 1 || gradeToExec < 1)
		throw(GradeTooHighException());
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name),  _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

const std::string &AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_signed);
}

const int &AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

const int &AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

void AForm::beSigned (const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw(GradeTooLowException());
	else
		_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("form not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm name : " << f.getName() << "; signed : " << f.isSigned() << "; grade to sign : " << f.getGradeToSign() << "; grade to execute : " << f.getGradeToExec();
	return (os);
}
