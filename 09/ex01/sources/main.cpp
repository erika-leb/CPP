# include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: enter 1 argument" << std::endl;
		return (1);
	}
	try {
		std::string str = av[1];
		RPN rpn(str);
		rpn.calculate();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error" << e.what() << std::endl;
		return (1);
	}
	return (0);
}
