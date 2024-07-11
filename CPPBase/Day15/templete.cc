#include <iostream>
#include<set>

using std::cout;
using std::endl;
using std::set;
using std::ostream;

template<class T>
T add(T t1,T t2){
    return t1+t2;
}

set<int>operator+(const set<int>& lhs,const set<int>& rhs)
{
    set<int> result;
    set<int>::const_iterator it1=lhs.begin();
    set<int>::const_iterator it2=rhs.begin();

    while(it1!=lhs.end()&&it2!=rhs.end())
    {
        result.insert(*it1+*it2);
        ++it1;
        ++it2;
    }

    while(it1!=lhs.end())
    {
        result.insert(*it1);
        ++it1;
    }

    while(it2!=rhs.end())
    {
        result.insert(*it2);
        ++it2;
    }

    return result;
}

ostream& operator<<(ostream& os,const set<int>&nums)
{
    os<<"{";
    for(const int&num:nums)
    {
        os<<num<<" ";
    }
    os<<"}"<<endl;
    return os;
}

int main()
{
    int a=1;
    int b=2;
    double c=9.9;
    double d=4.4;
    set<int>nums={1,2};
    set<int>nums2={3,4};

    
    cout<<add(a,b)<<endl;
    cout<<add(c,d)<<endl;
    cout<<add(nums,nums2)<<endl;
    return 0;
}

