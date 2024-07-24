#include<iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual void print(){
        cout<<"Base::print()"<<endl;
    }
    virtual void display(){
        cout<<"Base::display()"<<endl;
    }
    virtual void show(){
        cout<<"Base::show()"<<endl;
    }


private:
    long _base=10;
};

class Derived
:public Base
{
public:
    virtual void print()
    {
        cout<<"Derived::print()"<<endl;
    }

    virtual void display()
    {
        cout<<"Derived::display()"<<endl;
    }

    virtual void show()
    {
        cout<<"Derived::show()"<<endl;
    }

private:
    long _derived=100;

};

void test0()
{
    Derived d;
    long *pDerived =reinterpret_cast<long*>(&d);
    cout<<pDerived[0]<<endl;
    cout<<pDerived[1]<<endl;
    cout<<pDerived[2]<<endl;

    cout<<endl;
    long*pVtable=reinterpret_cast<long*>(pDerived[0]);
    cout<<pVtable[0]<<endl;
    cout<<pVtable[1]<<endl;
    cout<<pVtable[2]<<endl;

    cout<<endl;
    typedef void(*Function)();
    Function f=(Function)(pVtable[0]);
    f();
    f=(Function)(pVtable[1]);
    f();
    f=(Function)(pVtable[2]);
    f();
}

int main()
{
    test0();
    return 0;
}
