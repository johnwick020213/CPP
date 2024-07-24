#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

class Point
{
public:
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
    }

    void print(){
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test1(){
    unique_ptr<Point> up(new Point(1,2));
    up->print();
    (*up).print();

    unique_ptr<Point> up2(new Point(4,7));
    unique_ptr<Point> up3(new Point(5,9));

    vector<unique_ptr<Point>> vec;

    vec.push_back(unique_ptr<Point>(new Point(8,5)));
    vec[0]->print();

    vec.push_back(std::move(up));
    vec.push_back(std::move(up2));
    vec.push_back(std::move(up3));
    vec[1]->print();
    vec[2]->print();
    vec[3]->print();
}

int main(void){
    test1();
    return 0;
}

