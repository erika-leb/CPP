# include "Harl.hpp"

int	main(int ac, char **ag)
{
	Harl		harl;
	std::string	str;
	if (ac != 2)
	{
		std::cout << "Enter one level of complain" << std::endl;
		return (1);
	}
	str = ag[1];
	harl.complain(str);
	return (0);
}
