#include <iostream>

using std::cout;
using std::endl;

class Point{
public:
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
    int _ix;
    int _iy;
};



int main()
{
    Point p(1,1);
    p.print();
    return 0;
}

