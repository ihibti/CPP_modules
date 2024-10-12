#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat john("John", 1);  // Highest grade bureaucrat
        Bureaucrat bob("Bob", 50);   // Mid-grade bureaucrat
        Bureaucrat alice("Alice", 150);  // Lowest grade bureaucrat

        std::cout << john << std::endl;
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;

        bob.signForm(shrubbery);
        bob.executeForm(shrubbery); 
        bob.executeForm(shrubbery);
         // Bob should be able to execute this

        // Test RobotomyRequestForm
        RobotomyRequestForm robotomy("robot");
        std::cout << robotomy << std::endl;

        john.signForm(robotomy);  // Only John can sign RobotomyRequestForm
        john.executeForm(robotomy);  // John can execute it as well

        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("Alice");
        std::cout << pardon << std::endl;

        john.signForm(pardon);
        john.executeForm(pardon);  // John can execute the pardon

        // Test failure due to low grade
        alice.signForm(shrubbery);  // Alice cannot sign anything
        alice.executeForm(shrubbery);  // Alice cannot execute anything

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
