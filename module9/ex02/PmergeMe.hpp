#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <set>
#include <cctype>
#include <limits>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseArguments(int argc, char** argv);
    void printBefore() const;
    void sortWithVector();
    // void sortWithDequeue();    

    // Accès aux containers pour les étapes suivantes
    // const std::vector<int>& getVector() const;
    // const std::deque<int>& getDeque() const;
};

#endif
