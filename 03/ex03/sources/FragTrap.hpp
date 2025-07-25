#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		FragTrap &operator=(const FragTrap &rhs);

		void attack(const std::string& target);
		void highFivesGuys(void);

	protected:
		static const unsigned int _defaultHitP = 100;
		static const unsigned int _defaultEnerP = 100;
		static const unsigned int _defaultAttD = 30;
} ;

#endif
