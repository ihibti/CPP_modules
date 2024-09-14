#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <ctime>
# include <iomanip>
# include <iostream>
# include <string>

class HumanA
{
  private:
	std::string name;
	Weapon &weapon;

  public:
	void attack();
	void set_weapon(Weapon &_weapon);
	std::string get_name();

	HumanA(const std::string &_name, Weapon &_weapon);
	~HumanA(void);
};

#endif