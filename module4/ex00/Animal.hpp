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

class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual void makeSound() const;
	virtual ~Dog();

  private:
};

class Cat : public Animal
{
  public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual void makeSound() const;
	virtual ~Cat();

  private:
};

#endif