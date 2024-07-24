#include <iostream>

using std::endl;
using std::cout;

class Base
{
public:
	Base(int i) 
	{
		b = i;
	}
	// (1) 虚析构函数
	virtual ~Base() {}
    Base():b(0){}
    virtual void Print()
    {	cout << "Base 's Print() called." << endl;}
protected:
	int b;
};

class Derive1 : public Base
{
public:
	// (2) 构造函数
	Derive1():Base(1) {}
	void Print()
	{
		cout << "Derive1's Print() called." << endl;
	}
};

class Derive2 : public Base
{	
public:
	// (3) 构造函数
	Derive2():Base(2) {}
    void Print()
    {
        cout << "Derive2's Print() called. "<< endl;
    }
};

// (4) Base 类指针参数
void fun(Base *obj)
{      
	obj->Print();
}

int main(void)
{ 
	// (5) 创建基类指针并指向派生类对象
    Derive1 d1;
    Derive2 d2;
    fun(&d1);
    fun(&d2);
	return 0;
}

