#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap 
{
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string n);
		DiamondTrap(const DiamondTrap& oth);
		DiamondTrap& operator=(const DiamondTrap& oth);

		~DiamondTrap();

		std::string getName() const;
		void		setName(const std::string& name);

		void attack(const std::string& target);
		void whoAmI();
		
	private:
		std::string	_name;

};

#endif