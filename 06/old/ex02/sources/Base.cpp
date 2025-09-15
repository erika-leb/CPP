#include "B.hpp"
#include "A.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base * generate(void)
{
	srand(time(NULL));
	int r = std::rand() % 3;
	if (r == 0)
	{
		std::cout << "Type A created";
		return (new A);
	}
	if (r == 1)
	{
		std::cout << "Type B created";
		return (new B);
	}
	if (r == 2)
	{
		std::cout << "Type Ccreated";
		return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try {
			dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "no type: " << e.what() << std::endl;
			}
		}
	}
}
