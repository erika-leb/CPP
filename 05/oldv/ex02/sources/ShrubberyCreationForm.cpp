#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("unknown")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getGradeToExec() >= executor.getGrade())
	{
		std::string filename = _target + "_shrubbery";
		std::ofstream treeFile(filename. c_str()); //mettre un catch pour ici
		treeFile << "   /\\   " << std::endl;
		treeFile << "  /  \\  " << std::endl;
		treeFile << " /----\\ " << std::endl;
		treeFile << "   ||   " << std::endl;
		treeFile << "   ||   " << std::endl;
		treeFile.close();
		std::cout << "tree file created with success" << std::endl;
	}
	else
		throw(AForm::GradeTooLowException());
}
