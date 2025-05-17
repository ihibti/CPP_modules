#include"cat.hpp"

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