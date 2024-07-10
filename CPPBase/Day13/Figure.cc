#include <iostream>
#include <cmath>

using namespace std;

// 抽象类Figure
class Figure {
public:
    virtual string getName() const = 0;
    virtual double getArea() const = 0;
    virtual ~Figure() {}
};

// 矩形类Rectangle
class Rectangle : public Figure {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    string getName() const override {
        return "Rectangle";
    }
    
    double getArea() const override {
        return width * height;
    }
    
private:
    double width;
    double height;
};

// 圆形类Circle
class Circle : public Figure {
public:
    Circle(double r) : radius(r) {}
    
    string getName() const override {
        return "Circle";
    }
    
    double getArea() const override {
        return M_PI * radius * radius;
    }
    
private:
    double radius;
};

// 三角形类Triangle
class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) : side1(a), side2(b), side3(c) {}
    
    string getName() const override {
        return "Triangle";
    }
    
    double getArea() const override {
        // 使用海伦公式计算面积
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
private:
    double side1;
    double side2;
    double side3;
};

// 显示图形名称和面积的函数
void display(Figure & fig) {
    cout << fig.getName() 
         << "的面积是:" 
         << fig.getArea() << endl ;
}

// 测试函数
void test() {
    Rectangle r(10, 20);
    Circle c(15);
    Triangle t(3, 4, 5);
    display(r);
    display(c);
    display(t);
}

// 主函数
int main() {
    test();
    return 0;
}

