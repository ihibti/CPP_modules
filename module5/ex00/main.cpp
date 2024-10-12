#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat b1("efficient", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("lazy", 149);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;
		b2.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    try
	{
		Bureaucrat b3("ismael", -9);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;
		b3.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
