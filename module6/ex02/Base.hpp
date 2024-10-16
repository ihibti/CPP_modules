#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base() {}  // Public virtual destructor
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
class D : public Base {};

#endif
