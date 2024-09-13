#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->_weapon->getType();
	std::cout << std::endl;
}

std::string HumanA::get_name()
{
	return (this->name);
}

void HumanA::set_weapon(Weapon &_weapon)
{
	this->_weapon = _weapon;
}

HumanA::HumanA(std::string _name, Weapon *weapon) : _weapon(_weapon),
	name(_name){};
HumanA::~HumanA()
{
	std::cout << "mort pour " << this->name << std::endl;
}
