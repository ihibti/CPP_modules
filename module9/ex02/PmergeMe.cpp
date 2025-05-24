#include"PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec),_deq(other._deq){}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
        return *this;
    _vec = other._vec;
    _deq = other._deq;
    return *this;
}

PmergeMe::~PmergeMe() {}

static std::vector<int> jacobsthal_suite(int n)
{
    std::vector<int> j_suite;
    j_suite.push_back(0);
    j_suite.push_back(1);
    while(j_suite.back()< n)
    {
        j_suite.push_back(j_suite[j_suite.size()-1] + (2 * j_suite[j_suite.size() - 2]));
    }  
    return (j_suite);
}

static void buildJacOrder(int start, int len, const std::vector<int>& J, std::vector<int>& order)
{
    if (len <= 0)
        return;
    int k = 0;
    while (k + 1 < static_cast<int>(J.size()) && J[k + 1] < len)
        ++k;
    int pivot = J[k];
    if (pivot >= len)
        return;
    order.push_back(start + pivot);
    buildJacOrder(start, pivot, J, order);
    buildJacOrder(start + pivot + 1, len - pivot - 1, J, order);
}


std::vector<int> generateInsertionOrder(int n)
{
    std::vector<int> J = jacobsthal_suite(n);
    std::vector<int> order;
    buildJacOrder(0, n, J, order);
    return order;
}



void PmergeMe::parseArguments(int ac, char **av)
{
    if (ac < 2)
    {
        throw std::runtime_error("usage : ./PmergeMe \"sequence to sort\"");
    }
    std::ostringstream oss; //receptacle de la concatenation de tous les arguments
    for (int i = 1; i < ac; ++i)
    {
        oss << av[i];
        if (i != ac -1)
            oss << " ";
    }
    std::string input = oss.str();
    std::istringstream iss(input);
    std::string token;
    std::set<int> seen; //set pour savoir instantanement si c est un doublon
    while(iss >> token)
    {
        for(size_t i = 0; i < token.length(); ++i)
        {
            if (!std::isdigit(token[i]))
                throw std::runtime_error("Error: only positive numbers expected");
        }
        int num;
        std::istringstream temp(token);
        if (!(temp >> num))
            throw std::runtime_error("int overflow");
        if (seen.count(num))
            throw (std::runtime_error("Error: no duplicates"));
        seen.insert(num);
        _vec.push_back(num);
        _deq.push_back(num);
    }
    if (_vec.empty() || _deq.empty())
        throw(std::runtime_error("Error: no valid input"));
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";
    for(size_t i = 0; i < _vec.size(); i++)
    {
        std::cout << _vec[i];
        if (i < _vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortWithVector()
{
    std::vector<int> main_chain;
    std::vector<int> pending_chain;
    int vagabond;
    bool has_vagabond = false;
    for (size_t i = 0; i < _vec.size() - 1; i += 2)
    {
        int first = _vec[i];
        int second = _vec[i+1];
        if (first > second)
        {
            main_chain.push_back(first);
            pending_chain.push_back(second);
        }
        else
        {
            main_chain.push_back(second);
            pending_chain.push_back(first);
        }
    }
    if (_vec.size() % 2 == 1)
    {
        vagabond = _vec.back();
        has_vagabond = true;
    }

    std::sort(main_chain.begin(),main_chain.end());

    std::vector<int> insertOrder = generateInsertionOrder(pending_chain.size());
    for (size_t i = 0; i < insertOrder.size(); ++i)
        std::cout << insertOrder[i] << " ";
    std::cout << std::endl;
    for (size_t i = 0; i < insertOrder.size(); ++i) {
        int idx = insertOrder[i];
        int value = pending_chain[idx];

        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    // Étape 6 : insertion du vagabond
    if (has_vagabond) {
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), vagabond);
        main_chain.insert(pos, vagabond);
    }

    // Étape 7 : affichage du résultat
    std::cout << "After: ";
    for (size_t i = 0; i < main_chain.size(); ++i) {
        std::cout << main_chain[i];
        if (i < main_chain.size() -1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

// ____________________________________________________________



// pareil mais adapte a dequeue

void PmergeMe::sortWithDequeue()
{
    std::deque<int> main_chain;
    std::deque<int> pending_chain;
    int straggler = -1;
    bool has_straggler = false;

    // Étape 1 : Formation des paires
    for (size_t i = 0; i + 1 < _deq.size(); i += 2)
    {
        int first = _deq[i];
        int second = _deq[i + 1];
        if (first > second)
        {
            main_chain.push_back(first);
            pending_chain.push_back(second);
        }
        else
        {
            main_chain.push_back(second);
            pending_chain.push_back(first);
        }
    }

    // Étape 2 : Straggler s’il y a un élément impair
    if (_deq.size() % 2 != 0)
    {
        straggler = _deq.back();
        has_straggler = true;
    }

    // Étape 3 : tri de main_chain
    std::sort(main_chain.begin(), main_chain.end());

    // Étape 4 : génération de l’ordre d’insertion
    std::vector<int> insertionOrder = generateInsertionOrder(pending_chain.size());

    // Étape 5 : insertion dans main_chain
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int idx = insertionOrder[i];
        int value = pending_chain[idx];

        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    // Étape 6 : insertion du straggler
    if (has_straggler)
    {
        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    // Étape 7 : affichage
    std::cout << "After (deque): ";
    for (size_t i = 0; i < main_chain.size(); ++i)
    {
        std::cout << main_chain[i];
        if (i < main_chain.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

