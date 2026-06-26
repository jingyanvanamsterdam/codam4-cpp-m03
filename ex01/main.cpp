#include "ClapTrap.hpp"
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
    ScavTrap scav("Scav");
    printData(base);
    printData(scav);

    std::cout << "=== Test for attack ===" << std::endl;
	ScavTrap a("s-1");
	a.attack("Scav");
	base.attack("Scav");
	scav.takeDamage(a.getAttackdamage());
	printData(a);
	printData(scav);

    return 0;
}