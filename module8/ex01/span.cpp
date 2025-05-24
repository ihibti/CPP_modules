#include "span.hpp"

Span::Span(unsigned int size) : _maxSize(size){}

Span::Span():_maxSize(10){}

Span& Span::operator=(const Span& other)
{
    if (this == &other)
        return(*this);
    _maxSize = other._maxSize;
    _storage = other._storage;
    return(*this);
}


Span::Span(const Span &other):_maxSize(other._maxSize)
{
    _storage = other._storage;
}

Span::~Span(){};

void Span::addNumber(int number)
{
    if (_storage.size() == _maxSize)
        throw (std::out_of_range("Span is full"));
    _storage.push_back(number);
}

int Span::longestSpan() const
{
    if (_storage.size() < 2)
        throw(std::out_of_range("less than 2 elements"));
    int smallest = _storage[0];
    int biggest = _storage[0];
    for (unsigned long i = 0;i < _storage.size();i++)
    {
        if (_storage[i] > biggest)
            biggest = _storage[i];
        
        if (_storage[i] < smallest)
            smallest = _storage[i];    
    }
    return(biggest - smallest);
}

int Span::shortestSpan () const
{
    if (_storage.size() < 2)
        throw(std::out_of_range("less than 2 elements"));
    std::vector<int> sorted (_storage);
    std::sort(sorted.begin(),sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (unsigned long i = 0;i < sorted.size() - 1;i++ )
    {
        if (sorted[i+1] - sorted[i] < shortest)
            shortest = sorted[i+1] - sorted[i];
    }
    return (shortest);
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_storage.size() + std::distance(begin,end) > _maxSize)
        throw std::out_of_range("not ebough space in span");
    for (std::vector<int>::iterator current = begin;current != end;++current)
        addNumber(*current);
}





