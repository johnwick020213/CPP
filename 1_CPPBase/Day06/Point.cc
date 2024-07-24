#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

class Point{
public:
    Point()
        :_ix(3)
         ,_iy(4)
    {
        cout<<"Point()"<<endl;
    }
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
    vector<Point> point(10);
    for(auto & ch : point)
    {
        ch.print();
    }
    Point p(1,1);
    p.print();
    return 0;
}

