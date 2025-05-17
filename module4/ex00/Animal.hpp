#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iomanip>
# include <iostream>
# include <stdint.h>
# include <string>

class Animal
{
  public:
	Animal();
	Animal(const std::string &p_type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();
	std::string getType() const;
	virtual void makeSound() const;

  protected:
	std::string type;
};





#endif