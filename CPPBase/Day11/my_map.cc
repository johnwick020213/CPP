#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <map>
using std::cout;
using std::endl;
using std::set;
using std::map;
using std::pair;
using std::string;
using std::make_pair;



void test0()
{ 
    map<int,string> city{
        {1,"beijin"},
        {2,"shanghai"},
        {3,"wuhan"},
        pair<int,string>(5,"suzhou"),
        pair<int,string>(6,"taiyuan"),
        make_pair(7,"taiwan")
    };

    for(auto & ch:city)
    {
        cout<<ch.first<<" "<<ch.second<<endl;
    }

    cout<<"_______________________"<<endl;

    map<int,string>::iterator it=city.begin();
    for(;it!=city.end();++it)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}

int main()
{
    test0();
    return 0;
}

