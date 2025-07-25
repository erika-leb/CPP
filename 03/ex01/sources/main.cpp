# include "ScavTrap.hpp"

int main() {

	// ClapTrap charles("Charles");
	// ClapTrap *louis;
	ScavTrap henri("Henri");
	ScavTrap *francois;

	// louis = new ClapTrap("Louis");
	francois = new ScavTrap("Francois");
	// louis->attack("Elisabeth");
	henri.attack("Isabel");
	francois->guardGate();
	henri.beRepaired(2);
	francois->takeDamage(4);
	// delete louis;
	delete francois;
	return 0;
}

// int main() {
//     // std::cout << "=== Test 1 : Construction et destruction ===" << std::endl;
//     // {
//     //     ScavTrap s1("Scavvy");
//     //     s1.attack("target1");
//     //     s1.guardGate();
//     // } // Ici, la destruction se fait automatiquement (pile) : ScavTrap puis ClapTrap.

//     // std::cout << "\n=== Test 2 : Constructeur de copie ===" << std::endl;
//     // {
//     //     ScavTrap s2("CopySource");
//     //     ScavTrap s3(s2);  // constructeur de copie
//     //     s3.attack("target2");
//     // }

//     // std::cout << "\n=== Test 3 : Operateur = ===" << std::endl;
//     // {
//     //     ScavTrap s4("Original");
//     //     ScavTrap s5("Another");
//     //     s5 = s4;  // opérateur =
//     //     s5.attack("target3");
//     // }

//     // std::cout << "\n=== Test 4 : Test sur pile (stack) ===" << std::endl;
//     // {
//     //     ScavTrap s6("StackAllocated");
//     //     s6.guardGate();
//     // }

//     // std::cout << "\n=== Test 5 : Polymorphisme et destruction ===" << std::endl;
//     // {
//     //     ClapTrap *ptr = new ScavTrap("Dynamic");
//     //     ptr->attack("dynamicTarget");
//     //     delete ptr; // destruction : ScavTrap -> ClapTrap
//     // }

//     // std::cout << "\n=== FIN DES TESTS ===" << std::endl;

// 	ClapTrap *oui = new ScavTrap("Non");
// 	// oui->attack();
// 	delete oui;
//     return 0;
// }
