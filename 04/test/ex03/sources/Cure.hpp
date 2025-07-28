#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;
class AMateria;

class Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure &src);
		~Cure();
		Cure &operator=(const Cure &rhs);

		AMateria* clone() const;
		void use(ICharacter& target);
} ;

#endif
