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
#include <ctime>


class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    double _veqtime;
    double _deqtime;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseArguments(int argc, char** argv);
    void printBefore() const;
    void sortWithVector();
    void sortWithDequeue(); 
    void print_end();

    static void printafter(const std::vector<int>& vec);
    // l une des deux est inutile mais pour tester on sait jamais;
    static void printafter(const std::deque<int>& deq);
    // Accès aux containers pour les étapes suivantes
    // const std::vector<int>& getVector() const;
    // const std::deque<int>& getDeque() const;
};

#endif
