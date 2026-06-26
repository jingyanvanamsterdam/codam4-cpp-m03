#include "ClapTrap.hpp"
#include <iostream>
#include <string>

void	printData(ClapTrap& obj)
{
	std::cout << "-------------" << std::endl;
	std::cout << obj.getName() << ": \n";
	std::cout << "hit ptr: " << obj.getHitptr() << std::endl;
	std::cout << "energy ptr: " << obj.getEnergyptr() << std::endl;
	std::cout << "attact damage: " << obj.getAttackdamage() << std::endl;
 	std::cout << "-------------" << std::endl;

}

int main(void)
{
	ClapTrap a("Jip");
	ClapTrap b("Jaap");

	std::cout << "Round 1" << std::endl;
	a.attack("Jaap");
	b.takeDamage(10);
	printData(a);
	printData(b);

	std::cout << "Round 2" << std::endl;
	a.beRepaired(2);
	b.beRepaired(4);
	printData(a);
	printData(b);

	std::cout << "Round 3" << std::endl;
	b.attack("Jip");
	a.takeDamage(50);
	printData(a);
	printData(b);

	ClapTrap b_copy(b);
	std::cout << "Round 4" << std::endl;
	b_copy.attack("Jip");
	a.takeDamage(10);
	printData(a);
	std::cout << "b's copy: " << std::endl;
	printData(b_copy);
	printData(b);
}