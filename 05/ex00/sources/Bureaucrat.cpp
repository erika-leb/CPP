#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150)
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
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
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &rhs)
        _grade = rhs._grade;
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}


void Bureaucrat::incrementGrade(int nb)
{
    if (_grade - nb < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade -= nb;
}

void Bureaucrat::decrementGrade(int nb)
{
    if (_grade + nb > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade += nb;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Error: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error: Grade too low");    
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}