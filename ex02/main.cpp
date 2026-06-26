#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
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
    ClapTrap base("Clap");
    FragTrap frag("Frag");
	ScavTrap scav("Scav");
    printData(base);
    printData(frag);
	printData(scav);

    std::cout << "=== Test for attack ===" << std::endl;
	FragTrap a("f-1");
	a.attack("Frag");
	base.attack("Frag");
	frag.takeDamage(a.getAttackdamage());
	scav.attack("Frag");
	frag.takeDamage(scav.getAttackdamage());
	printData(a);
	printData(frag);
	printData(scav);

	std::cout << "=== Test for repair ===" << std::endl;
	a.beRepaired(20);
	frag.beRepaired(10);
	printData(a);
	printData(frag);
	
	std::cout << "=== Test for highFive ===" << std::endl;
	frag.highFivesGuys();

    return 0;
}