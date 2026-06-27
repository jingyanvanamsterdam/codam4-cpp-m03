#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string n);
		FragTrap(const FragTrap& oth);
		FragTrap& operator=(const FragTrap& oth);

		~FragTrap();
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif