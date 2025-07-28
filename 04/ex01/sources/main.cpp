#include "Cat.hpp"
#include "Dog.hpp"

// int main()
// {
// 	std::cout << "-----ANIMAL TESTS------" <<std::endl;
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	const Animal* m = new Dog();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	std::cout << m->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	m->makeSound();
// 	delete meta;
// 	delete j;
// 	delete i;
// 	delete m;
// 	return 0;
// }

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	return 0;
}


int	main(void)
{

	std::cout << "==============TABLE TEST==============" << std::endl;
	Animal*	tab[10];

	for (int i = 0; i < 5; i++)
		tab[i] = new Dog;
	for (int i = 5; i < 10; i++)
		tab[i] = new Cat;

	for (int i = 0; i < 10; i++)
		delete tab[i];

	std::cout << "==============IDEAS TEST==============" << std::endl;
	Cat*	a = new Cat;
	Dog*	b = new Dog;

	a->setIdeas(0, "Sleep");
	b->setIdeas(0, "Eat");

	std::cout << "Cats: " << a->getIdeas(0) << std::endl;
	std::cout << "Dogs: " << b->getIdeas(0) << std::endl;

	std::cout << "==============DEEP COPY==============" << std::endl;
	Cat*	c = new Cat(*a);
	std::cout << "Cat copy idea: " << c->getIdeas(0) << std::endl;

	delete a;
	delete b;
	delete c;

	return (0);
}
