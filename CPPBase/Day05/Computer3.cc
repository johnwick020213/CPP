#include <iostream>
#include<cstring>
using std::cout;
using std::endl;

class Computer
{
    public:
        static Computer*getInstance()
        {
            if(nullptr==_pInstance)
            {
                _pInstance=new Computer(1,"null");
            }
            return _pInstance;
        }

        void init(int price,const char*brand)
        {
            _price=price;
            strcpy(_brand,brand);
        }

        static void destroy()
        {
            if(_pInstance)
            {
                delete _pInstance;
                _pInstance=nullptr;
                cout<<">>delete heap"<<endl;
            }
        }

        void print() const
        {
             cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
        }

    private:

        Computer()
        int _price;
        char *_brand;
        static Computer * _pInstance;
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

