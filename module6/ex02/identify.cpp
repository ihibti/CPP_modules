#include "identify.hpp"

// Function to randomly instantiate A, B, or C
Base	*generate(void)
{
	std::srand(std::time(0));          // Seed random number generator
	int randomValue = std::rand() % 3; // Random number between 0 and 2
	if (randomValue == 0)
		return (new A());
	else if (randomValue == 1)
		return (new B());
	else
		return (new C());
}

// Function to identify type via pointer
void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

// Function to identify type via reference
void	identify(Base &p)
{
	// Try to convert the reference to a pointer and then use dynamic_cast
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}
