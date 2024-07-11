#include <iostream>
using std::cout;
using std::endl;

template<class T=int,int kCapcity=10>
class Stack
{
public:
    Stack()
    :_top(-1)
     ,_data(new T[kCapcity]())
    {
        cout<<"Stack()"<<endl;
    }

    ~Stack()
    {
        if(_data){
            delete []_data;
            _data=nullptr;
        }
        cout<<"~Stack()"<<endl;
    }

    bool empty() const
    {
        return _top==-1;
    }

    bool full() const
    {
        return _top==kCapcity-1;
    }

    void push(const T&t)
    {
        if(!full())
        {
            _data[++_top]=t;
        }
        else
        {
            cout<<"栈已满"<<endl;
        }
    }

    void pop()
    {
        if(!empty())
        {
            --_top;
        }
        else
        {
            cout<<"栈已空"<<endl;
        }
    }

    T top();
private:
    int _top;
    T*_data;
};

template<class T,int kCapcity>
T Stack<T,kCapcity>::top()
{
    if(!empty())
    {
        return _data[_top];
    }
    else
    {
        throw"栈已空";
    }
}

void test0()
{
    Stack<int,20>s1;
    Stack<double>s2;
    Stack<>s3;
}

int main()
{
    test0();
    return 0;
}

