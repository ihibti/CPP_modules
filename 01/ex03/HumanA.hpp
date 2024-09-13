#include "Weapon.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

class HumanA
{
  private:
	std::string name;
	Weapon *_weapon;

  public:
	void attack();
	void set_weapon(Weapon *_weapon);
	std::string get_name();

	HumanA(std::string _name, Weapon *weapon);
	~HumanA(void);
};