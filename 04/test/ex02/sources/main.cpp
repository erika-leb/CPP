#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// Animal an; //tester si la classe est bien abstraite
	Animal* animals[10];
	for (int i = 0; i < 5; ++i)
		animals[i] = new Dog();
	for (int i = 5; i < 10; ++i)
		animals[i] = new Cat();

	// test polymorphisme
	for (int i = 0; i < 10; ++i)
		animals[i]->makeSound();

	// nettoyage
	for (int i = 0; i < 10; ++i)
		delete animals[i];

	// Animal* a = new Animal();

	return(0);
}
