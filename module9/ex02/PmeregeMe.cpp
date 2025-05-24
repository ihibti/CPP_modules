#include"PmeregeMe.hpp"

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

void PmergeMe::parseArguments(int ac, char **av)
{
    if (ac < 2)
    {
        throw std::runtime_error("usage : ./PmergeMe \"sequence to sort\"");
    }
    std::ostringstream oss; //receptacle de la concatenation de tous les arguments
    for (int i = 1;i < ac; ++i)
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
        for(size_t i = 0; i < token.length();++i)
        {
            if (!std::isdigit(token[i]))
                throw std::runtime_error("Error: only positive numbers expected");
        }
        long num;
        std::istringstream temp(token);
        if ((temp >> num))
            throw std::runtime_error("int overflow");
        if (num > std::numeric_limits<int>::max())
            throw(std::runtime_error("Error: int overflow"));
        if (seen.count(num))
            throw (std::runtime_error("Error: no duplicates"));
        seen.insert(num);
        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
    }
    if (_vec.empty() || _deq.empty())
        throw(std::runtime_error("Error: no valid input"));


}
