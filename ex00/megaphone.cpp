#include <iostream>
#include <string>

char	*capitalize(char *string);

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		std::string str("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		std::cout << str << std::endl;
		return (0);
	}
	while (av[i])
	{
		std::cout << capitalize(av[i]);
		i++;
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}

char	*capitalize(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] <= 'z' && string[i] >= 'a')
			string[i] -= 32;
		i++;
	}
	return (string);
}
