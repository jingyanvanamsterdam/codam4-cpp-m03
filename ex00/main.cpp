#include "ClapTrap.hpp"
#include <iostream>
#include <string>

void	printData(ClapTrap& obj)
{
	std::cout << "-------------" << std::endl;
	std::cout << obj.getName() << ": \n";
	std::cout << "hit ptr: " << obj.getHitptr() << std::endl;
	std::cout << "energy ptr: " << obj.getEnergyptr() << std::endl;
	std::cout << "attack damage: " << obj.getAttackdamage() << std::endl;
 	std::cout << "-------------" << std::endl;

}

int main(void)
{
	std::cout << "=== Test for constructor ===" << std::endl;
	ClapTrap a("Jip");
	ClapTrap b("Jaap");
	ClapTrap c;
	ClapTrap b_copy(b);
	c = a;
	
	std::cout << "=== Test for attack and damage ===" << std::endl;
	a.attack("Jaap");
	b.takeDamage(10);
	printData(a);
	printData(b);

	std::cout << "=== Test for repair ===" << std::endl;
	a.beRepaired(2);
	b.beRepaired(4);
	printData(a);
	printData(b);

	std::cout << "=== Test for overload damage ===" << std::endl;
	b.attack("Jip");
	a.takeDamage(50);
	printData(a);
	printData(b);


	std::cout << "=== Test for b's copy ===" << std::endl;
	b_copy.attack("Jip");
	a.takeDamage(10);
	printData(a);
	std::cout << "b's copy: " << std::endl;
	printData(b_copy);
	printData(b);
}