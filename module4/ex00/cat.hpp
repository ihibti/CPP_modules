#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

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