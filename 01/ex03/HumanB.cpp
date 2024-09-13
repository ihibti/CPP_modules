#include "HumanB.hpp"

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType();
	std::cout << std::endl;
}

std::string HumanB::get_name()
{
	return (this->name);
}

void HumanB::set_weapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

HumanB::HumanB(Weapon &_weapon, std::string _name) : weapon(&_weapon),
	name(_name){};
HumanB::HumanB(std::string _name) : name(_name), weapon(NULL){};
HumanB::~HumanB()
{
	std::cout << "mort pour " << this->name << std::endl;
}