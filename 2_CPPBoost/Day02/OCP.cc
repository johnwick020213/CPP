#include <iostream>

using namespace::std;

class Figure
{
public:
    virtual void display() const=0;
    virtual double getArea() const=0;
};

class Rectangle
:public Figure
{
public:
    Rectangle(double length1,double width1)
        :_length(length1)
         ,_width(width1)
    {
        cout<<"Rectangle()"<<endl;
    }

    ~Rectangle()
    {
        cout<<"~Rectangle()"<<endl;
    }

    void display() const  override
    {
        cout<<"Rectangle";
    }

    double getArea() const override
    {
        return _length*_width/2;
    }
private:
    double _length;
    double _width;
};

class Circle
:public Figure
{
public:
    Circle(double radius=0)
        :_radius(radius)
    {
        cout<<"Circle()"<<endl;
    }

    void display() const override
    {
        cout<<"Circle";
    }

    double getArea() const override
    {
        return 3.14*_radius*_radius;
    }

    ~Circle()
    {
        cout<<"~Circle()"<<endl;
    }

private:
    double _radius;
};

void func(Figure* fig)
{
    fig->display();
    cout<<"的面积是："<<fig->getArea()<<endl;
}

int main()
{
    Rectangle rec(10,5);
    Circle cir(10);
    
    func(&rec);
    func(&cir);
    return 0;
}

