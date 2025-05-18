#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


void checkDeepCopy() {
        Dog originalDog;
        originalDog.getBrain()->setIdeas("Chase the cat",0);
        Dog copiedDog = originalDog; 

        copiedDog.getBrain()->setIdeas("Eat the bone",0);
        if (originalDog.getBrain()->getIdeas(0) == "Chase the cat" &&
            copiedDog.getBrain()->getIdeas(0) == "Eat the bone") {
            std::cout << "great success." << std::endl;
        } else {
            std::cout << "u cant even copy successfully. u re a failure" << std::endl;
        }
    }

int main() {
    Animal* animals[10];

    for (int i = 0; i < 5; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 10; ++i) {
        animals[i]->makeSound();
    } 
    checkDeepCopy();
    // retirer le commentaire pour tester la copie profonde
    // retirer aussi le commentaire de la fonction checkDeepCopy

    for (int i = 0; i < 10; ++i) {
        delete animals[i];
    }

    return 0;
}

