#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw(GradeTooHighException());
	_grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		_grade =rhs._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(int n)
{
	if (_grade - n < 1)
		throw(GradeTooHighException());
	else
		_grade -= n;
}
void Bureaucrat::decrementGrade(int n)
{
	if (_grade + n > 150)
		throw(GradeTooLowException());
	else
		_grade += n;
}

void Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << _name << " couldn't execute " << form.getName() << " because of " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: grade too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
