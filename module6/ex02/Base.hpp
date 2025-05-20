#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base() {}  // destructeur qui semnle inutile a mettre en virtuel
    // mais qui sert a l identtification en temps reel
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
// classe inutile mais sert pour la correction
class D : public Base {};

#endif
