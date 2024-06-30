#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Computer
{
public:
    Computer(int price,const char*brand)
    :_price(price)
     ,_brand(new char[strlen(brand)+1]())
    {
        strcpy(_brand,brand);
        cout<<"Computer"<<endl;
    }  
    
    ~Computer(){
        cout<<"~Computer()"<<endl;
        if(_brand){
            delete []_brand;
            _brand=nullptr;
        }
    }

       void print(){
        cout<<"price:"<<_price<<endl;
        cout<<"brand:"<<_brand<<endl;
    }

private:
    void*operator new(size_t sz){
        cout<<"operator new"<<endl;
        void *ret=malloc(sz);
        return ret;
    }

    void operator delete(void *pointer){
        cout<<"operator delete"<<endl;
        free(pointer);
    }

   

    int _price;
    char* _brand;
};

int main()
{
    Computer com(10000,"联想");
    com.print();

    return 0;
}

