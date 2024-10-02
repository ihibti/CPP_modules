#include "Animal.hpp"

Brain::Brain()
{
	std::cout << "Brain created\n";
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copied\n";
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain assigned\n";
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed\n";
}

Animal::Animal() : type("Unknown")
{
	std::cout << "Unknown Animal created\n";
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

Cat::~Cat()
{
	delete	brain;

	std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}
