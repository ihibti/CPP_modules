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

    // tentative de creation d un formulaire non existant
    AForm* invalid = someRandomIntern.makeForm("invalid form", "target");
    if (invalid) {
        john.signForm(*invalid);
        john.executeForm(*invalid);
    }

    delete rrf;
    delete shrub;
    delete invalid;

    return 0;
}
