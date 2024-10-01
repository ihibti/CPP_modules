#include"ClapTrap.hpp"

int main()
{
    ClapTrap jimmy("jimmy");
    ClapTrap brandon("brandon");

    jimmy.attack("brandon");
    brandon.takeDamage(jimmy.get_ad());
}