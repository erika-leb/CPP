#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45),  _target("unknown")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45),  _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("Robotomy Request Form", 72, 45) , _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeToExec())
		throw (GradeTooLowException());
	if (isSigned() == false)
		throw(NotSignedException());
	srand(time(NULL));
	bool x = rand() % 2;
	std::cout << "dring dring: ";
	if (x == true)
		std::cout << _target << " has been robotized with success" << std::endl;
	else
		std::cout << _target << " has failed to be robotized" << std::endl;
}
