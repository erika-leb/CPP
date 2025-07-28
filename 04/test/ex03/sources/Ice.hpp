#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;
class AMateria;

class Ice : public AMateria {

	public:
		Ice();
		Ice(const Ice &src);
		~Ice();
		Ice &operator=(const Ice &rhs);

		AMateria* clone() const;
		void use(ICharacter& target);
} ;

#endif
