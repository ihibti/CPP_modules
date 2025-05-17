#include "Dog.hpp"

Dog::Dog() : Animal("dog"), brain(new Brain())
{
	std::cout << "Dog created\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog copied\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	std::cout << "Dog assigned\n";
	return (*this);
}

Dog::~Dog()
{
	delete	brain;

	std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const
{
	std::cout << "Bark!\n";
}

Brain *Dog::getBrain() const
{
    return brain;
}
void Dog::setBrain(Brain *newBrain)
{
    if (brain != nullptr)
        delete brain;
    brain = newBrain;
}