
#include <iostream>

using std::cout;
using std::endl;

class Point{
public:
    Point(){}
    Point(int x,int y)
        :_ix(x),_iy(y)
    {
        cout<<"Point(int,int)"<<endl;

    }

    void print(){
        cout<<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

private:
    int _ix=2;
    int _iy=2;
};



int main()
{
    //Point p(1,1);
    //p.print();
    Point p;
    Point();
    p.print();
    return 0;
}

