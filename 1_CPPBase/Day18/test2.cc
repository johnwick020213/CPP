/* 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。 */
/* 例如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。 */
/* 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。 */
#include <iostream>
#include<map>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::sort;

//时间：O(n)空间O(n)
void test1()
{
    vector<int>numbers={1,2,3,2,2,2,5,4,2};

    map<int,int>countMap;

    for(const auto&number:numbers)
    {
        ++countMap[number];
        if(countMap[number]>4)
        {
            cout<<number<<endl;
            return;
        }
    }
}

//时间O(nlogn)空间O(1)
void test2()
{
    vector<int>nums={1,2,3,2,2,2,5,4,2};
    // 对数组进行排序
    sort(nums.begin(), nums.end());
    // 返回排序后数组的中间元素
    cout<<nums[nums.size() / 2]<<endl;
}

//时间O(n)空间O(1)
void test3()
{
    int candidate=0;
    int count=0;
    vector<int>nums={1,2,3,2,2,2,5,4,2};

    //第一遍遍历，找出候选者
    for(int num:nums)
    {
        if(count==0)
        {
            candidate=num;
            count=1;
        }
        else if(candidate==num)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    //第二遍遍历，确认候选人是否确实是主要元素
    count=0;
    for(int num:nums)
    {
        if(num==candidate)
        {
            count++;
        }
    }

    if(count>nums.size()/2)
    {
        cout<<candidate<<endl;
    }
    else
    {
        cout<<"没有这样的元素"<<endl;
    }
}

int main()
{

    test3();
    return 0;
}

