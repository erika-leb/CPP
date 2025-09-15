# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
	std::cout << _name << " constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw(GradeTooHighException());
	_grade = grade;
	std::cout << _name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << _name << " copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << " destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::decrementGrade(int n)
{
	if (_grade + n > 150)
		throw(GradeTooLowException());
	_grade += n;
	std::cout << _name << " bureaucrat was decreased to " << n << " grades" << std::endl;
}
void Bureaucrat::incrementGrade(int n)
{
	if (_grade - n < 1)
		throw(GradeTooHighException());
	_grade -= n;
	std::cout << _name << " bureaucrat was rised to " << n << " grades" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error : grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error : grade too low");
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
