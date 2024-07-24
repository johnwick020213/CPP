#include <iostream>
using std::cout;
using std::endl;
class Base{
    int x;
public:
    Base(const int y)
        :x(y)
    {
        ;
    }
    friend
        int operator+(const Base &lhs,const Base  &rhs);
};

int operator+(const Base&lhs,const Base &rhs)
{
    return Base(rhs.x-lhs.x).x;
}

int main()
{
    int i=2;
    int j=7;

    Base x(i);
    Base y(j);
    cout<<(x+y==j-i)<<endl;
    return 0;
}

