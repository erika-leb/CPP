#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &src);
		virtual ~Animal();
		Animal &operator=(const Animal &rhs);

		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string _type;
} ;

#endif
