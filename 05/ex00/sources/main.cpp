#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat *b = NULL;
	//tester de creer un Bureaucrat avec une note trop basse 200
	try
	{
		std::cout << "=========Bureaucrat construction=========" << std::endl;
		Bureaucrat a("Johnny", 150);
		std::cout << "=========Bureaucrat pointer construction=========" << std::endl;
		b = new Bureaucrat("Brad", 1);
		std::cout << "=========Presentation of the two bureaucrats =========" << std::endl;
		std::cout << a << std::endl;
		std::cout << "b name: " << b->getName() << "; grade: " << b->getGrade() << std::endl;
		std::cout << "=========Incrementation test=========" << std::endl;
		a.incrementGrade(2);
		std::cout << a << std::endl;
		std::cout << "=========Decrementation test=========" << std::endl;
		b->decrementGrade(1);
		std::cout << *b << std::endl;
		std::cout << "=========Exception test=========" << std::endl;
		b->incrementGrade(2);
		std::cout << *b << std::endl;
		delete b;
	}
	catch (std::exception &e)
	{
		if (b)
			delete b;
		std::cerr << "Exception catched: " << e.what() << std::endl;
	}
}
