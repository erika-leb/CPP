#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: please indicate a file to open" << std::endl;
		return (1);
	}


	try {

		BitcoinExchange bt("data.csv");
		bt.processInput(av[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
