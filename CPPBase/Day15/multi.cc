#include <iostream>

using namespace std;

// 基类 A
class A {
public:
    // 虚函数 a()
    virtual void a() {
        cout << "A::a()" << endl;
    }
    
    // 非虚函数 b()
    void b() {
        cout << "A::b()" << endl;
    }
    
    // 虚函数 c()
    virtual void c() {
        cout << "A::c()" << endl;
    }
    
    // 非虚函数 e()
    void e() {
        cout << "A::e()" << endl;
    }
};

// 基类 B
class B {
public:
    // 虚函数 a()
    virtual void a() {
        cout << "B::a()" << endl;
    }
    
    // 非虚函数 c()
    void c() {
        cout << "B::c()" << endl;
    }
    
    // 非虚函数 d()
    void d() {
        cout << "B::d()" << endl;
    }
    
    // 虚函数 f()
    virtual void f() {
        cout << "B::f()" << endl;
    }
};

// 派生类 C，继承自 A 和 B
class C : public A, public B {
public:
    // 覆盖 A 和 B 的虚函数 a()
    virtual void a() {
        cout << "C::a()" << endl;
    }
    
    // 虚函数 b()
    virtual void b() {
        cout << "C::b()" << endl;
    }
    
    // 覆盖 A 和 B 的 c() 函数
    void c() {
        cout << "C::c()" << endl;
    }
    
    // 覆盖 B 的 d() 函数
    void d() {
        cout << "C::d()" << endl;
    }
};

// 测试函数
void test0() {
    // 创建 C 类对象
    C c;
    
    // 直接通过对象 c 调用成员函数
    c.a();  // 调用 C::a()
    c.b();  // 调用 C::b()
    c.c();  // 调用 C::c()
    c.d();  // 调用 C::d()
    c.e();  // 调用 A::e()
    c.f();  // 调用 B::f()
    
    cout << endl;
    
    // 通过 A* 类型指针调用成员函数
    A* pa = &c;
    pa->a();  // 调用 C::a()，因为 a() 是虚函数
    pa->b();  // 调用 A::b()
    pa->c();  // 调用 C::c()，因为 c() 是虚函数
    // pa->d(); // 编译错误，A 类中没有 d()
    pa->e();  // 调用 A::e()
    // pa->f(); // 编译错误，A 类中没有 f()
    
    cout << endl;
    
    // 通过 B* 类型指针调用成员函数
    B* pb = &c;
    pb->a();  // 调用 C::a()，因为 a() 是虚函数
    // pb->b(); // 编译错误，B 类中没有 b()
    pb->c();  // 调用 B::c()
    pb->d();  // 调用 C::d()
    // pb->e(); // 编译错误，B 类中没有 e()
    pb->f();  // 调用 C::f()，因为 f() 是虚函数
    
    cout << endl;
    
    // 通过 C* 类型指针调用成员函数
    C * pc = &c;
    pc->a();  // 调用 C::a()
    pc->b();  // 调用 C::b()
    pc->c();  // 调用 C::c()
    pc->d();  // 调用 C::d()
    pc->e();  // 调用 A::e()
    pc->f();  // 调用 B::f()
}

int main() {
    test0();
    return 0;
}

