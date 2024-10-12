#include "new_replace.hpp"

bool	new_file(std::string &infile, std::string &outfile, std::string &ori,
		std::string &replacement)
{
	if (infile.empty())
		return (std::cerr << "error filename is empty\n", false);
	std::ifstream lecture(infile.c_str());
	if (!lecture.is_open())
	{
		std::cerr << "erreur opening file\n";
		return (false);
	}
	std::string line;
	std::ofstream writing(outfile.c_str());
	if (!writing.is_open())
	{
		lecture.close();
		std::cerr << "erreur writing file\n";
		return (false);
	}
	while (std::getline(lecture, line))
	{
		writing << new_replaced(line, ori, replacement) << "\n";
	}
	lecture.close();
	writing.close();
	return (true);
}

std::string new_replaced(std::string &line, std::string &ori,
	std::string &replacement)
{
	std::size_t pos;
	std::string ret;
	if (ori.empty())
		return (line);

	ret = line;
	pos = line.find(ori, 0);
	while (pos != std::string::npos)
	{
		ret = ret.substr(0, pos) + replacement + ret.substr(pos + ori.length(),
				std::string::npos);
		pos = ret.find(ori, 0);
	}
	return (ret);
}