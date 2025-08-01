#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &src);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &rhs);

		void attack(const std::string& target);
		void guardGate();
} ;

# endif
