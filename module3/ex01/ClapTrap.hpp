#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iomanip>
# include <iostream>
# include <stdint.h>
# include <string>

class ClapTrap
{
  public:
	ClapTrap();
    ClapTrap(const std::string &n_name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	ClapTrap(ClapTrap &&other) noexcept;
	ClapTrap &operator=(ClapTrap &&other) noexcept;
	~ClapTrap();
    int get_ad();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

  private:
	int hitpoints;
	int energypoints;
	int attackDamage;
    std::string name;
};



#endif