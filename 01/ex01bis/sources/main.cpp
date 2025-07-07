#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(10, "Clementine");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete []horde;
	return (0);
}
