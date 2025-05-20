#include "identify.hpp"

// generer un objet d une classe aleatoire
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

// Fonction pour identifier avec un pointeur
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

// pareil mais avec une reference
void	identify(Base &p)
{
    try 
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception &e) {}
    try 
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &e) {
    }
    try 
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception &e) {
    }
    std::cout << "Unknown type" << std::endl;
}
