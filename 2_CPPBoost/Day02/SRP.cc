#include <iostream>

class Rectangle
{
public:
    Rectangle();
    double area();
private:
    int _high;
    int _line;
};

class RectangleGUI
:public Rectangle
{
public:
    void draw();
};


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

