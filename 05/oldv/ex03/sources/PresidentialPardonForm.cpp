#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("unknown")
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("PresidentialPardonForm", 25, 5), _target(src._target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getGradeToExec() >= executor.getGrade())
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw(AForm::GradeTooLowException());
}
