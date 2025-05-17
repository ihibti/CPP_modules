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
			this->ideas[i] = std::string( other.ideas[i]);
		}
	}
	std::cout << "Brain assigned\n";
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed\n";
}
void Brain::setIdeas(const std::string &idea, int index)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdeas(int index) const
{
    if (index >= 0 && index < 100)
        return this->ideas[index];
    return "";
}


