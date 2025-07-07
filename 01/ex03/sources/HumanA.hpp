#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

// class HumanA {

// 	public:
// 		HumanA(void);
// 		~HumanA(void);

// 		void	attack(void);

// 	private:
// 		std::string	name;
// 		Weapon		weapon;
// };

class HumanA
{
	public:
		HumanA(std::string name, Weapon &w);
		~HumanA(void);

		void	attack(void) const;

	private:
		std::string	name;
		Weapon&		_w_ref;
};



#endif
