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
	std::cout << obj.ScavTrap::getName() << " is scv name\n";
	std::cout << obj.FragTrap::getName() << " is frg name\n";
	std::cout << "hit ptr: " << obj.getHitptr() << "; "
		      << obj.ScavTrap::getHitptr() << "; " 
			  << obj.FragTrap::getHitptr() << std::endl;
	std::cout << "energy ptr: " << obj.getEnergyptr() << "; "
			<< obj.ScavTrap::getEnergyptr() << "; " 
			<< obj.FragTrap::getEnergyptr() << std::endl;

	std::cout << "attack damage: " << obj.getAttackdamage() << "; "
			<< obj.ScavTrap::getAttackdamage() << "; " 
			<< obj.FragTrap::getAttackdamage() << std::endl;
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

	std::cout << "=== Test for repair ===" << std::endl;
	diam.beRepaired(20);
	frag.beRepaired(10);
	printDiam(diam);
	printData(frag);
	
	std::cout << "=== Test for inherit methods ===" << std::endl;
	diam.highFivesGuys();
	diam.guardGate();

	std::cout << "=== Test for self methods ===" << std::endl;
	diam.whoAmI();

	std::cout << "=== Test for setName ===" << std::endl;
	diam.setName("Newbie");
	printDiam(diam);

    return 0;
}