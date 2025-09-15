#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	Ariel("Ariel", 150);
	Bureaucrat	Eric("Eric", 1);

	ShrubberyCreationForm	*f1 = new ShrubberyCreationForm("Sea");
	RobotomyRequestForm		f2("Ocean");
	PresidentialPardonForm	f3("Land");

	try {


		std::cout <<"--------------ALL OF THIS SHOULD NOT WORK--------------" << std::endl;
		//Ariel has not the required grade to Sign/Exec the forms
		Ariel.signForm(*f1);
		Ariel.executeForm(*f1);

		//Eric can't execute the form because it's not signed
		Eric.executeForm(f2);

		std::cout << "---------------ALL OF THIS SHOULD WORK---------------" << std::endl;

		Eric.signForm(*f1);
		Eric.signForm(f2);
		Eric.signForm(f3);

		Eric.executeForm(*f1);
		Eric.executeForm(f2);
		Eric.executeForm(f3);
		delete f1;
	}
	catch(std::exception &e)
	{
		if (f1)
			delete (f1);
		std::cerr << "Execption catched: " << e.what() << std::endl;
	}

	return (0);
}
