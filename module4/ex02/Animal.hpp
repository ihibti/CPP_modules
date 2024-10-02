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

class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();
	virtual void makeSound() const;

  private:
	Brain *brain;
};

class Cat : public Animal
{
  public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();
	virtual void makeSound() const;

  private:
	Brain *brain;
};

#endif
