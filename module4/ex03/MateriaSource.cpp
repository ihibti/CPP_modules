#include "MateriaSource.hpp"

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