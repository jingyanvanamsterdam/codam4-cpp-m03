#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
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

void	printDiam(DiamondTrap& obj)
{
	std::cout << "-------------" << std::endl;
	std::cout << obj.getName() << ": \n";
	std::cout << "hit ptr: " << obj.FragTrap::getHitptr() << std::endl;
	std::cout << "energy ptr: " << obj.ScavTrap::getEnergyptr() << std::endl;
	std::cout << "attack damage: " << obj.FragTrap::getAttackdamage() << std::endl;
 	std::cout << "-------------" << std::endl;
}

int main(void)
{
    std::cout << "=== Test for constructor ===" << std::endl;
    ClapTrap base("Clap");
	std::cout << "=== ===" << std::endl;
    FragTrap frag("Frag");
	std::cout << "=== ===" << std::endl;
	ScavTrap scav("Scav");
	std::cout << "=== ===" << std::endl;
	DiamondTrap diam("Diam");
    printData(base);
    printData(frag);
	printData(scav);
	printDiam(diam);

    std::cout << "=== Test for attack ===" << std::endl;
	diam.attack("Someone");
	scav.attack("Someone");
	frag.attack("Iemand");
	base.attack("One man");
	printDiam(diam);
	printData(frag);
	printData(scav);
	printData(base);

	std::cout << "=== Test for repair ===" << std::endl;
	diam.ScavTrap::beRepaired(20);
	frag.beRepaired(10);
	printDiam(diam);
	printData(frag);
	
	std::cout << "=== Test for inherit methods ===" << std::endl;
	diam.highFivesGuys();
	diam.guardGate();

	std::cout << "=== Test for self methods ===" << std::endl;
	diam.whoAmI();
	
	
    return 0;
}