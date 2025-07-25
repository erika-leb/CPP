#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &rhs);

		void attack(const std::string& target);
		void guardGate();

	protected:
		static const unsigned int _defaultHitP = 100;
		static const unsigned int _defaultEnerP = 50;
		static const unsigned int _defaultAttD = 20;

} ;

# endif
