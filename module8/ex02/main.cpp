#include <iostream>
#include <list>
#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
    std::cout << "--- Test avec MutantStack ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Iterating over MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack); // Vérifie la compatibilité avec std::stack

    std::cout << "\n--- Test équivalent avec std::list ---" << std::endl;
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);

    std::cout << "Back: " << lstack.back() << std::endl;
    lstack.pop_back();
    std::cout << "Size after pop: " << lstack.size() << std::endl;

    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);

    std::list<int>::iterator lit = lstack.begin();
    std::list<int>::iterator lite = lstack.end();

    ++lit;
    --lit;

    std::cout << "Iterating over std::list:" << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}
