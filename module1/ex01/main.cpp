#include "Zombie.hpp"

int	main(void)
{
	Zombie alex("alexandre");
	Zombie *pierre;
	Zombie *horde;

	horde = zombieHorde(10, "loubard");
	pierre = newZombie("pierre");
	pierre->announce();
	alex.announce();
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	delete pierre;
}