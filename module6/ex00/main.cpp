#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
    //liberte a l utilisateur 
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
        std::cerr << "u have to use a '.' and not a ',' for a float" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
