#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5),  _target("unknown")
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5),  _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("Presidential Pardon Form", 25, 5) , _target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeToExec())
		throw (GradeTooLowException());
	if (isSigned() == false)
		throw(NotSignedException());
	std::cout << _target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}
