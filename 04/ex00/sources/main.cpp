#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-----ANIMAL TESTS------" <<std::endl<<std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const Animal* m = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << m->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	m->makeSound();
	delete meta;
	delete j;
	delete i;
	delete m;
	std::cout <<std::endl << "-----WRONG ANIMAL TESTS------" <<std::endl<<std::endl;
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongCat *k = new WrongCat();
	const WrongAnimal* n = new WrongCat();
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << n->getType() << " " << std::endl;
	wrong->makeSound();
	k->makeSound();
	n->makeSound(); //ne sort pas le bruit du chat
	delete wrong;
	delete k;
	delete n;
	return 0;
}
