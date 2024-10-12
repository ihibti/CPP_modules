#include "new_replace.hpp"
#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string inputFilename = argv[1];
	std::string outputFilename = inputFilename + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (new_file(inputFilename, outputFilename, s1, s2))
	{
		std::cout << outputFilename << " created with success" << std::endl;
		return (0);
	}
	else
	{
		std::cerr << "failure" << std::endl;
		return (1);
	}
}