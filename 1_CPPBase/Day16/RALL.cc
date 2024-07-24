#include <iostream>
#include<cstring>
using std::cout;
using std::endl;

template<class T>
class RALL
{
public:
    RALL(T*data)
        :_data(data)
    {
        cout<<"RALL(T*)"<<endl;
    }

    ~RALL()
    {
        cout<<"~RALL()"<<endl;
        if(_data)
        {
            delete _data;
            _data=nullptr;
        }
    }

    T*operator->()
    {
        return _data;
    }

    T&operator*()
    {
        return *_data;
    }

    T*get()const
    {
        return _data;
    }


    void set(T*data)
    {
        if(_data)
        {
            delete _data;
            _data=nullptr;
        }
        _data=data;
    }

    RALL(const RALL & rhs) = delete;
    RALL& operator=(const RALL & rhs) = delete;

private:
    T* _data;
};

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

    void*operator new(size_t sz){
        cout<<"operator new"<<endl;
        void *ret=malloc(sz);
        return ret;
    }

    void operator delete(void *pointer){
        cout<<"operator delete"<<endl;
        free(pointer);
    }

    void print(){
        cout<<"price:"<<_price<<endl;
        cout<<"brand:"<<_brand<<endl;
    }

    void destroy(){
        delete this;
    }

    ~Computer(){
        cout<<"~Computer()"<<endl;
        if(_brand){
            delete []_brand;
            _brand=nullptr;
        }
    }
private:
    int _price;
    char* _brand;
};

int main()
{
    Computer * pt = new Computer(100, "huawei");
	//智能指针的雏形
	RALL<Computer> rall(pt);
	rall->print();
	(*rall).print();
    return 0;
}

