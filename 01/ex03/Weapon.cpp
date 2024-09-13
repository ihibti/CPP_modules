#include "Weapon.hpp"

std::string Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(std::string _newtype)
{
	this->type = _newtype;
}

Weapon::Weapon(std::string _type) : type(_type){};

Weapon::~Weapon()
{
	std::cout << "destruction de l arme " << this->type << std::endl;
}
