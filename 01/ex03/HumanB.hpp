#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <ctime>
# include <iomanip>
# include <iostream>
# include <string>

class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
	void attack();
	void setWeapon(Weapon &weapon);
	std::string get_name() const;

	HumanB(Weapon &_weapon, const std::string &name);
	HumanB(const std::string &name);
	~HumanB(void);
};

#endif