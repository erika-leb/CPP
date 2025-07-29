#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-----ANIMAL TESTS------" <<std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* m = new Dog();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << m->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	m->makeSound();
	delete meta;
	delete j;
	delete i;
	delete m;
	std::cout << "-----ANIMAL TESTS------" <<std::endl;
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongCat *k = new WrongCat();
	const WrongAnimal* n = new WrongCat();
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << n->getType() << " " << std::endl;
	k->makeSound(); //will not output the cat sound!
	wrong->makeSound();
	n->makeSound();
	delete wrong;
	delete k;
	delete n;
	return 0;
}
