#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int num =1;
    int *p=&num;
    int &ref=num;
    ref+=10;
    cout<<num<<endl;
    cout<<ref<<endl;
    cout<<&num<<endl;
    cout<<&ref<<endl;
    cout<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;

    cout<<endl;
    int num2=12;
    ref=num2;//赋值
    cout<<&num<<endl;
    cout<<&ref<<endl;
    cout<<&num2<<endl;
    cout<<num<<endl;

    //引用不能单独存在，要初始化
    
}

void func(int &x)
{
    cout<<x<<endl;
}

void test1(){
    int a=10;
    func(a);
}


int main()
{
    test0();
    return 0;
}

