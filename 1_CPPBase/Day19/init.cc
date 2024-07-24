#include <iostream>
#include<vector>
#include<list>
#include<deque>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

int main()
{   
    vector<int> nums{1,2,3,4};
    for(auto &num:nums)
    {
        cout<<num<<" ";
    }

    cout<<endl;

    vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(3);

    for(auto &num:nums2)
    {
        cout<<num<<" ";
    }
    
    cout<<endl;

    cout<<"queue:";
    deque<int> list1{5,2,3,4};
    deque<int>::iterator it=list1.begin();
    while(it!=list1.end())
    {
        cout<<*it<<" ";
        ++it;
    }

    cout<<endl;
    return 0;
}

