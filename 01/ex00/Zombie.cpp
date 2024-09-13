#include "Zombie.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
void Zombie::set_name(std::string name_n)
{
	this->name = name_n;
}
std::string Zombie::get_name(void)
{
	return (this->name);
}
Zombie::Zombie(std::string _name) : name(_name){};
Zombie::Zombie(void) : name("inconu"){};
Zombie::~Zombie(void)
{
	std::cout << get_name() << " est mort comme le zombie qu il est\n";
}
