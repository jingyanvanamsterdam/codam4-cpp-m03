#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// no override for virtural methods. it is for c++11;

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string n);
		ScavTrap(const ScavTrap& oth);
		ScavTrap& operator=(const ScavTrap& oth);

		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif