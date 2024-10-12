#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int	main(void)
{
    Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}