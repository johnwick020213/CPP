#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    static Point * getInstance(){
        if(nullptr==_pInstance){
            _pInstance=new Point(1,2);
        }
        return _pInstance;
    }

    void init(int x,int y){
        _ix=x;
        _iy=y;
    }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance =nullptr;
            cout<<">>delete heap"<<endl;
        }
    }

    void print() const{
        cout<<"("<<this->_ix
            <<","<<this->_iy
            <<")"<<endl;
    }
private:
   Point(const Point &rhs)=delete;
   Point &operator=(const Point &rhs)=delete;

   Point()=default;
    
    Point(int x,int y=0)
        :_ix(x)
         ,_iy(y)
    {
        cout<<"Point(int,int)"<<endl;
    }

    ~Point(){
        cout<<"~Point()"<<endl;
    }

    int _ix;
    int _iy;
    static Point*_pInstance;
};

Point * Point::_pInstance = nullptr;

int main()
{
    
    Point::getInstance()->print();
    Point::getInstance()->init(7,8);
    Point::getInstance()->print();
    Point::getInstance()->init(29,81);
    Point::getInstance()->print();
    Point::destroy();
    Point::destroy();
    Point::destroy();
    Point::getInstance()->print();
    Point::destroy(); 
    return 0;
}

