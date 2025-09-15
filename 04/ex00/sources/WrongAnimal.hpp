#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		virtual~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &rhs);

		std::string getType(void) const;
		void makeSound() const;

	protected:
		std::string _type;

} ;

#endif
