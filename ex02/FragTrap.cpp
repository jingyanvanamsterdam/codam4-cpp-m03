#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << GREEN << "Default FragTrap constructor called" << RESET << std::endl;
} 


FragTrap::FragTrap(const std::string n)
	: ClapTrap(n)
{
	std::cout << GREEN << "FragTrap Constructor called" << RESET << std::endl;
	this->_hitptr = 100;
	this->_energyptr = 100;
	this->_attackdamage = 30;
}

FragTrap::FragTrap(const FragTrap& oth)
{
	std::cout << GREEN << "FragTrap Copy constructor called" << RESET << std::endl;
	*this = oth;
}

FragTrap& FragTrap::operator=(const FragTrap& oth)
{
	std::cout << GREEN << "FragTrap Operater overload = is called" << RESET << std::endl;
	if (this != &oth)
	{
		this->_name = oth.getName();
		this->_energyptr = oth.getEnergyptr();
		this->_hitptr = oth.getHitptr();
		this->_attackdamage = oth.getAttackdamage();
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED << "Desctructor FragTrap called." << RESET << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energyptr <= 0)
		std::cout << "FragTrap " << this->_name << " try to attack but no energy points left\n";
	else
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing ";
		std::cout << this->_attackdamage << " points of damage!\n";
		this->_energyptr -= 1;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " request a high five!" << std::endl;
}