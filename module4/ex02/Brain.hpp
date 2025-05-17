#include "Animal.hpp"

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
  public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
    void setIdeas(const std::string &idea, int index);
    std::string getIdeas(int index) const;
	std::string ideas[100];
};

#endif
