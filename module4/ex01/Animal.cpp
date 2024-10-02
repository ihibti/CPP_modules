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

Dog::Dog() : Animal("dog")
{
	std::cout << "Dog created\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copied\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Dog Assigned";
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog has been destroyed\n";
}

void Dog::makeSound() const
{
	std::cout << "Bark !\n";
}

Cat::Cat() : Animal("cat")
{
	std::cout << "Cat created\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copied\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Cat Assigned";
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat has been destroyed\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow !\n";
}