#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"
# include <iostream>
# include <string>

class Animal
{
  public:
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string getType() const;

  protected:
	std::string type;
};


#endif
