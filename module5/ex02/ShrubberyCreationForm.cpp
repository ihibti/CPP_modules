#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137)
{
}

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
    try {
        checkExecution(executor);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return ;
    }

	// Ouvre fichier en mode "append"
	std::ofstream file((getName() + "_shrubbery").c_str(), std::ios::app);
	if (!file)
	{
		std::cerr << "Error: Could not open file." << std::endl;
		return ;
	}

    // pas de jugement sur l arbre
	file << "       /\\\n";
	file << "      /  \\\n";
	file << "     /    \\\n";
	file << "    /______\\\n";
	file << "      ||||\n";
	file << "      ||||\n";
	file << "\n"; 
	file.close();
}
