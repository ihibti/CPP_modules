#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat john("John", 3);
		Bureaucrat bob("Bob", 50);
		Form formA("FormA", 5, 30);
		Form formB("FormB", 40, 20);
		john.signForm(formA);
		john.signForm(formB);
		bob.signForm(formA);
		bob.signForm(formB);
        bob.signForm(formA);
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
