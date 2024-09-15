#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << weapon.getType();
	std::cout << std::endl;
}

std::string HumanA::get_name()
{
	return (this->name);
}

void HumanA::set_weapon(Weapon &_weapon)
{
	this->weapon = _weapon;
}

HumanA::HumanA(const std::string &_name, Weapon &_weapon) : name(_name),
	weapon(_weapon){};
HumanA::~HumanA()
{
	std::cout << "mort pour " << this->name << std::endl;
}
