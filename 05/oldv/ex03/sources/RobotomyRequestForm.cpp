#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getGradeToExec() >= executor.getGrade())
	{
		srand(time(NULL));
		bool x = rand() % 2;
		std::cout << "dring dring :" << std::endl;
		if (x == true)
			std::cout << _target << " has been successfully robotized" << std::endl;
		else
			std::cout << _target << "had failed to be robotized" << std::endl;
	}
	else
		throw(AForm::GradeTooLowException());
}
