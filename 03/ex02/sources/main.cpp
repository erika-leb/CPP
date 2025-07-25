# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main() {

	// std::cout << std::endl << std::endl << "----ClapTrap tests----" << std::endl << std::endl;
	// ClapTrap charles("Charles");
	// ClapTrap *louis;
	// louis = new ClapTrap("Louis");
	// louis->attack("Elisabeth");
	// delete louis;

	// std::cout << std::endl << std::endl << "----ScavTrap tests----" << std::endl << std::endl;
	// ScavTrap henri("Henri");
	// ScavTrap *francois;
	// francois = new ScavTrap("Francois");
	// henri.attack("Isabel");
	// francois->guardGate();
	// henri.beRepaired(2);
	// francois->takeDamage(4);
	// delete francois;

	std::cout << std::endl << std::endl << "----FragTrap tests----" << std::endl << std::endl;
	FragTrap philippe("Philippe");
	FragTrap *clovis;
	clovis = new FragTrap("Clovis");
	philippe.attack("Gontran");
	clovis->highFivesGuys();
	philippe.beRepaired(2);
	clovis->takeDamage(4);
	delete clovis;
	return 0;
}
