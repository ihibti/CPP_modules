#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout << "unknown Animal created\n";
};
std::string Animal::getType() const
{
	return (type);
}
Animal::Animal(const std::string &p_type) : type(p_type)
{
	std::cout << "animal of type: " << type << " created\n";
};
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "animal assigned\n";
	return (*this);
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "animal copied\n";
};
Animal::~Animal()
{
	std::cout << "Animal of type  " << type << " has been destroyed\n";
}

void Animal::makeSound() const
{
	if (type != "Unknown")
		std::cout << "Animal makes the sound of a " << type << std::endl;
	else
		std::cout << "No type no noises!\n";
}

