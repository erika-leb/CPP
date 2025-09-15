#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base * generate(void)
{
	srand(time(NULL));
	int r = rand() % 3;
	if (r == 0)
	{
		std::cout << "Type A created" << std::endl;
		return (new A);
	}
	if (r == 1)
	{
		std::cout << "Type B created" << std::endl;
		return (new B);
	}
	if (r == 2)
	{
		std::cout << "Type C created" << std::endl;
		return (new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception &e)
		{
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "no type: " << e.what() << std::endl;
			}
		}
	}
}
