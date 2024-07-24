#include <iostream>

class A {
public:
    ~A() { std::cout << "A destructor\n"; }
};

class B {
public:
    ~B() { std::cout << "B destructor\n"; }
};

class C {
public:
    ~C() { std::cout << "C destructor\n"; }
};

class D {
public:
    ~D() { std::cout << "D destructor\n"; }
};

C c;

int main()
{
    A *pa = new A();
    B b;
    static D d;
    delete pa;
    return 0;
}

