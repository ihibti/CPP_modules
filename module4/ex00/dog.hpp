#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

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

#endif