#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &rhs);

		std::string getType(void) const;
		virtual void makeSound() const = 0;

	protected:
		std::string _type;
} ;

#endif
