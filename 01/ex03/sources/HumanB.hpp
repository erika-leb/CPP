#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

// class HumanB {

// 	public:
// 		HumanB(void);
// 		~HumanB(void);

// 		void	attack(void);

// 	private:
// 		std::string	name;
// 		Weapon		weapon;
// };

class HumanB
{
	public:
		HumanB(void);
		HumanB(std::string type);
		~HumanB(void);

		void	attack(void) const;
		void	setWeapon(Weapon& w);

	private:
		std::string	name;
		Weapon*		_w_ptr;
};

#endif
