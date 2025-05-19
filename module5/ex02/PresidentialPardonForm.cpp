#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    try {
        checkExecution(executor);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
