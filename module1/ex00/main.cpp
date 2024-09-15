#include "Zombie.hpp"

int	main(void)
{
	Zombie alex("alexandre");
	Zombie *pierre;

	pierre = newZombie("pierre");
	randomChump("le clochard");
	pierre->announce();
	alex.announce();
	delete pierre;
}