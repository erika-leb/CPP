# include "ClapTrap.hpp"

int main() {
    ClapTrap bob("Bob");
    ClapTrap alice("Alice");

    std::cout << "\n--- Test 1: Bob attaque Alice ---\n";
    bob.attack("Alice");
    alice.takeDamage(0); // on suppose que bob a 0 de dégâts au départ

    std::cout << "\n--- Test 2: Bob gagne 5 hit points ---\n";
    bob.beRepaired(5); // +5 HP, -1 énergie

    std::cout << "\n--- Test 3: Bob reçoit 3 dégâts ---\n";
    bob.takeDamage(3); // -3 HP

    std::cout << "\n--- Test 4: Alice attaque avec 0 énergie ---\n";
    // Consomme toute son énergie
    for (int i = 0; i < 11; ++i) {
        alice.attack("Bob");
    }

    std::cout << "\n--- Test 5: Alice tente de se réparer sans énergie ---\n";
    alice.beRepaired(10); // échoue normalement si énergie == 0

    std::cout << "\n--- Test 6: Bob subit des dégâts létaux ---\n";
    bob.takeDamage(100); // doit tomber à 0 HP

    std::cout << "\n--- Test 7: Bob essaie d'attaquer en étant mort ---\n";
    bob.attack("Alice"); // ne devrait pas fonctionner

    return 0;
}
