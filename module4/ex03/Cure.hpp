#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
public:
Cure(const Cure& other);
Cure& operator=(const Cure& other);
    Cure();
    virtual ~Cure();
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif