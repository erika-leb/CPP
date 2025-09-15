#include"Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("unkwown"), _grade(150)
{
	std::cout << " Bureaucrat " << _name << " is created with grade " << _grade << std::endl;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << " Bureaucrat " << _name << " is created with grade " << _grade << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << " Bureaucrat " << _name << " is created by copy with grade " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << " Bureaucrat " << _name << " is destroyed" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

int &Bureaucrat::getGrade()
{
	return (_grade);
}

void Bureaucrat::incrementGrade(int n)
{
	_grade -= n;
	if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	std::cout << "Bureaucrat " << _name << " incremented his/her grade to " << _grade <<std::endl;
}

void Bureaucrat::decrementGrade(int n)
{
	_grade += n;
	if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Bureaucrat " << _name << " decremented his/her grade to " << _grade <<std::endl;
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
	std::cout << "Bureaucrat " << _name << " signed " << form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
