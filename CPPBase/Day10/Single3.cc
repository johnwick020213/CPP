#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton*getInstance()
    {
        if(nullptr==_pInstance)
        {
            atexit(destory);
            _pInstance=new Singleton(1,2);
        }
        return _pInstance;
    }

    void init(int x,int y)
    {
        _ix=x;
        _iy=y;
    }

    void print() const
    {
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }

private:
    static void destory()
    {
        if(_pInstance)
        {
            delete _pInstance;
            _pInstance=nullptr;
            cout<<">>delete heap"<<endl;
        }
    }

    Singleton(const Singleton &rhs)=delete ;
    Singleton & operator=(const Singleton &rhs)=delete ;
    Singleton(int x,int y=0)
        :_ix(x)
         ,_iy(y)
    {
        cout<<"Singleton(int,int)"<<endl;
    }

    ~Singleton()
    {
        cout<<"~Singleton()"<<endl;
    }
    
private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
};

//饱汉式（懒汉式） —— 懒加载
//单例对象要使用的时候才创建出来，缺点是无法保证多线程安全
/* Singleton * Singleton::_pInstance = nullptr; */

//饿汉式
//一开始就将单例对象创建出来，即使程序中不使用这个单例对象
//能够保证多线程安全
//因为这一次的getInstance一定会是第一次的调用
Singleton * Singleton::_pInstance = Singleton::getInstance();

void test0(){
    Singleton::getInstance()->init(7,8);
    Singleton::getInstance()->print();
    /* Singleton::destroy(); */
}


int main(void){
    test0();
    return 0;
}
