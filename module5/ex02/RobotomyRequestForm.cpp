#include "RobotomyRequestForm.hpp"
#include <cstdlib>  // For rand()


RobotomyRequestForm::RobotomyRequestForm()
    : AForm("default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    try {
        checkExecution(executor);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << getName() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed for " << getName() << "." << std::endl;
}
