#include"WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("wrong cat")
{
    std::cout << "WrongCat created" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copied" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "WrongCat assigned" << std::endl;
    return (*this);
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed" << std::endl;
}       
void WrongCat::makeSound() const
{
    std::cout << "benjamin PAVARRRRRRDDDDDD" << std::endl;
}

