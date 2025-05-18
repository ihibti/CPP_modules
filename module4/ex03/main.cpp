#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int	main(void)
{

    // Test de la classe MateriaSource

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    // test du cas ou on essaye d'apprendre une materia alors qu'on en a deja 4
    Ice icetemp;
    src->learnMateria(&icetemp);


    // Test 2: utiliser et equiper des materias
    ICharacter* alice = new Character("Alice");
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    alice->equip(ice);
    alice->equip(cure);

    // Test 3: equiper plus de 4 Materias
    alice->equip(src->createMateria("ice"));
    alice->equip(src->createMateria("cure"));
    alice->equip(&icetemp); // Should not equip

    // Test 4: utiliser les  Materias
    ICharacter* bob = new Character("Bob");
    for (int i = 0; i < 4; ++i)
        alice->use(i, *bob);

    // Test 5: desequiper et essayer d utiliser quand meme
    alice->unequip(1);
    alice->use(1, *bob); // Should do nothing

    // Test 6: copie profondee
    Character* clone = new Character(*(Character*)alice);
    clone->use(0, *bob);

    // Test 7: operateur d assignation
    Character assign("Assign");
    assign = *(Character*)alice;
    assign.use(0, *bob);

    delete clone;
    delete bob;
    delete alice;
    delete src;

    /*

    utilisation de plusieurs new non necessaires mais 
    interessant pour mieux comprendre le fonctionnement de la classe

    test du sujet
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
    */
}