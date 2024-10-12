#include "RobotomyRequestForm.hpp"
#include <cstdlib>  // For rand()

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
    checkExecution(executor);
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << getName() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed for " << getName() << "." << std::endl;
}
