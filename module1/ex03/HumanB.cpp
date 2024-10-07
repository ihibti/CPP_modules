#include "HumanB.hpp"

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType();
	else
		std::cout << "no weapon no war";
	std::cout << std::endl;
}

std::string HumanB::get_name() const
{
	return (this->name);
}

void HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

HumanB::HumanB(Weapon &_weapon, const std::string &_name)
{
	name = _name;
	this->weapon = &_weapon;
}
HumanB::HumanB(const std::string &_name)
{
	name = _name;
	weapon = NULL;
}
HumanB::~HumanB()
{
	std::cout << "mort pour " << this->name << std::endl;
}