#include <iostream>
using std::cout;
using std::endl;

class Singlenton
{
    class AutoRelease
    {
    public:
        AutoRelease()
        {
            cout<<"AutoRelease()"<<endl;
        }

        ~AutoRelease()
        {
            cout<<"~AutoRelease()"<<endl;
            if(_pInstance)
            {
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };

    public:
    static Singlenton *getInstance()
    {
        if(nullptr==_pInstance)
        {
            _pInstance=new Singlenton(1,2);
        }
        return _pInstance;
    }

    void init(int x,int y)
    {
        _ix=x;
        _iy=y;
    }

    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
            _pInstance =nullptr;
            cout<<">>delete heap"<<endl;
        }
    }

    void print() const
    {
        cout<<"("<<this->_ix
            <<","<<this->_iy
            <<")"<<endl;
    }

    private:
    Singlenton(const Singlenton &rhs)=delete;
    Singlenton &operator=(const Singlenton & rhs)=delete ;
    Singlenton(int x,int y=0)
        :_ix(x)
         ,_iy(y)
    {
        cout<<"Singleton(int,int)"<<endl;
    }

    ~Singlenton()
    {
        cout<<"~Singleton()"<<endl;
    }
private:
    int _ix;
    int _iy;
    static Singlenton * _pInstance;
    static AutoRelease _ar;
};

Singlenton * Singlenton::_pInstance = nullptr;
Singlenton::AutoRelease Singlenton::_ar;
void test0(){
    Singlenton::getInstance()->init(7,8);
    Singlenton::getInstance()->print();
    /* Singleton::destroy(); */    
}


int main(void){
    test0();
    return 0;
}
