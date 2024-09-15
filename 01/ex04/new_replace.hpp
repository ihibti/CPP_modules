#ifndef NEWREPLACE_HPP
# define NEWREPLACE_HPP
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <string>

bool	new_file(std::string &infile, std::string &outfile, std::string &ori,
			std::string &replacement);
std::string new_replaced(std::string &line, std::string &ori,
	std::string &replacement);

#endif