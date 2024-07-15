#include <iostream>
/* 题目： */
/* 请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。 */
/* 例如把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。 */

#include<string>
#include<bitset>

using std::cin;
using std::cout;
using std::endl;
using std::bitset;

void test1()   
{
    int num,num2;
    cout<<"输入一个数字："<<endl;
    cin>>num2;

    num=num2;

    static int count=0;
    while(num!=0)
    {
        if(num%2)
        {
            count++;
        }
        num=num>>1;

    }
    bitset<32> binary_number(num2);
    cout<<"二进制数："<<binary_number.to_string()<<endl;

    cout<<"1的个数："<<count<<endl;

}

void test2()
{
    cout<<"输入一个数字："<<endl;
    int num;
    cin>>num;
    int count = __builtin_popcount(num);
    cout<<"1的个数是："<<count<<endl;
}

int main()
{
    test2();
    return 0;
}

