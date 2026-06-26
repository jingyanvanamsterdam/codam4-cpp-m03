#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << GREEN << "Default ScavTrap constructor called" << RESET << std::endl;
} 


ScavTrap::ScavTrap(const std::string n)
	: ClapTrap(n)
{
	std::cout << GREEN << "ScavTrap Constructor called" << RESET << std::endl;
	this->_hitptr = 100;
	this->_energyptr = 50;
	this->_attackdamage = 20;
}
// 如果为了封装更好，可以吧剩下三个值也作为ClapTrap的parameters。
//ScavTrap::ScavTrap(const std::string n)
//	: ClapTrap(n, 100, 50, 20)
//{
//	std::cout << GREEN << "ScavTrap Constructor called" << RESET << std::endl;
//}

ScavTrap::ScavTrap(const ScavTrap& oth)
{
	std::cout << GREEN << "ScavTrap Copy constructor called" << RESET << std::endl;
	*this = oth;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& oth)
{
	std::cout << GREEN << "ScavTrap Operater overload = is called" << RESET << std::endl;
	if (this != &oth)
	{
		this->_name = oth.getName();
		this->_energyptr = oth.getEnergyptr();
		this->_hitptr = oth.getHitptr();
		this->_attackdamage = oth.getAttackdamage();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "Desctructor ScavTrap called." << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyptr <= 0)
		std::cout << "ScavTrap " << this->_name << " try to attack but no energy points left\n";
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing ";
		std::cout << this->_attackdamage << " points of damage!\n";
		this->_energyptr -= 1;
	}
}

void ScavTrap::guardGate()
{
	std::cout << this->_name << " is now in Gate Keeper mode." << std::endl;
}