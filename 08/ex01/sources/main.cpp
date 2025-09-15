#include "Span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int main( void )
{
	std::cout << "----- SUBJECT TEST -----" << std::endl;

	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " <<  e.what() << std::endl;
	}

	std::cout << "----- REAL TEST -----" << std::endl;

	try
	{
		srand(static_cast<unsigned int>(time(NULL)));
		std::vector<int> v(10000);
		for (size_t i = 0; i < 10000; i++)
			v[i] = rand() % 42000;

		Span bigSp(10000);
		bigSp.addRange(v.begin(), v.end());
		std::cout << "longest: " << bigSp.longestSpan() << std::endl;
		std::cout << "shortest: " << bigSp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
