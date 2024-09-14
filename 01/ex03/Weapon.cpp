#include "Weapon.hpp"

std::string Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(const std::string &_newtype)
{
	this->type = _newtype;
}

Weapon::Weapon(const std::string &_type) : type(_type){};

Weapon::~Weapon()
{
	std::cout << "destruction de l arme " << this->type << std::endl;
}
