#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

#define CLAP_NAME "_clap_name"

DiamondTrap::DiamondTrap(void)
{
	std::cout << GREEN << "Default DiamondTrap constructor called" << RESET << std::endl;
} 


DiamondTrap::DiamondTrap(const std::string n)
	: ScavTrap(n + CLAP_NAME),
	  FragTrap(n + CLAP_NAME),
	  _name(n)
{
	std::cout << GREEN << "DiamondTrap Constructor called" << RESET << std::endl;
	//ScavTrap::setEnergyptr(ScavTrap::getEnergyptr());
	//ScavTrap::setAttackdamage(FragTrap::getAttackdamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap& oth)
{
	std::cout << GREEN << "DiamondTrap Copy constructor called" << RESET << std::endl;
	*this = oth;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& oth)
{
	std::cout << GREEN << "DiamondTrap Operater overload = is called" << RESET << std::endl;
	if (this != &oth)
	{
		this->_name = oth.getName();
		this->ScavTrap::_energyptr = oth.ScavTrap::getEnergyptr();
		this->ScavTrap::_hitptr = oth.FragTrap::getHitptr();
		this->FragTrap::_attackdamage = oth.ScavTrap::getAttackdamage();
	}
	return (*this);
}

std::string DiamondTrap::getName() const
{
	return (this->_name);
}

void DiamondTrap::setName(const std::string& name)
{
	this->_name = name;
	ScavTrap::setName(name + CLAP_NAME);
	FragTrap::setName(name + CLAP_NAME);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "Desctructor DiamondTrap called." << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << this->_name << " is my name." << std::endl;
	std::cout << ScavTrap::_name << " is ClapTrap name." << std::endl; 
}