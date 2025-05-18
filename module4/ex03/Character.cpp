#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = 0;
    }
}

Character::Character(Character const & other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = 0;
        }
    }
}

Character& Character::operator=(Character const & other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) {
                delete inventory[i];
            }
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            } else {
                inventory[i] = 0;
            }
        }
        name = other.name;
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        if (inventory[idx]) {
            delete inventory[idx];
        }
        inventory[idx] = 0;
    }
    else {
        std::cout << "Invalid index for unequip: " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
    else {
        std::cout << "No materia equipped at index " << idx << std::endl;
    }
}