#include "Harl.hpp"
#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char **av)
{
	Harl harrl;
	for (int i = 1; i < argc; i++)
	{
		harrl.complain(av[i]);
	}
}