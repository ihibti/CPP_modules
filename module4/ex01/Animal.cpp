#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout << "Unknown Animal created\n";
}

void Animal::makeSound() const
{
	std::cout << "no type no noiseds\n";
}

Animal::Animal(const std::string &type) : type(type)
{
	std::cout << "Animal of type " << type << " created\n";
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copied\n";
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Animal assigned\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal of type " << type << " has been destroyed\n";
}

std::string Animal::getType() const
{
	return (type);
}




