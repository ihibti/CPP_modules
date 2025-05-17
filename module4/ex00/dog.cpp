#include "dog.hpp"

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
