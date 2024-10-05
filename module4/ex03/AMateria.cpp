#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    (void)target; 
}

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

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
        inventory[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        materiaSlots[i] = 0;
    }
}

MateriaSource::MateriaSource(MateriaSource const & other) {
    for (int i = 0; i < 4; i++) {
        if (other.materiaSlots[i]) {
            materiaSlots[i] = other.materiaSlots[i]->clone();
        } else {
            materiaSlots[i] = 0;
        }
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (materiaSlots[i]) {
                delete materiaSlots[i];
            }
            if (other.materiaSlots[i]) {
                materiaSlots[i] = other.materiaSlots[i]->clone();
            } else {
                materiaSlots[i] = 0;
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (materiaSlots[i]) {
            delete materiaSlots[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!materiaSlots[i]) {
            materiaSlots[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (materiaSlots[i] && materiaSlots[i]->getType() == type) {
            return materiaSlots[i]->clone();
        }
    }
    return 0;
}
