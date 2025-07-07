# include "Zombie.hpp"

int main(void)
{
	Zombie	*z1;

	z1 = newZombie("Charles");
	z1->announce();
	randomChump("Louis");
	delete z1;
	return (0);
}
