#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(void){} 

ClapTrap::ClapTrap(const std::string n)
	: _name(n),
	  _hitptr(10),
	  _energyptr(10),
	  _attackdamage(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& oth)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = oth;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& oth)
{
	std::cout << GREEN << "Operater overload = is called" << RESET << std::endl;
	if (this != &oth)
	{
		this->_name = oth.getName();
		this->_energyptr = oth.getEnergyptr();
		this->_hitptr = oth.getHitptr();
		this->_attackdamage = oth.getAttackdamage();
	}
	return (*this);
}

std::string		ClapTrap::getName() const
{
	return (this->_name);
}
unsigned int	ClapTrap::getHitptr() const
{
	return (this->_hitptr);
}
unsigned int	ClapTrap::getEnergyptr() const
{
	return (this->_energyptr);
}
unsigned int	ClapTrap::getAttackdamage() const
{
	return (this->_attackdamage);
}

void			ClapTrap::setName(std::string	name)
{
	this->_name = name;
}
void			ClapTrap::setHitptr(unsigned int nbr)
{
	this->_hitptr = nbr;
}
void			ClapTrap::setEnergyptr(unsigned int nbr)
{
	this->_energyptr = nbr;
}
void			ClapTrap::setAttackdamage(unsigned int nbr)
{
	this->_attackdamage = nbr;
}
ClapTrap::~ClapTrap()
{
	std::cout << RED << "Desctructor called." << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyptr <= 0)
		std::cout << this->_name << " try to attack but no energy points left\n";
	else
	{
		std::cout << this->_name << " attacks " << target << ", causing ";
		std::cout << this->_attackdamage << " points of damage!\n";
		this->_energyptr -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " got attacked,";

	if (amount > this->_hitptr)
		this->_hitptr = 0;
	else
		this->_hitptr -= amount;

	std::cout << " hit ptr is reduced." << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyptr <= 0)
		std::cout << this->_name << " try to repair but no energy points left\n";
	else
	{
		std::cout << this->_name << " reparied " << "with ";
		std::cout << amount << " points for hit points!\n";
		this->_hitptr += amount;
		this->_energyptr -= 1;
	}
}