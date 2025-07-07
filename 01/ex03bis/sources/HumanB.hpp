#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	public:
		HumanB(std::string name);
		~HumanB(void);

		void	attack(void) const;
		// void	setWeapon(Weapon &w);
		void	setWeapon(Weapon *w);

	private:
		std::string _name;
		Weapon		*_w;

} ;

#endif
