#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>        // pour stocker les entiers
#include <algorithm>     // pour std::sort(), std::min_element(), etc.
#include <stdexcept>     // pour std::exception, std::out_of_range

class Span {
public:
    Span();
    Span(unsigned int size);
    
    Span(const Span& other);
    
    Span& operator=(const Span& other);
    void addNumber(int number);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;
    ~Span();

private:
    unsigned int _maxSize;
    std::vector<int> _storage;
};


#endif