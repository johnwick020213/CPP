#include <iostream>
#include<string>
using std:cout;
using std:endl;
using std:string;

class Point
{
public:
    Point(float x,float y);
private:
    float _ix;
    float _iy;
};

class Line
{
public:
    Line(Point a,Point b);

    float getLenth();
private:
    Point _a;
    Point _b;
};

class Triangle
:public Line
{
public:
    Triangle(Point a,Point b,float height,string color);

    friend
        float circumference();
    friend
        float areas();
private:
    float _height;
    string _color;
};

Point::Point(float x,float y):_ix(x),_iy(y){}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

