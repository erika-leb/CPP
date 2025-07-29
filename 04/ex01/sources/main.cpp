#include "Cat.hpp"
#include "Dog.hpp"

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }


int	main(void)
{

	std::cout << "-------------BASIC TEST-------------" << std::endl;
	Animal*	tab[10];

	for (int i = 0; i < 5; i++)
		tab[i] = new Dog;
	for (int i = 5; i < 10; i++)
		tab[i] = new Cat;

	for (int i = 0; i < 10; i++)
		delete tab[i];

	std::cout << "-------------IDEA TEST-------------" << std::endl;
	Cat*	a = new Cat;
	Dog*	b = new Dog;

	a->setIdea(0, "Run");
	b->setIdea(0, "Jump");

	std::cout << "Cat is thinking: " << a->getIdea(0) << std::endl;
	std::cout << "Dog is thinking: " << b->getIdea(0) << std::endl;

	std::cout << "-------------DEEP COPY-------------" << std::endl;
	Cat*	c = new Cat(*a);
	std::cout << "Cat copy idea: " << c->getIdea(0) << std::endl;

	std::cout << std::endl;
	delete a;
	delete b;
	delete c;

	return (0);
}
