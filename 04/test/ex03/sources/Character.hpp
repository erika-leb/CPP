#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter{

	public:
		Character();
		Character(std::string name);
		Character(const Character &src);
		~Character();
		Character &operator=(const Character &rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria *_items[4];
		AMateria *_garbage[100];
} ;

#endif
