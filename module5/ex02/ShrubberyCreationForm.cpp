#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

#include "ShrubberyCreationForm.hpp"
#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);

    std::ofstream file((getName() + "_shrubbery").c_str());
    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    file << "ASCII trees go here..." << std::endl;
    file.close();
}

