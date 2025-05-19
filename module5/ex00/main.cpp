#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat b1("efficient", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
        std::cout << "incrementation de 1 devrait etre impossible" << std::endl;
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
        std::cout << "decrementation de 1 devrait etre impossible" << std::endl;
		b2.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    try
	{
        std::cout << "creation d un bureaucrate trop low" << std::endl;
		Bureaucrat b3("ismael", -9);
        std::cout << "cette ligne ne doit pas apparaitre" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    try
	{
        std::cout << "creation d un bureaucrate trop eleve" << std::endl;
		Bureaucrat b4("ismael", 160);
        std::cout << "cette ligne ne doit pas apparaitre" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
