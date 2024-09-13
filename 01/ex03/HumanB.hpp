#include "Weapon.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
	void attack();
	void set_weapon(Weapon &weapon);
	std::string get_name();

	HumanB(Weapon &_weapon, std::string name);
	HumanB(std::string name);
	~HumanB(void);
};