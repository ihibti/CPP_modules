#include "Zombie.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

void	randomChump(std::string name)
{
	Zombie random(name);
	random.announce();
}