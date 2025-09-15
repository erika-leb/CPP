#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	Kumar("Kumar", 150);
	Bureaucrat	Harold("Harold", 1);

	ShrubberyCreationForm	*f1 = new ShrubberyCreationForm("Garden");
	RobotomyRequestForm		f2("Atom");
	PresidentialPardonForm	f3("Dallas");

	std::cout <<"--------------ALL OF THIS SHOULD NOT WORK--------------" << std::endl;
	//Kumar has not the required grade to Sign/Exec the forms
	// Kumar.signForm(*f1);
	Kumar.executeForm(*f1);

	//Harold can't execute the form because it's not signed
	Harold.executeForm(f2);

	std::cout << "---------------ALL OF THIS SHOULD WORK---------------" << std::endl;

	// Harold.signForm(*f1);
	// Harold.signForm(f2);
	// Harold.signForm(f3);

	Harold.executeForm(*f1);
	Harold.executeForm(f2);
	Harold.executeForm(f3);

	return (0);
}
