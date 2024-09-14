#include "new_replace.hpp"
#include <fstream>
#include <iostream>
#include <string>

// Fonction pour ouvrir un fichier en lecture
bool	openInputFile(const std::string &filename, std::ifstream &file)
{
	file.open(filename.c_str());
	return (file.is_open());
}

// Fonction pour ouvrir un fichier en écriture
bool	openOutputFile(const std::string &filename, std::ofstream &file)
{
	file.open(filename.c_str());
	return (file.is_open());
}

// Fonction pour remplacer une occurrence dans une chaîne
void	replaceOccurrence(std::string &line, const std::string &s1,
		const std::string &s2, std::string::size_type &pos)
{
	line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
	pos += s2.length();
}

// Fonction pour traiter une ligne
void	processLine(std::string &line, const std::string &s1,
		const std::string &s2)
{
	std::string::size_type pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		replaceOccurrence(line, s1, s2, pos);
	}
}

// Fonction principale de remplacement
bool	replaceInFile(const std::string &inputFilename,
		const std::string &outputFilename, const std::string &s1,
		const std::string &s2)
{
	std::ifstream inFile;
	std::ofstream outFile;
	if (!openInputFile(inputFilename, inFile))
	{
		std::cerr << "Erreur : Impossible d'ouvrir le fichier d'entrée." << std::endl;
		return (false);
	}
	if (!openOutputFile(outputFilename, outFile))
	{
		std::cerr << "Erreur : Impossible de créer le fichier de sortie." << std::endl;
		inFile.close();
		return (false);
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		processLine(line, s1, s2);
		outFile << line << '\n';
	}
	inFile.close();
	outFile.close();
	return (true);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string inputFilename = argv[1];
	std::string outputFilename = inputFilename + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (replaceInFile(inputFilename, outputFilename, s1, s2))
	{
		std::cout << "Opération terminée avec succès." << std::endl;
		return (0);
	}
	else
	{
		std::cerr << "L'opération a échoué." << std::endl;
		return (1);
	}
}