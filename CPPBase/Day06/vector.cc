#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<vector<int>> vec;
    vec.push_back(vector<int>{1,2,3});
    vec.push_back(vector<int>{4,5,6});
    vec.push_back(vector<int>{7,8,9});
 
    for(size_t i=0;i<vec.size();++i)
    {
        cout<<"Vector:"<<endl;
        for(size_t j=0;j<vec[i].size();++j)
        {
            cout<<"第"<<i+1<<"行第"<<j+1<<"个元素："<<vec[i][j]<<endl;
            cout<<" (地址："<<&vec[i][j]<<")"<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}

