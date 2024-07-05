#include"Line.hh"
#include <iostream>
using std::cout;
using std::endl;

class Line::LineImpl
{
    class Point
    {
    public:
        Point(int x=0,int y=0)
            :_ix(x)
             ,_iy(y)
        {
            cout<<"Point(int,int)"<<endl;
        }

        ~Point()
        {
            cout<<"~Point()"<<endl;
        }

        void print() const
        {
            cout<<"("<<_ix
                <<","<<_iy
                <<")"<<endl;
        }

    private:
        int _ix;
        int _iy;


    };

public:
    LineImpl(int x1,int y1,int x2,int y2)
        :_pt1(x1,y1)
         ,_pt2(x2,y2)
    {
        cout<<"LineImpl(int*4)"<<endl;
    }

    ~LineImpl()
    {
        cout<<"~LineImpl()"<<endl;
    }

    void printLine() const
    {
        _pt1.print();
        cout<<"----------->";
        _pt2.print();
        cout<<endl;
    }
private:
    Point _pt1;
    Point _pt2;
};

Line::Line(int x1,int y1,int x2,int y2)
    :_pimpl(new LineImpl(x1,y1,x2,y2))
{
    cout<<"Line(int *4)"<<endl;
}

Line::~Line()
{
    cout<<"~Line()"<<endl;
    if(_pimpl)
    {
        delete _pimpl;
        _pimpl=nullptr;
    }
}

void Line::printLine() const
{
    _pimpl->printLine();
}


