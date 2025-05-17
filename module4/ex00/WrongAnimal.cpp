#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong animal")
{
    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{
    std::cout << "WrongAnimal created" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "WrongAnimal copied" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "WrongAnimal assigned" << std::endl;
    return (*this);
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destroyed" << std::endl;
}
void WrongAnimal::makeSound() const
{
    std::cout << "wrong and no type ! NO SOUND !" << std::endl;
}
std::string WrongAnimal::getType() const
{
    return this->type;
}
