#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>   // pour std::cerr, std::endl
#include <fstream>    // pour std::ifstream
#include <string>
#include<sstream>
#include<map>


bool isValidDate(const std::string &date);
std::map<std::string, float> parseDatabase(std::ifstream &file);



#endif