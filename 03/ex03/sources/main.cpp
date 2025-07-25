# include "DiamondTrap.hpp"

int main() {

	std::cout << std::endl << std::endl << "----DiamondTrap tests----" << std::endl << std::endl;
	std::cout << std::endl << "-Philippe and Frenegonde construction tests-" << std::endl << std::endl;
	DiamondTrap philippe("Philippe");
	DiamondTrap *clovis;
	DiamondTrap fulano("fulano");
	std::cout << std::endl << "-Clovis construction tests-" << std::endl << std::endl;
	clovis = new DiamondTrap("Clovis");
	std::cout << std::endl << "-functions tests-" << std::endl << std::endl;
	philippe.attack("Gontran");
	clovis->highFivesGuys();
	clovis->guardGate();
	philippe.whoAmI();
	philippe.beRepaired(2);
	clovis->takeDamage(4);
	std::cout << std::endl << "-Assignement tests-" << std::endl << std::endl;
	fulano = philippe;
	fulano.attack("Florimond");
	fulano.whoAmI();
	std::cout << std::endl << "-Destructions tests-" << std::endl << std::endl;
	delete clovis;
	return 0;
}
