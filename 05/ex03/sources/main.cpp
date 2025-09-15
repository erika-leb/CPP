#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern random;
	AForm* form = NULL;
	Bureaucrat elo("Elodie", 1);

	std::cout << "---- OK! -----" << std::endl;
	try
	{
		form = random.makeForm("robotomy request", "Flo");
		elo.signForm(*form);
		elo.executeForm(*form);
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception catched: " << e.what() << std::endl;
	}


	std::cout << "---- KO! -----" << std::endl;

	AForm* unknowm_form = NULL;

	try
	{
		unknowm_form = random.makeForm("yacht request purchase", "Ger");
		delete unknowm_form;
	}
	catch (std::exception &e)
	{
		if (unknowm_form)
			delete unknowm_form;
		std::cerr << "Exception catched: " << e.what() << std::endl;
	}
	return (0);
}
