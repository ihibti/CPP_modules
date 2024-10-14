#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target,
	145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);

	// Open file in append mode
	std::ofstream file((getName() + "_shrubbery").c_str(), std::ios::app);
	if (!file)
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return ;
	}

	// Append the ASCII tree
	file << "       /\\\n";
	file << "      /  \\\n";
	file << "     /    \\\n";
	file << "    /______\\\n";
	file << "      ||||\n";
	file << "      ||||\n";
	file << "\n"; // Add a new line to separate the trees
	file.close();
}
