#include <iostream>
using std::cout;
using std::endl;

template<class T>
T add(T arg)
{
    return arg;
}


template<class T,class ...Args>
T add(T first,Args ...args)
{
    return first+add(args...);
}


int main()
{
    cout<<add(1,2,3,4)<<endl;
    cout<<add(1.2,1.3,1.4,1.5)<<endl;
    return 0;
}

