#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {

	public :
		Character();
		Character(std::string name);
		Character(const Character &src);
		~Character();
		Character &operator=(const Character &rhs);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	protected :
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_garbage[100];
} ;

#endif
