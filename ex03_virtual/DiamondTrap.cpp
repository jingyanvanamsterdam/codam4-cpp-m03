#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

#define CLAP_NAME "_clap_name"

static void init_print(DiamondTrap& obj)
{
	std::cout << "In constructor: " << obj.getHitptr() <<", " << obj.getEnergyptr() << ", " << obj.getAttackdamage() << ".\n" << std::endl;
}

DiamondTrap::DiamondTrap(void)
{
	std::cout << GREEN << "Default DiamondTrap constructor called" << RESET << std::endl;
	init_print(*this);
} 


DiamondTrap::DiamondTrap(const std::string n)
	: ClapTrap(n + CLAP_NAME),
	  _name(n)
{
	std::cout << GREEN << "DiamondTrap Constructor called" << RESET << std::endl;
	this->_energyptr = 50;
	init_print(*this);
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
		this->_energyptr = oth.getEnergyptr();
		this->_hitptr = oth.getHitptr();
		this->_attackdamage = oth.getAttackdamage();
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
	ClapTrap::setName(name + CLAP_NAME);
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
	std::cout << ClapTrap::_name << " is ClapTrap name." << std::endl; 
}