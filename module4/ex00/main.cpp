#include "Animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	// const Animal	*i = new Cat();
    /*
    supprimer le commentaire et la ligne 9 
    pour tester le wrong animl
    */
    const WrongAnimal *i = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
    delete i;
    delete j;
    delete meta;
	return (0);
}
