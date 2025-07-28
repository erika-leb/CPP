#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog &operator=(const Dog &rhs);

		void setIdeas(const int i, const std::string idea);
		std::string getIdeas(const int i) const;
		void makeSound(void) const;

	private:
		Brain *_brain;
} ;

#endif
