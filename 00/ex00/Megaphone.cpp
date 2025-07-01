#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int k;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (av[i])
	{
		k = 0;
		while (av[i][k])
		{
			std::cout << (char) std::toupper(av[i][k]);
			k++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
