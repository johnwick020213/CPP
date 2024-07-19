#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::back_inserter;
using std::back_insert_iterator;
using std::front_inserter;;
using std::front_insert_iterator;
using std::inserter;
using std::insert_iterator;
using std::vector;
using std::list;
using std::set;
using std::copy;

void test()
{
    vector<int>vec={1,3,7,5};
    list<int>lstNum={11,44,66,22};

    //将list中的元素插入到vector尾部
    copy(lstNum.begin(),lstNum.end(),back_inserter<vector<int>>(vec));
    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    

    //将vector中的元素插入到list头部呢
    copy(vec.begin(),vec.end(),front_inserter<list<int>>(lstNum));
    copy(lstNum.begin(),lstNum.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;

    set<int>setNum={1,7,44,12,34,56};

    auto it=setNum.begin();
    copy(vec.begin(),vec.end(),inserter(setNum,it));
    copy(setNum.begin(),setNum.end(),std::ostream_iterator<int>(cout," "));
    cout<<endl;




}

int main()
{
    test();
    return 0;
}
