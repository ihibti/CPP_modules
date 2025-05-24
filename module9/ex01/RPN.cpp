#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

RPN::RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) { 
    if (this != &other)
        _stack = other._stack;
    return *this;
    }
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperator(const std::string &op, int a, int b) const
{
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator");
}

// int RPN::evaluate(const std::string &expression)
// {
//     std::istringstream iss(expression);
//     std::string token;

//     while (iss >> token)
//     {
//         if (token.length() == 1 && std::isdigit(token[0]))
//         {
//             _stack.push(token[0] - '0');
//         }
//         else if (isOperator(token))
//         {
//             if (_stack.size() < 2)
//                 throw std::runtime_error("Error: not enough operands");

//             int b = _stack.top();
//             _stack.pop();
//             int a = _stack.top();
//             _stack.pop();

//             int result = applyOperator(token, a, b);
//             _stack.push(result);
//         }
//         else
//         {
//             throw std::runtime_error("Error: invalid token");
//         }
//     }

//     if (_stack.size() != 1)
//         throw std::runtime_error("Error: invalid expression");

//     return _stack.top();
// }


// int RPN::evaluate(const std::string &expression)
// {
//     std::istringstream iss(expression);
//     std::string token;

//     if (iss.fail() || !iss.eof())
//     {
//         std::cerr << "erreur !" << std::endl ;
//         throw (std::exception());
//     }
//     while(iss >> token)
//     {
//         if (this->isOperator(token) && this->_stack.size() < 2)
//         {
//             std::cerr << "not enough operands" << std::endl;
//             throw std::exception();
//         }
//         if (std::isdigit(token[0]))
        
//     }

// }
