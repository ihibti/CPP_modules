#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat john("John", 1);  //  bureaucrate capable de tout faire
        Bureaucrat bob("Bob", 50);   // bureaucrate moyen
        Bureaucrat alice("Alice", 150);  // bureaucrate desastreux

        std::cout << john << std::endl;
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;

        // test du shrubbery sans signature
        john.executeForm(shrubbery);  // John ne peut pas executer
        bob.signForm(shrubbery);
        //maintenant bob peut executer
        bob.executeForm(shrubbery); 
        bob.executeForm(shrubbery);
         // Bob should be able to execute this

        // Test RobotomyRequestForm
        RobotomyRequestForm robotomy("robot");
        std::cout << robotomy << std::endl;
    
        john.signForm(robotomy);  
        john.executeForm(robotomy);  
        john.executeForm(robotomy);  
        john.executeForm(robotomy);  // plusieurs tests pour voir si la reussite est aleatoire


        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("Alice");
        std::cout << pardon << std::endl;

        john.signForm(pardon);
        john.executeForm(pardon);  

        alice.signForm(shrubbery);  
        alice.executeForm(shrubbery);  // Alice ne peut rien faire

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
