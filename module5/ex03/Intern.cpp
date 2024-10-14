#include "Intern.hpp"
#include <iostream>

// Constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern& other) {
    *this = other;
}

// Assignment operator
Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

// Destructor
Intern::~Intern() {}

// Helper functions to create specific forms
AForm* Intern::makeShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardon(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

// makeForm method
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

    const std::string formNames[] = {
        "shrubbery creation", 
        "robotomy request", 
        "presidential pardon"
    };

    FormCreator formCreators[] = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidentialPardon
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    std::cerr << "Error: Form name '" << formName << "' does not exist." << std::endl;
    return 0;
}
