#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

int	main(void)
{
	std::string var;
	std::string *stringPTR;
	var = "HI THIS IS BRAIN";
	std::string &stringREF = var;
	stringPTR = &var;
	std::cout << &var << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << var << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
