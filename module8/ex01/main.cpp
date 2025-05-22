#include <iostream>
#include <vector>
#include <cstdlib>      
#include <ctime>        
#include "span.hpp"
#include "span.tpp"

int main()
{
    //  Test basique
    Span s1(5);

    try {
        s1.addNumber(6);
        s1.addNumber(3);
        s1.addNumber(17);
        s1.addNumber(9);
        s1.addNumber(11);

        std::cout << "Shortest span: " << s1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << s1.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    //  Test plage d’itérateurs + exception si trop de valeurs
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i * 10);

    Span s2(10);
    try {
        s2.addNumber(v.begin(), v.end());
        std::cout << "Span (10 éléments): OK" << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Range insert failed: " << e.what() << std::endl;
    }

    //  Test avec 10 000 éléments aléatoires
    Span big(10000);
    srand(time(NULL));
    for (int i = 0; i < 10000; ++i)
        big.addNumber(rand());

    try {
        std::cout << "Big span (10000 values) - shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Big span (10000 values) - longest: " << big.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error on big span: " << e.what() << std::endl;
    }

    return 0;
}
