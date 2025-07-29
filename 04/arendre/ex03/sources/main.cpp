#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <stdio.h>

int main(void)
{
    std::cout << "=== Initialisation de la MateriaSource ===" << std::endl;
    IMateriaSource* source = new MateriaSource();

    std::cout << "\n=== Apprentissage des Materias ===" << std::endl;
    source->learnMateria(new Cure());
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Ice());
    source->learnMateria(new Cure()); // devrait échouer (5e essai)

    std::cout << "\n=== Création du personnage (hero) ===" << std::endl;
    ICharacter* hero = new Character("hero");

    std::cout << "\n=== Création et équipement des Materias ===" << std::endl;
    AMateria* materia;
    materia = source->createMateria("cure");
    hero->equip(materia);
    materia = source->createMateria("ice");
    hero->equip(materia);
    materia = source->createMateria("cure");
    hero->equip(materia);
    materia = source->createMateria("ice");
    hero->equip(materia);

    std::cout << "\n=== Tentative d'équipement supplémentaire ===" << std::endl;
    materia = source->createMateria("cure");
    hero->equip(materia); // devrait échouer car inventaire plein
    // delete materia;        // éviter fuite mémoire

    std::cout << "\n=== Création d'un autre personnage (enemy) ===" << std::endl;
    ICharacter* enemy = new Character("enemy");
    hero->use(0, *enemy);
    hero->use(1, *enemy);
    hero->use(10, *enemy); // index invalide

    std::cout << "\n=== Test du constructeur de copie ===" << std::endl;
    Character copyHero(*(Character*)hero); // clone de hero
    copyHero.use(0, *enemy);
    copyHero.use(1, *enemy);

    std::cout << "\n=== Test de l'opérateur d'assignation ===" << std::endl;
    Character anotherHero;
    anotherHero = *(Character*)hero;
    anotherHero.use(2, *enemy);

    std::cout << "\n=== On vide l'inventaire du héros ===" << std::endl;
    for (int i = 0; i < 4; i++)
        hero->unequip(i);
    hero->unequip(2); // slot déjà vide

    std::cout << "\n=== Fin du programme ===" << std::endl;
    delete enemy;
    delete hero;
    delete source;

    return 0;
}
