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
             cout << "(" << this->_price
            << "," << this->_brand
            << ")" << endl;
        }

    private:
        Computer(const Computer & rhs)=delete;
        Computer & operator=(const Computer & rhs)=delete;

        Computer()=default;
        Computer(int price,const char*brand)
            :_price(price)
             ,_brand(new char[strlen(brand)+1]())
        {
            strcpy(_brand,brand);
            cout<<"Computer(int,int)"<<endl;
        }

        ~Computer()
        {
            cout<<"~Computer()"<<endl;
        }
        int _price;
        char *_brand;
        static Computer * _pInstance;
};

Computer *Computer::_pInstance=nullptr;

int main()
{
    Computer::getInstance()->print();
    Computer::getInstance()->init(10000,"huawei");
    Computer::getInstance()->print();
    Computer::destroy();
    Computer::getInstance()->print();
    Computer::destroy();
    Computer::destroy();
    return 0;
}

