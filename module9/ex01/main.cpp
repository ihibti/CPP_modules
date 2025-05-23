#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    // Vérifie qu'un seul argument est passé
    if (argc != 2)
    {
        std::cerr << "usage : ./rpn \"expression\"" << std::endl;
        return 1;
    }

    try
    {
        // Création d'une instance de RPN
        RPN rpn;

        // Évalue l'expression passée en argument
        int result = rpn.evaluate(argv[1]);

        // Affiche le résultat
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        // Affiche toute erreur déclenchée dans RPN
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
