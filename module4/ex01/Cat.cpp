#include"Cat.hpp"

Cat::Cat() : Animal("cat"), brain(new Brain())
{
	std::cout << "Cat created\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copied\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	std::cout << "Cat assigned\n";
	return (*this);
}

Brain *Cat::getBrain() const
{
    return brain;
}

Cat::~Cat()
{
	delete	brain;

	std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}