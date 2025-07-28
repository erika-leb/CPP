#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


#include <stdio.h>

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp); //ici
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

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

	std::cout << "\n=== Création du personnage principal (hero) ===" << std::endl;
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
	delete materia;		// éviter fuite mémoire
	materia = NULL;
	std::cout << "\n=== Création d'un autre personnage (enemy) ===" << std::endl;
	ICharacter* enemy = new Character("enemy");
	hero->use(0, *enemy);
	hero->use(1, *enemy);
	hero->use(10, *enemy); // index invalide

	std::cout << "\n=== Test du constructeur de copie ===" << std::endl;
	Character copyHero(*(Character*)hero); // clone de hero
	perror("ici");
	copyHero.use(0, *enemy);
	copyHero.use(1, *enemy);
	perror("la");

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
	enemy = NULL;
	delete hero;
	hero = NULL;
	delete source;
	source = NULL;
	perror("offre");

	return 0;
}


// int	main(void)
// {
// 	std::cout << "--- Creation of a MateriaSource ---" << std::endl;
// 	IMateriaSource* src = new MateriaSource();

// 	std::cout << std::endl << "--- Let's learn ! ---" << std::endl;
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	std::cout << std::endl << "--- Want to learn more ? ---" << std::endl;
// 	src->learnMateria(new Ice());

// 	std::cout << std::endl << "--- Creation of a Character ---" << std::endl;
// 	ICharacter* me = new Character("me");

// 	std::cout << std::endl << "--- Let's create some Materias"
// 	<< " from MateriaSource's memory ---";
// 	std::cout << std::endl << "--- and equip the Character 'me'"
// 	<< " ---" << std::endl;
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	std::cout << std::endl << "--- Want to equip more ? ---" << std::endl;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);


// 	std::cout << std::endl << "--- Replace the last Materia cure for a Materia ice ---" << std::endl;
// 	me->unequip(1);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);

// 	std::cout << std::endl << "--- Creation of Bob and use some Materias on him ---" << std::endl;
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(3, *bob);

// 	std::cout << std::endl << "--- Let's clear me's inventory ---" << std::endl;
// 	me->unequip(0);
// 	me->unequip(1);
// 	me->unequip(2);
// 	me->unequip(3);
// 	std::cout << std::endl << "--- Try to unequip an empty position ---" << std::endl;
// 	me->unequip(0);
// 	std::cout << std::endl << "--- Try to unequip a nonexistent position ---" << std::endl;
// 	me->unequip(10);


// 	std::cout << std::endl << "--- End of main() ---" << std::endl;
// 	delete bob;
// 	delete me;
// 	delete src;

// 	return (0);
// }
