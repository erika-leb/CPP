# include "Bureaucrat.hpp"

int main ()
{
	try
	{
		std::cout << "=========Bureaucrat construction=========" << std::endl;
		Bureaucrat a("Johnny", 150);
		Bureaucrat b("Brad", 25);
		std::cout << "=========Form construction=========" << std::endl;
		Form f("car purchase", 100, 50);
		// std::cout << "=========Form construction (failure)=========" << std::endl;
		// Form r("yatch purchase", 0, 100);
		std::cout << "=========Form details=========" << std::endl;
		std::cout << f << std::endl;
		std::cout << "=========Signature test (failure)=========" << std::endl;
		a.signForm(f);
		std::cout << "=========Signature test (success)=========" << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception catched: " << e.what() << std::endl;
	}

}
