#include "Brain.hpp"

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


