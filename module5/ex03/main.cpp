#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat john("John", 5);
    
    // Create a robotomy request form
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        john.signForm(*rrf);
        john.executeForm(*rrf);
    }

    // Create a shrubbery creation form
    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    if (shrub) {
        john.signForm(*shrub);
        john.executeForm(*shrub);
    }

    // Try to create a non-existent form
    AForm* invalid = someRandomIntern.makeForm("invalid form", "target");
    if (invalid) {
        john.signForm(*invalid);
        john.executeForm(*invalid);
    }

    // Clean up dynamically allocated memory
    delete rrf;
    delete shrub;
    delete invalid;

    return 0;
}
