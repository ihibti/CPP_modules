#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 3);
        Bureaucrat bob("Bob", 50);

        Form formA("FormA", 5, 30);  // Needs grade 5 to sign
        Form formB("FormB", 40, 20); // Needs grade 40 to sign

        john.signForm(formA);  // John has grade 3, can sign formA
        john.signForm(formB);  // John has grade 3, can sign formB

        bob.signForm(formA);  // Bob has grade 50, can't sign formA
        bob.signForm(formB);  // Bob has grade 50, can sign formB

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
