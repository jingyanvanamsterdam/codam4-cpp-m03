#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# define GREEN	"\033[32m"
# define RED	"\033[31m"
# define RESET	"\033[0m"

#include <string>

class ClapTrap
{
	public:
		ClapTrap(const std::string n);
		ClapTrap(const ClapTrap& oth);
		ClapTrap& operator=(const ClapTrap& oth);

		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string		getName() const;
		unsigned int	getHitptr() const;
		unsigned int	getEnergyptr() const;
		unsigned int	getAttackdamage() const;
		
		void			setName(std::string	name);
		void			setHitptr(unsigned int nbr);
		void			setEnergyptr(unsigned int nbr);
		void			setAttackdamage(unsigned int nbr);


	private:
		ClapTrap(void);
		std::string		_name;
		unsigned int	_hitptr;
		unsigned int	_energyptr;
		unsigned int	_attackdamage;
		
};

#endif