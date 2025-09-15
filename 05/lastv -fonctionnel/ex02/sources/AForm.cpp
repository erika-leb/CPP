# include "AForm.hpp"

AForm::AForm() : _name("unknown"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "AForm constructor called" << std::endl;
}
AForm::AForm (std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw(GradeTooLowException());
	if (gradeToSign < 1 || gradeToExec < 1)
		throw(GradeTooHighException());
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	_signed = false;
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Error: grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error: grade too low");
}


std::string AForm::getName() const
{
	return (_name);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return(_gradeToExec);
}

bool AForm::isSigned() const
{
	return (_signed);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign && _signed == false)
		_signed = true;
	else if (_signed == true)
	 std::cout << _name << " form is already signed" << std::endl;
	else
		throw(GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form name: " << form.getName() << "; grade to sign: " << form.getGradeToSign() << "; grade to execute: " << form.getGradeToExec() << "; signed: " << form.isSigned();
	return (os);
}

