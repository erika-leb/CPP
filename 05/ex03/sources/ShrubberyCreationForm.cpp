#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137),  _target("unknown")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137),  _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("Shrubbery Creation Form", 145, 137) , _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeToExec())
		throw (GradeTooLowException());
	if (isSigned() == false)
		throw(NotSignedException());
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file)
	{
		std::cerr << "Error: file not created" << std::endl;
		return ;
	}
	file << "   /\\      /\\   " << std::endl;
	file << "  /  \\    /  \\  " << std::endl;
	file << " /----\\  /----\\ " << std::endl;
	file << "   ||       ||   " << std::endl;
	file << "   ||       ||   " << std::endl;
	file.close();
	std::cout << "tree file created with success" << std::endl;
}
