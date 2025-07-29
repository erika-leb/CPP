#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog &operator=(const Dog &rhs);

		void makeSound(void) const;
		void setIdea(int idx, std::string idea);
		std::string getIdea(int idx) const;

	private:
		Brain *_brain;
} ;

#endif
